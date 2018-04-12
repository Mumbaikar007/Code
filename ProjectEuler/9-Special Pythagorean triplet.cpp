/*
	Problem:
		https://projecteuler.net/problem=9

	References:
		http://www.friesian.com/pythag.htm
		https://www.mathsisfun.com/numbers/pythagorean-triples.html
		(generalised formula does not generate all triplets)
		https://stackoverflow.com/questions/2817848/find-pythagorean-triplet-for-which-a-b-c-1000

# include <iostream>
# include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	
	int m = 1, n = 2;

	int a = 0, b = 0, c = 0;
	while ( (a+b+c) <= 1000 ){
		
		a = ( (int) pow(n,2) - 1) ;
		b = (2 * n * m);
		c = ((int )pow(n,2) + 1	);

		cout << a << " " << b << " " << c << " " << (a+b+c) << endl
		 ;

		n ++;
	}
	return 0;
}

*/

#include <math.h>
#include <stdio.h>

int main()
{
    const int sum = 1000;
    int a;
    for (a = 1; a <= sum/3; a++)
    {
        int b;
        for (b = a + 1; b <= sum/2; b++)
        {
            int c = sum - a - b;
            if ( a*a + b*b == c*c )
               printf("a=%d, b=%d, c=%d\n",a,b,c);
        }
    }
    return 0;
}