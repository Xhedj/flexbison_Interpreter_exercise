test: lex.yy.c test.tab.c
	gcc -g lex.yy.c test.tab.c -o test

lex.yy.c: test.tab.c test.l
	flex test.l

test.tab.c: test.y
	bison -d test.y

clean: 
	rm -rf lex.yy.c calc.tab.c calc.tab.h calc calc.dSYM