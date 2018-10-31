

# include <stdio.h>

#define X 49
#define Y 7

struct Path_Array
{
	int path[X];
};

struct Path_Array init_path()
{
	struct Path_Array path;
	for(int i = 0; i < X; i++)
		path.path[i] = -1;
	return path;
}

struct Graph
{
    int graph_array[X][X];
};

struct Path_Array findPath(struct Graph graph, int start, int finish)
{
    struct Path_Array path = init_path();

	// Declare
    
    int i, j, k, min_index, opposite[X];
    int distance[X], visited[X], previous[X];

    // Initialize
	const int MAX_INT = 1000;
	for ( i = 0 ; i < X; i ++){
		distance[i] = MAX_INT;
		visited[i] = 0;
		previous[i] = start;
    }

    // source distance always 0
	distance [start] = 0;
    

    for ( k = 0 ; k < X - 1; k++){
		min_index = MAX_INT;
		for ( i = 0 ; i < X ; i ++){
			if ( !visited[i] &&  min_index > distance[i] ){
				j = i;
				min_index = distance[i];
			}
		}	


		visited [j] = 1;


		for ( i = 0 ; i < X; i ++){
		
			if ( !visited [i] && graph.graph_array [j][i] ) {
		
				if ( ( graph.graph_array[j][i] + distance [j] ) < distance [i] ) {
		
					distance [i] = distance [j] + graph.graph_array [j][i];
					previous [i] = j;

				}

			}

		}

    }


    i = finish;
    j = 0;
    
    while ( i != start ){
	opposite [j++] = i;
	i = previous [i];
    }
    
    k = 0;    
    path.path[0] = start;
    
    for ( i = j - 1; i >= 0 ; i --)
	path.path [++k] = opposite [i];

    return path;
}

/** Function Name: main_function
 ** Input: maze - Maze structure
 **        start - start point of path
 **        finish - end point of path
 ** Output: Returns a Path_Array structure which contains the path in the maze from start to finish.
 ** Logic: This function first constructs a graph from the maze passed as argument and then finds out
 **        path from start to finish. The path is returned as a Path_Array structure.
 ** Example Call: struct Path_Array path = main_function(maze,0,24);
 **/
struct Path_Array main_function( struct Graph adjacency_matrix, int start, int finish)
{
    
	//struct Graph adjacency_matrix = buildGraph( obstacle_x, obstacle_y);
    
    struct Path_Array path = findPath(adjacency_matrix, start, finish);
	return path;
}


int coord_to_flat(int x, int y)
{
    return x*Y + y;
}


int main(int argc, char const *argv[])
{
	
	
	// 49 X 49
	struct Graph adj_matrix;

    // Counters
    int i, j, k;

    int obstacle_x = 6, obstacle_y = 4;


    int connectedTo, cellNumber;

    
    // Initially, no cell is connected with any other cell
    for ( i = 0 ; i < X; i ++){
		for ( j = 0 ; j < X; j ++)
			adj_matrix.graph_array[i][j] = 0;
    } 

	// connecting all horizontal paths
    for ( i = 0 ; i < Y; i ++){
		for ( j = 0; j < Y-1; j ++){
			cellNumber = coord_to_flat( i, j);
			connectedTo = cellNumber + 1;
			adj_matrix.graph_array [cellNumber][connectedTo] = 
					adj_matrix.graph_array [connectedTo][cellNumber] = 1;
		}			
	}
	
	// connecting all vertical paths
	for ( i = 0 ; i < Y-1; i ++){
		for ( j = 0; j < Y; j ++){
			cellNumber = coord_to_flat( i, j);
			connectedTo = cellNumber + 7;
			adj_matrix.graph_array [cellNumber][connectedTo] =
				adj_matrix.graph_array[connectedTo][cellNumber] = 1;
		}
	}
	
	
	// Disconnect all paths connecting to obstacle
	int obstacle = coord_to_flat( obstacle_x -1 , obstacle_y);
	
	//assuming obstacle can be kept on some boundary
	
	// to obstacle's left
	if ( obstacle - 1 >= 0)
		adj_matrix.graph_array[obstacle][obstacle-1] = 
			adj_matrix.graph_array[obstacle-1][obstacle] = 0;
			
	// to obstacle's right
	if ( obstacle + 1 <= X)
		adj_matrix.graph_array[obstacle][obstacle+1] =
			adj_matrix.graph_array[obstacle+1][obstacle] = 0;
		
	// above obstacle
	if ( obstacle - Y >= 0)
		adj_matrix.graph_array[obstacle][obstacle-Y] =
			adj_matrix.graph_array[obstacle-Y][obstacle] = 0;
		
	// below obstacle
	if ( obstacle + Y <= X)
		adj_matrix.graph_array[obstacle][obstacle+Y] =
			adj_matrix.graph_array[obstacle+Y][obstacle] = 0;


	for ( i = 0 ; i < 10; i ++){
		for ( j = 0 ; j < 10; j ++)
			printf("%d ", adj_matrix.graph_array[i][j]);
		printf("\n");
	}

	printf("%d %d %d %d\n", adj_matrix.graph_array[39][32],
		adj_matrix.graph_array[39][40],
		adj_matrix.graph_array[39][38],
		adj_matrix.graph_array[45][46]);


	
    struct Path_Array path = main_function(adj_matrix, 46, 32);
    for(int i = 0; i < X; i++)
    {
        if(path.path[i] == -1)
        {
            break;
        }
        printf("%d ", path.path[i]);
    }
	
	return 0;
}