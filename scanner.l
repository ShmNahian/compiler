%{
	#include <stdlib.h>
	int total_keys = 0, total_id = 0;
%}

%%
int|float|true|if|return|else		{printf("Keyword: %s\n", yytext);
					total_keys++;}

[_a-zA-Z][_a-zA-Z0-9]*			{printf("Identifier: %s\n", yytext);
					total_id++;}

[-]?[0-9]+				{printf("Integer Number: %s\n", yytext);}

[-]?[0-9]*[.][0-9]+			{printf("Float Number: %s\n", yytext);}

>=|<=|==|>|<				{printf("Relational Operator: %s\n", yytext);}

=					{printf("Assignment Operator: %s\n", yytext);}

[();]					{printf("Delimiter: %s\n", yytext);}

[ \n\t]+				;

%%

int main(){
	FILE* fp = fopen("input.txt", "r");
	yyin = fp;
	yylex();
	return 1;
}

int yywrap(){
	printf("Total Keywords: %d\n", total_keys);
	printf("Total Identifiers: %d\n", total_id);
	return 1;
}