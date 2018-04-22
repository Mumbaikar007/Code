%option noyywrap

%{
	# include <stdio.h>
	int tokens = 0;
%}

%%
if|else|print|int|float|while|for	{ printf("Keyword\n"); tokens++; }
"	"|" "				{ printf("Space"); }
[A-Za-z][a-zA-Z0-9_]*			{ printf("Identifiers"); tokens ++; }
[0-9]*					{ printf("Hard code"); tokens++;}
"<"|"="|">"|"+"|"-"|"/"|"*"		{ printf("operators"); tokens++;}
"$"|"#"|";"|"("|")"			{ printf("special character"); tokens ++; }
[\n]					{ printf("Tokens = %d", tokens); tokens = 0; }
%%


int main(){
	printf ("Enter your code: ");
	yylex();
	return 0;
}
