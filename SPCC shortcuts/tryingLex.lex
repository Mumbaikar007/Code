
%option noyywrap

%{
	# include <stdio.h>
	int op = 0;
	float  a, b;
%}

dig [0-9]+|([0-9]+)"."([0-9]*)

%%

{dig} 	{ digi(); }
[+]	{ op = 1; }
[-]	{ op = 2; }
[*]	{ op = 3; }
[/] 	{ op = 4; }
[\n]	{ printf("Total is %f\nEnter equation: " , a); a = 0; }

%%

digi() {

	if ( op == 0 ) 
		a = atof(yytext);
	else {
		b = atof(yytext);		
 		switch (op) {
			case 1:
				a = a + b;
				break;
			case 2:
				a = a - b;
				break;
			case 3:
				a = a * b;
				break;
			case 4:
				a = a / b;
		}
		op = 0;
  	}

}

int main(){
	printf("Enter equation: ");
 	yylex();
	return 0;
}
