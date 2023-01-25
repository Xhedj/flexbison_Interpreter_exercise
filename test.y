%{
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define YYDEBUG 1

extern int yylex();
int yyerror(const char *s);

const char INT_TYPE = 1;
const char FLOAT_TYPE = 2;
const char STRING_TYPE = 3;

struct variable summation(struct variable n1, struct variable n2);
struct variable subtraction(struct variable n1, struct variable n2);
struct variable multiplication(struct variable n1, struct variable n2);
struct variable division(struct variable n1, struct variable n2);
struct variable negativeNumb(struct variable);

bool greaterValue(struct variable, struct variable);
bool smallerValue(struct variable, struct variable);
bool equality(struct variable, struct variable);
bool inequality(struct variable, struct variable);
bool greaterEqual(struct variable, struct variable);
bool smallerEqual(struct variable, struct variable);

struct variable increment(struct variable);
struct variable decrement(struct variable);

void print_value(struct variable var);
void print_boolExpr(_Bool result);
char* varType(struct variable data);

struct symbolTable *head = (struct symbolTable *)0;
struct symbolTable *node = (struct symbolTable *)0;
struct symbolTable *symlook(char *str);
void setHead(struct symbolTable *node);
struct symbolTable *addNode(char *str, struct symbolTable *node);
const int max_symbols = 10;
int counter = 0;

%}
%code requires{
	struct variable{
    union{
        int intval;
        float floatval;
        char *strings;

    };
    char fromID;
    char type;
};

    struct symbolTable{
        char *id;
        char declared;
        char initialized;
        struct symbolTable *next;
        struct variable value;
    };
}

%union {
		char* name;
        char* varname;
        char* types;
		float floatv;
		int integerv;
        _Bool cond;
		struct variable variabile;
};

%token STRING 
%token INTEGERV
%token FLOATV

%token INTEGER
%token FLOAT
%token WORD

%token TYPE
%token BADGE

%token IF
%token FL
%token FOR
%token WHILE

%token OTHER

%token EXIT
%token SEMICOLON
%token EOL

%type <name> STRING
%type <integerv> INTEGERV
%type <floatv> FLOATV
%type <varname> BADGE
%type <cond> cond_expression

%type <variabile> expression


%type <variabile> stringa
%type <types> variabletype

%left '<' '>' '=' LESSEQUAL GREATEREQUAL NEGATION COMPARISON
%nonassoc  INC DEC
%left '(' ')'
%left '+' '-'
%left '*' '/'
%right MINUS
%start input
%%

input: line input | line ;

line	: expression SEMICOLON EOL { print_value($1); };
		| stringa SEMICOLON EOL { print_value($1); }
        | cond_expression SEMICOLON EOL { print_boolExpr($1); };
        | assign SEMICOLON EOL { ; };
        | variabletype BADGE SEMICOLON EOL {
            struct symbolTable *pointer = symlook($2);
            if(!pointer->initialized){
                pointer->initialized = 1;

                if($1 == "integer"){
                    pointer->value.type = INT_TYPE;
                    printf(" A variable of type integer has been declared with Identifier: '%s'\n",$2);
                }
                    

                else if($1 == "float"){
                    pointer->value.type = FLOAT_TYPE;
                    printf(" A variable of type float has been declared with Identifier: '%s'\n",$2);
                }
            } 
            else {
                printf("--ERROR--\nVariable '%s' already defined\n",$2);
            }
        }
        | WORD BADGE SEMICOLON EOL {
            struct symbolTable *pointer = symlook($2); 
            if(!pointer->initialized)
            {
                pointer->initialized = 1; 
                pointer->value.type = STRING_TYPE; 
                pointer->value.strings = "null";
                printf(" A variable string has been declared with Identifier: '%s'\n",$2);
            } else {
                printf("--ERROR--\nVariable '%s' already defined\n",$2);
            }
        }
        | WORD INTEGERV	{
            printf("--ERROR!!--\n Illegal variable declaration! A legal variable declaration must start with a letter and not an Integer \n");
            }
		| WORD FLOATV	{
            printf("--ERROR!!--\n Illegal variable declaration! A legal variable declaration must start with a letter and not a Float \n");
        } 
		| EXIT	{exit(0); }
		;

