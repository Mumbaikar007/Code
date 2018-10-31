# include "areas.h"
# include <stdio.h>

int main(){
	int a = 5, b = 10;
	printf ( "Area of square with side 5cms is %d cm^2\n", AreaSquare(a) );
	printf ( "Area of rectangle with length 5cms and breadth 10cm is %d cm^2\n", AreaRectangle(a,b) );
	printf ( "Area of circle with side 10cms is %0.2lf cm^2\n", AreaCircle(b) );
	printf ( "Area of triangle with height 5cms and breadth 10cms is %0.2lf cm^2\n", AreaTriangle(a,b) );
	return 0;
}
