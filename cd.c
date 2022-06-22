PROGRAM 1

Design a lex code to count the number of lines, spaces, tab space, meta character and rest of characters in a given input pattern.

%{
#include<stdio.h>
int lines=0, chars=0, tabs=0, blank=0;
%}

%%
[\n] {lines++;}
[\t] {tabs++;}
[ ]  {blank++;}
.    {chars++;}
%%

intyywrap() {return 1;}

intmain()
{
yylex();
printf("No. of Lines: %d",lines);
printf("\nNo. of Chars: %d",chars);
printf("\nNo. of Tabs: %d",tabs);
printf("\nNo. of Blank: %d\n",blank);
return 0;
}





PROGRAM 2

Design a lex code to identify and print valid identifiers of C/C++ in a given input file.

%{
#include<stdio.h>
%}

%%
([a-zA-Z][0-9])+|[a-zA-Z]* {printf("Identifier\n");}   
^[0-9]+ {printf("Not a Identifier\n");}
.|\n; 
%%
intyywrap()					
{
return 1;
}

int main(void)
{
yylex();						
return 0;
}






PROGRAM 3

Design a lex code to identify and print integer and float value in given input pattern.

%{
#include<stdio.h>
%}
DIGIT [0-9]
%%
{DIGIT}* {printf("\n%s: Integer",yytext);}
{DIGIT}*?\.{DIGIT}+ {printf("\n%s: Float",yytext);}
%%
intyywrap() {return 1;}
intmain()
{
yylex();
return 0;
}





PROGRAM 4

Design a lex code for tokenising i.e. identify and print operators, separators, keywords, identifiers, in the following C-fragment


%{
#include<stdio.h>
%}

%%
auto|double|int|struct|break|else|long|switch|case|enum|register|typedef|char|extern|return|union|continue|for|signed|void|do|if|static|while|default|goto|sizeof|volatile|const|float|short     {ECHO;printf("\nKEYWORD\n");} 						
[{};,()]   {ECHO; printf("\tSEPERATOR\t");}						
[+-/=*%]   {ECHO; printf("\tOPERATOR\t");}						
([a-zA-Z][0-9])+|[a-zA-Z]* {ECHO; printf("\tIdentifier\t");}    
.|\n ; 												
%%

intyywrap()								
{
return 1;
}
int main(void)
{
yylex();
return 0;
}



 
PROGRAM 5

Design a lex code to count and print the number of total characters, words, white spaces in given ‘Input.txt’ file.

%{
 #include<stdio.h>
 int lines=0, words=0, spaces=0, total=0;
%}

%%
\n {lines++,words++,total++;}
[\t''] {words++,total++;}
[" "] {spaces++,total++;}
%%

intyywrap(){}
int main(intargc, char *argv[])
{
extern FILE *yyin;
yyin=fopen("Input.txt", "r");
yylex();
printf("\nlines: %d \nspaces: %d\ntotal: %d\nwords: %d\n", lines, spaces, total, words);
return 0;
}   


 


PROGRAM 6
Design a lex code to remove the extra spaces and empty line write it in “store.txt” file.
%{
 #include<stdio.h>
%}

space [\t]
emptyline [\n]

%%
{space}+ printf(" ");
{emptyline}+ printf("\n");
.printf("%s\n",yytext);
%%


intyywrap(){}
int main(intargc, char *argv[])
{
extern FILE *yyout;
yyout=fopen("store.txt", "w");
yylex();
return 0;
}   




PROGRAM 7
Design the lex code to remove the comments from any  C-program given at run time and store into “comment.txt”.
%{
#include<stdio.h>
%}
%%
\/\/(.*) {};					
\/\*(.*\n)*.*\*\/  {};			
%%
intyywrap()
{
return 1;
}

intmain()
{
yyin=fopen("input7.c","r");
yyout=fopen("out7.c","w");
/*call the yylexfunction.*/
yylex();
return 0;
}






PROGRAM 8
Design a lex code to extract all the HTML tags in the given HTML file at run time and store it into text file “Tags.txt” given at run time.
%{
#include<stdio.h>
%}