expression	: expression '*' expression {$$ = multiplication($1,$3); }
            | expression '+' expression {$$ = summation($1,$3); }
            | expression '-' expression {$$ = subtraction($1,$3); }
            | expression '/' expression {$$ = division($1,$3); }
            | expression INC {$$ = increment($1);}
            | expression DEC {$$ = decrement($1);}
            | '-' expression %prec MINUS {$$ = negativeNumb($2);}
            | '(' expression ')'		{$$ = $2;}
            |INTEGERV {{struct variable data; data.type = INT_TYPE; data.fromID=0; data.intval = $1; $$ = data; }}
 			|FLOATV {{struct variable data; data.type = FLOAT_TYPE; data.fromID=0; data.floatval = $1; $$ = data; }}
            ;

stringa	  : STRING		{struct variable data; data.type = STRING_TYPE; data.strings = ++$1; data.strings[strlen(data.strings)-1] = '\0'; $$ = data; }
        ;

cond_expression : expression '>' expression			{$$ = greaterValue($1,$3); }
                | expression '<' expression			{$$ = smallerValue($1,$3); }
                | expression COMPARISON expression	{$$ = equality($1,$3);}
                | expression NEGATION expression		{$$ = inequality($1,$3);}
                | expression GREATEREQUAL expression	{$$ = greaterEqual($1,$3);}
                | expression LESSEQUAL expression		{$$ = smallerEqual($1,$3);}
                ;


assign    :   variabletype BADGE '=' expression {
                    struct symbolTable *pointer = symlook($2);
                    if(pointer->initialized){
				        printf("--ERROR!!--\n Variable %s already defined \n",$2);
				    }
			        else {
                            if($1 == "float"){
                                if($4.type == INT_TYPE||$4.type == FLOAT_TYPE){
                                pointer->value.type = FLOAT_TYPE;
                                pointer->initialized=1;	
                                pointer->declared=1;
                                
                                if($4.type == INT_TYPE){
                                    pointer->value.floatval = $4.intval;
                                } else {
                                    pointer->value.floatval = $4.floatval;
                                }
                                printf(" Variable defined as: '%s' and",$2);
                                printf(" has value %f\n",pointer->value.floatval);

                        } else 
                            fprintf(stderr, "--ERROR!!--\n Cannot assign %s to FLOAT type \n",varType($4)); 

                        } else if($1 == "integer") {
							
						if(!($4.type == INT_TYPE))
							fprintf(stderr, "--ERROR!!--\n Cannot assign %s to INTEGER type \n",varType($4));
								
						else {
                                pointer->value.type = INT_TYPE;
                                pointer->initialized = 1;
                                pointer->declared=1;
                                pointer->value.intval=$4.intval;
                                printf(" Variable defined as '%s' and",$2);
                                printf(" has value %i\n",pointer->value.intval);
						    }
                        }  
                        else {
                        fprintf(stderr, "--ERROR!!--\n The type inserted: %s, is not recognized \n",$1);
                        }
                    }
                }

            |   variabletype BADGE '=' stringa{
                    struct symbolTable* pointer = symlook($2);
                    if(pointer->initialized){
                        printf("Variable already defined\n");
                        }
                    else{
                        fprintf(stderr, "--ERROR!!--\n Impossible to assign string to the type: %s \n",$1);
                        }
                }
            
            |   WORD BADGE '=' stringa{
                    struct symbolTable* pointer = symlook($2);
                    if(pointer->initialized){
                        printf("--ERROR!!--\n The variable: '%s', has been already defined \n",$2);
                    }			
                    else {
                        pointer->value.type = STRING_TYPE;
                        pointer->initialized=1;
                        pointer->declared=1;
                        pointer->value.strings=strdup($4.strings);
                        printf(" Variable defined as '%s' and",$2);
                        printf(" has value: %s \n", pointer->value.strings);
                        }
                }
            
            |   WORD BADGE '=' expression{
                    struct symbolTable* pointer = symlook($2); 
                    if(pointer->initialized){
                        printf("--ERROR!!--\n The variable: '%s', has been already defined \n",$2);
                    }else{
                        printf("--ERROR!!--\n Cannot assign an expression to a string!! \n");
                    }
                }
            
            |   BADGE '=' expression{
                    struct symbolTable* pointer1 = symlook($1);
                    if(pointer1->initialized){
                        char type1 = pointer1->value.type;
                        char type2 = $3.type; 
                        if (type2 == 0){
                                print_value($3);
                        }else{
                            if(type1 == 2){
                                if(type2 == 1){
                                    pointer1->value.floatval=$3.intval;
                                    pointer1->declared=1;
                                    printf(" Assigned integer value to float variable: '%d'\n",$3.intval);

                                } else if(type2 == 2){
                                    pointer1->value.floatval=$3.floatval;
                                    pointer1->declared=1;
                                    printf(" Assigned float value to float variable: '%f'\n",$3.floatval);
                                } else {
                                    fprintf(stderr, "--ERROR!!--\n Cannot assign: %s to %s type \n",varType($3),varType(pointer1->value));
                                    }
                            } else {
                                if(type1 == type2) {
                                    if(type1 == 1){
                                        pointer1->value.intval=$3.intval;
                                        printf(" Assigned integer value to integer variable: '%d'\n",$3.intval);
                                    } else {
                                    pointer1->value.strings=$3.strings;
                                    printf(" Assigned a string to a string variable: '%s'\n",$3.strings);
                                    }
                                    pointer1->declared=1;
                                } else {
                                    fprintf(stderr, "--ERROR!!--\n Cannot assign: %s to %s type\n",varType($3),varType(pointer1->value));}
                            }
                        }
                    } else {
                        printf("--ERROR!!--\n The variable '%s' is not defined\n",$1);
                    }
                }

            | BADGE '=' stringa {
                    struct symbolTable* pointer = symlook($1); 

					if(pointer->initialized){

                        if(pointer->value.type != STRING_TYPE){
                            fprintf(stderr, "--ERROR!!--\n A string cannot be assigned to type: %s \n",varType(pointer->value));
                        } else {
                            pointer->value.strings=strdup($3.strings);
                            printf(" Currently defined variable has ID: %s and", $1);
                            printf(" has value: %s \n", pointer->value.strings);
                            pointer->declared=1;
                        
                        }

					} else {printf("--ERROR!!--\n Variable '%s' is not defined \n",$1);}
                } 
            ;


