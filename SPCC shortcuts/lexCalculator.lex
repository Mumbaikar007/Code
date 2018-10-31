%option noyywrap

%{
	#include <stdio.h>
	int op=0,i;
	float a,b;
%}

dig [0-9]+|([0-9]+)"."([0-9]+)
add "+"
sub "-"
mul "*"
div "/"
pow "^"
ln \n
%%
{dig} {digi();} /*** digi() is a user defined function ***/
{add} {op=1;}
{sub} {op=2;}
{mul} {op=3;}
{div} {op=4;}
{pow} {op=5;}
{ln} {printf("\n the result :%f\n\n",a);}

%%
digi()
{
	if(op==0)
	a=atof(yytext); /*** atof() is used to convert the ASCII input to float***/
	else
	{
	b=atof(yytext);
	switch(op)
	{
		case 1:a=a+b;
		break;
		case 2:a=a-b;
		break;
		case 3:a=a*b;
		break;
		case 4:a=a/b;
		break;
		case 5:for(i=a;b>1;b--)
		a=a*i;
		break;
		}
		op=0;
	}
}
int main(int argv,char *argc[])
{
	printf ("Enter eqution: ");
	yylex();
	return 0;
}

