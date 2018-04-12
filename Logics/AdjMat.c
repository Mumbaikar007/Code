
# include <stdio.h>

#define X 25
#define Y 5


struct Maze
{
    int maze_array[Y][Y];
};

/** Structure Name: Graph
 ** Purpose: Used to store the Graph constructed by the buildGraph() function.
 **          The graph is represented in form of a 2D array wrapped in a structure.
 **/


int main(){

	int maze_array[5][5] = {{9, 5, 5, 3, 11},{12, 3, 11, 10, 10},{9, 6, 10, 12,
	2},{8, 3, 10, 11, 10},{14, 12, 6, 12, 6}};


	int graph_array[X][X];

	// Counters
    int i, j, k;


    /*  Since 15 is 1111 in binary - length 4
        For 2D maze length is 4: Left,Bottom,Right,Top*/
    const int FOUR = 4;


    int connectedTo, cellNumber;

    

    // Initially, no cell is connected with any other cell
    for ( i = 0 ; i < X; i ++){
	for ( j = 0 ; j < X; j ++)
	    graph_array[i][j] = 0;
    } 
    

    for ( i = 0; i < Y ; i ++){
        for ( j = 0 ; j < Y; j ++){
            for ( k = 0; k < FOUR ; k ++){

		if (!(maze_array[i][j] & (1 << k) ) ){
			
			
		    cellNumber = (Y*i + j) ;

		    switch (k){
			
			// Cell above (TOP)
			case 0: connectedTo = cellNumber - Y;
				    graph_array[cellNumber][connectedTo] = 
				    graph_array[connectedTo][cellNumber] = 1;
				break;

			// Cell on right (RIGHT)
			case 1: connectedTo = cellNumber + 1;
				graph_array[cellNumber][connectedTo] = 
				    graph_array[connectedTo][cellNumber] = 1;
				break;

			// Cell below (BOTTOM)
			case 2: connectedTo = cellNumber + Y;
				graph_array[cellNumber][connectedTo] = 
				    graph_array[connectedTo][cellNumber] = 1;
				break;

			// Cell on left (LEFT)
			case 3: connectedTo = cellNumber - 1;
				graph_array[cellNumber][connectedTo] = 
				    graph_array[connectedTo][cellNumber] = 1;
				

		    }


		}


	    }
	}

	}

	for ( i = 0 ; i < X; i ++){
	for ( j = 0 ; j < X; j ++)
	    printf("%d ",graph_array[i][j]);
	printf("\n");
    } 


	return 0;
}