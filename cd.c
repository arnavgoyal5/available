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