variabletype    :   FLOAT	{$$ = "float";}
	            |   INTEGER	{$$ = "integer";}
	            ;




%%
// Sum of two variables
struct variable summation(struct variable n1, struct variable n2){
    struct variable result;

    if (n1.type == STRING_TYPE && n2.type == STRING_TYPE){
        result.strings = n1.strings;
        strcat(result.strings, n2.strings);
        result.type = STRING_TYPE;
    }
    else if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        result.intval = n1.intval + n2.intval;
        result.type = INT_TYPE;
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        result.floatval = n1.intval + n2.floatval;
        result.type = FLOAT_TYPE;
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        result.floatval = n1.floatval + n2.intval;
        result.type = FLOAT_TYPE;
    }
    else if (n1.type == FLOAT_TYPE && n2.type == FLOAT_TYPE){
        result.floatval = n1.floatval + n2.floatval;
        result.type = FLOAT_TYPE;
    }
    else{
        result.type = 9; // ERROR TYPE
    }

    return result;
}

// Subtraction between variables
struct variable subtraction(struct variable n1, struct variable n2){
    struct variable result;

    if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        result.intval = n1.intval - n2.intval;
        result.type = INT_TYPE;
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        result.floatval = n1.intval - n2.floatval;
        result.type = FLOAT_TYPE;
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        result.floatval = n1.floatval - n2.intval;
        result.type = FLOAT_TYPE;
    }
    else{
        result.floatval = n1.floatval - n2.floatval;
        result.type = FLOAT_TYPE;
    }

    return result;
}

// Multiplication of two variables
struct variable multiplication(struct variable n1, struct variable n2){

    struct variable result;

    if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        result.intval = n1.intval * n2.intval;
        result.type = INT_TYPE;
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        result.floatval = n1.intval * n2.floatval;
        result.type = FLOAT_TYPE;
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        result.floatval = n1.floatval * n2.intval;
        result.type = FLOAT_TYPE;
    }
    else{
        result.floatval = n1.floatval * n2.floatval;
        result.type = FLOAT_TYPE;
    }

    return result;
}

// Division of two variables
struct variable division(struct variable n1, struct variable n2){

    struct variable result;
    if(n2.floatval == 0.0 || n2.intval == 0){
        printf("cannot divide by 0");
        exit(0);
    }
    else if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        result.intval = n1.intval / n2.intval;
        result.type = INT_TYPE;
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        result.floatval = n1.intval / n2.floatval;
        result.type = FLOAT_TYPE;
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        result.floatval = n1.floatval / n2.intval;
        result.type = FLOAT_TYPE;
    }
    else{
        result.floatval = n1.floatval / n2.floatval;
        result.type = FLOAT_TYPE;
    }

    return result;
}

struct variable negativeNumb(struct variable n1){
    struct variable result;
    if (n1.type == INT_TYPE){
        result.type = INT_TYPE;
        result.intval = -n1.intval;
    }
    else{
        result.type = FLOAT_TYPE;
        result.floatval = -n1.floatval;
    }
    return result;
}


