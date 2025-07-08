%{
	#include <stdlib.h>
	int total_keys = 0, total_id = 0;
%}

%option noyywrap
%x MLC

keyword 				int|float|true|if|return|else
digit					[0-9]
rel_op					>=|<=|==|>|<
assign_op				\+=|-=|=

%%

\/\*					{ BEGIN(MLC); } /*start comment*/

<MLC>[^\/]+				{ if(yytext[yyleng-1] == '*'){
						yyless(yyleng-1); 
						printf("Inside comment: %s\n", yytext);}
					  else
						yymore(); }

<MLC>\*\/				{ BEGIN(INITIAL); }

{keyword}				{printf("Keyword: %s\n", yytext);
					total_keys++;}

[_a-zA-Z][_a-zA-Z0-9]*			{printf("Identifier: %s\n", yytext);
					total_id++;}

[-]?{digit}+				{printf("Integer Number: %s\n", yytext);}

[-]?{digit}*[.]{digit}+			{printf("Float Number: %s\n", yytext);}

{rel_op}				{printf("Relational Operator: %s\n", yytext);}

{assign_op}				{printf("Assignment Operator: %s\n", yytext);}

[();]					{printf("Delimiter: %s\n", yytext);}

[ \n\t]+				;

%%

int main(){
	FILE* fp = fopen("input.txt", "r");
	yyin = fp;
	yylex();
	printf("Total Keywords: %d\n", total_keys);
	printf("Total Identifiers: %d\n", total_id);
	return 1;
}