%%
\<[^>]*\>fprintf(yyout,"%s\n",yytext);
.|\n; 
%%

intyywrap()
{
return 1;
}

intmain()
{
yyin=fopen("input8.html","r");
yyout=fopen("output8.txt","w");
yylex();
return 0;
}






PROGRAM 9
Design a DFA in LEX Code which accepts string containing even number of ‘a’ and even number of ‘b’ over input alphabet {a, b}.
%{
#include<stdio.h>
%}
reg (aa|bb)*((ab|ba)(aa|bb)*(ab|ba)(aa|bb)*)*
%%
{reg} printf(%s is accepted",yytext);
.* printf("%s is not accepted",yytext);
%%
int yywrap(){}
int main(int argc, char *argv[]){
extern FILE *yyin;
yyin= fopen("Input.txt","r");
yylex();
return 0;
}











OUTPUT

 

 





PROGRAM 10
Design a DFA in LEX Code which accepts string containing third last element ‘a’ over input alphabet {a, b}.
%{
#include<stdio.h>
 %}
reg (a*b*)*a(aa|bb|ab|ba)
%%
{reg} printf("%s is accepted", yytext);
.* printf("%s is not accepted", yytext);
%%
int yywrap(){return 1;}
int main()
{
extern FILE *yyin;
yyin = fopen("Input2.txt","r");
yylex();
return 0;
}










OUTPUT

 
 


PROGRAM 11
Design a DFA in LEX Code to Identify and print Integer & Float Constants and Identifier.
%{
#include<stdio.h>
%}
%%
[+-]?[0-9]"."[0-9]+ printf("%s is Float Constants",yytext);
[+-]?[0-9]+ printf("%s is Integer Constants",yytext);
[a-zA-Z]+|[a-zA-Z]+[0-9]+ printf("%s is Identifiers",yytext);
.* printf("%s is Neither Ineger, Float constants nor identifiers",yytext);
%%
int yywrap(){}
int main()
{
extern FILE *yyin;
yyin = fopen("Input3.txt","r");
yylex();
return 0;
}










OUTPUT

 
 




PROGRAM 12
Design YACC/LEX code to recognize valid arithmetic expression with operators +, -, * and /.

%{
#include <stdio.h>
#include <string.h>
int operators_count = 0, operands_count = 0, valid = 1, top = -1, l = 0, j = 0;
char operands[10][10], operators[10][10], stack[100];
%}

%%
"(" {top++; stack[top] = '(';}
"{" {top++; stack[top] = '{';}
"[" {top++; stack[top] = '[';}
")" {if (stack[top] != '('){
        valid = 0;
    }else if(operands_count>0 && (operands_count-operators_count)!=1){
        valid=0;
    }else{
        top--; operands_count=1; operators_count=0;
    }
}
"}" {
    if(stack[top] != '{') { valid = 0;
    }else if(operands_count>0 && (operands_count-operators_count)!=1){
        valid=0;
    }else{
        top--;
        operands_count=1;
        operators_count=0;
    }
}
"]" {if (stack[top] != '[') {
        valid = 0;
    }else if(operands_count>0 && (operands_count-operators_count)!=1){
        valid=0;
    }else{
        top--;
        operands_count=1;
        operators_count=0;
    }
}
"+"|"-"|"*"|"/" {
    operators_count++;
    strcpy(operators[l], yytext);
    l++;
}
[0-9]+|[a-zA-Z][a-zA-Z0-9_]* {
    operands_count++;
    strcpy(operands[j], yytext);
    j++;
}
%%

int yywrap(){return 1;}

int main()
{
    int k;
    printf("Enter the arithmetic expression: ");
    yylex();
    if (valid == 1 && top == -1) {
printf("\nValid Expression\n");
    }else
        printf("\nInvalid Expression\n");
    return 0;
}


OUTPUT










PROGRAM 13
Design YACC/LEX code to evaluate arithmetic expression involving operators +, -, * and / without operator precedence grammar & with operator precedence grammar.

Without Operator Precedence Grammar
Lex Program:
%{
#include<stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%
[0-9]+ {
yylval=atoi(yytext);
return NUMBER;
}
[\t] ;
[\n] return 0;
. return yytext[0];
%%
int yywrap()
{
    return 1;
}






Yacc Program:
%{
    #include<stdio.h>
    int flag=0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%

ArithmeticExpression: E{
printf("\nResult=%d\n",$$);
return 0;
};
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'%'E {$$=$1%$3;}
|'('E')' {$$=$2;}
| NUMBER {$$=$1;}
;
%%
void main()
{
    printf("\nEnter Any Arithmetic Expression which can have operations Addition, Subtraction, Multiplication, Divison, Modulus and Round brackets:\n");
    yyparse();
    if(flag==0)
        printf("\nEntered arithmetic expression is Valid\n\n");
}
void yyerror()
{
    printf("\nEntered arithmetic expression is Invalid\n\n");
    flag=1;
}
OUTPUT

With Operator Precedence Grammar
Lex Program:
%{
	#include<stdio.h>
	#include "y.tab.h"
	extern int yylval;
%}

%%
[0-9]+ {
yylval=atoi(yytext);
return NUMBER;
}
[\t] ;
[\n] return 0;
. return yytext[0];
%%

int yywrap()
{
	return 1;
}

Yacc Program:
%{
#include<stdio.h>
int flag=0;%}
%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%
ArithmeticExpression: E{
printf("\nResult=%d\n",$$);
return 0;
}
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'%'E {$$=$1%$3;}
|'('E')' {$$=$2;}
| NUMBER {$$=$1;}
;
%%
void main()
{
printf("\nEnter Any Arithmetic Expression which can have operations
Addition, Subtraction, Multiplication, Divison, Modulus and Round
brackets:\n");
yyparse();if(flag==0)
printf("\nEntered arithmetic expression is Valid\n\n");
}
void yyerror()
{
printf("\nEntered arithmetic expression is Invalid\n\n");
flag=1;
}







OUTPUT
















PROGRAM 14
Design YACC/LEX code that translates infix expression to postfix expression.

Lex Program:
%{
    #include"y.tab.h"
    extern int yylval;
%}

%%
[0-9]+ {yylval=atoi(yytext); return NUM;}
\n return 0;
. return *yytext;
%%

int yywrap(){
    return 1;
}

Yacc Program:
%{
    #include<stdio.h>
%}

%token NUM
%left '+' '-'
%left '*' '/'
%right NEGATIVE

%%
S: E {printf("\n");} ;E: E '+' E {printf("+");}
| E '*' E {printf("*");}
| E '-' E {printf("-");}
| E '/' E {printf("/");}
| '(' E ')'
| '-' E %prec NEGATIVE {printf("-");}
| NUM
{printf("%d", yylval);}
;
%%

int main(){
    yyparse();
}
int yyerror (char *msg) {
    return printf ("error YACC: %s\n", msg);
}





OUTPUT





PROGRAM 15
Design Desk Calculator using YACC/LEX code.

Lex Program:
%{
    #include<stdio.h>
    #include "y.tab.h"
    extern int yylval;
%}

%%
[0-9]+ {
yylval=atoi(yytext);
return NUMBER;
}
[\t] ;
[\n] return 0;
. return yytext[0];
%%

int yywrap()
{
    return 1;
}

Yacc Program:
%{
    #include<stdio.h>
    int flag=0;
%}

%token NUMBER
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'
%%

ArithmeticExpression: E{
printf("\nResult=%d\n",$$);
return 0;
};
E:E'+'E {$$=$1+$3;}
|E'-'E {$$=$1-$3;}
|E'*'E {$$=$1*$3;}
|E'/'E {$$=$1/$3;}
|E'%'E {$$=$1%$3;}
|'('E')' {$$=$2;}
| NUMBER {$$=$1;}
;
%%
void main()
{
    printf("\nEnter Any Arithmetic Expression which can have operations Addition, Subtraction, Multiplication, Divison, Modulus and Round brackets:\n");
    yyparse();
    if(flag==0)
        printf("\nEntered arithmetic expression is Valid\n\n");
}
void yyerror()
{
    printf("\nEntered arithmetic expression is Invalid\n\n");
    flag=1;
}
OUTPUT