/* Function for printing the data value */
void print_value(struct variable var){
    if (var.type == INT_TYPE){
        printf("Integer Result: %i \n", var.intval);
    }
    else if (var.type == FLOAT_TYPE){
        printf("Float Result: %f \n", var.floatval);
    }
    else if (var.type == STRING_TYPE){
        printf("String: %s \n", var.strings);
    }
    else{
        printf("variable is not defined\n");
    }
}

char* varType(struct variable data){ // returns type of data

	char* type;

	switch(data.type) {
	
		case 1:
			type="int";
			break;
		case 2:
			type="float";
			break;
		case 3:
			type="string";
			break; 
		case 0:
			type="none";
			break;
	}
	
	return type;
}

_Bool equality(struct variable n1, struct variable n2){
    _Bool prov;
    if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        if (n1.intval == n2.intval){
            prov = true;
        }
    }
    else if (n1.type == FLOAT_TYPE && n2.type == FLOAT_TYPE){
        if (n1.floatval == n2.floatval){
            prov = true;
        }
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        if (n1.floatval == n2.intval){
            prov = true;
        }
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        if (n1.intval == n2.floatval){
            prov = true;
        }
    }
    else{
        prov = false;
    }
    return prov;
}

_Bool greaterValue(struct variable n1, struct variable n2){
    _Bool prov;
    if (n1.type == INT_TYPE && n2.type == INT_TYPE){
        if (n1.intval > n2.intval){
            prov = true;
        }
    }
    else if (n1.type == FLOAT_TYPE && n2.type == FLOAT_TYPE){
        if (n1.floatval > n2.floatval){
            prov = true;
        }
    }
    else if (n1.type == FLOAT_TYPE && n2.type == INT_TYPE){
        if (n1.floatval > n2.intval){
            prov = true;
        }
    }
    else if (n1.type == INT_TYPE && n2.type == FLOAT_TYPE){
        if (n1.intval > n2.floatval){
            prov = true;
        }
    }
    else{
        prov = false;
    }
    return prov;
}

_Bool inequality(struct variable n1, struct variable n2){
    return !equality(n1, n2);
}

_Bool smallerValue(struct variable n1, struct variable n2){
    return (!greaterValue(n1, n2) && !equality(n1, n2));
}

_Bool greaterEqual(struct variable n1, struct variable n2){
    return greaterValue(n1, n2) || equality(n1, n2);
}

_Bool smallerEqual(struct variable n1, struct variable n2){
    return smallerValue(n1, n2) || equality(n1, n2);
}

struct variable increment(struct variable n1){
    struct variable result;
    if (n1.type == INT_TYPE){
        result.type = INT_TYPE;
        result.intval = n1.intval + 1;
    }
    else{
        result.type = FLOAT_TYPE;
        result.floatval = n1.floatval + 1;
    }
    return result;
}

struct variable decrement(struct variable n1){
    struct variable result;
    if (n1.type == INT_TYPE){
        result.type = INT_TYPE;
        result.intval = n1.intval - 1;
    }
    else{
        result.type = FLOAT_TYPE;
        result.floatval = n1.floatval - 1;
    }
    return result;
}

void print_boolExpr(_Bool result){
    printf("Conditional result: %s\n", result ? "true" : "false");
}

struct symbolTable *addNode(char *str, struct symbolTable *iter){

    struct symbolTable *node = (struct symbolTable *)malloc(sizeof(struct symbolTable));
    node->id = strdup(str);
    node->next = NULL;

    iter->next = node;

    counter++;

    return node;
}

struct symbolTable *symlook(char *str){

    if (head == NULL) {
        head = (struct symbolTable *)malloc(sizeof(struct symbolTable));
        head->id = strdup(str);
        head->next = NULL;
        counter++;
        return head;
    }

    else {

        struct symbolTable *iter = (struct symbolTable *)malloc(sizeof(struct symbolTable));
        iter = head;

        while (iter->next != NULL){ // iterate over list
            /* strcmp checks if WHOLE string is equal starting from pointer to it*/

            if (iter->id && !strcmp(iter->id, str)){ /* return pointer */
                return iter;
            }
            iter = iter->next;
        }

        if (iter->id && !strcmp(iter->id, str)){ /* return pointer */
            return iter;
        }

        if (counter < max_symbols){ // if the variable was not found and there is still space in the ST
            struct symbolTable *added = addNode(str, iter);
            return added;
        }

	exit(1);

    }
}




int yyerror(const char *s)
{
	return fprintf (stderr, "%s\n", s);
	fputs (s, stderr);
	fputc ('\n', stderr);
	return 0;
}

int main()
{

    yyparse();
    return 0;
}
