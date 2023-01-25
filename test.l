
%{
#include <stdio.h>
#include <string.h>
#include "test.tab.h"
void showError();
%}

NUMBER      ([0-9])
SYMBOLS         [\+\-\*\(\)\<>&\|=\!\?\^\%\$\£\'\[\]\{\}\@\#\:\.\,\;\`\°\ç\§\/\\]

INTEGER     ({NUMBER}+)
FLOAT       ({INTEGER}\.{NUMBER}+)
BADGE       ([a-zA-Z])([0-9]|\_)*
ALPHA       \"([a-zA-Z0-9]*{SYMBOLS}*_*)*\"

%%

{INTEGER}       {yylval.integerv = atoi(yytext); return (INTEGERV);}
{FLOAT}         {yylval.floatv = atof(yytext); return (FLOATV);}
{ALPHA}			   {yylval.name = strdup(yytext); return (STRING);}
{BADGE}              {yylval.varname = strdup(yytext); return (BADGE);}

float		{return (FLOAT);}
int			{return (INTEGER);}
if          {return (IF);}
follows     {return (FL);}
string      {return (WORD);}
type        {return (TYPE);}
while       {return (WHILE);}
for         {return (FOR);}
";"         {return (SEMICOLON);}
"+"         {return('+');}
"-"         {return('-');}
"*"		    {return ('*');}
"/"		    {return ('/');}
"("		    {return ('(');}
")"		    {return (')');}
"{"		    {return ('{');}
"}"		    {return ('}');}
"<"		    {return ('<');}
">"		    {return ('>');}
"="         {return ('=');}
"=="	    {return COMPARISON;}
"!="	    {return NEGATION;}
"<="	    {return LESSEQUAL;}
">="	    {return GREATEREQUAL;}
"++"	    {return INC;}
"--"	    {return DEC;}
"\n"        {return EOL;}

[ \t\f\v\n] { ; }
quit		{return (EXIT);}
.      		{showError(); return(OTHER);}

%%


void showError(){
    printf("Other input error \n");
}
int yywrap(){
    return 1;
}
