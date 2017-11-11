
# include <stdio.h>

int main(){
	



	const int MAX_INT = 1000, X = 25;
    int i, j, k, min_index, opposite[X];
    int distance[X], visited[X], previous[X];

    for ( i = 0 ; i < X; i ++){
		distance[i] = MAX_INT;
		visited[i] = 0;
		previous[i] = start;
    }

     [start] = 0;
    

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
		
	    if ( !visited [i] && graph [j][i] ) {
		
		if ( ( graph[j][i] + distance [j] ) < distance [i] ) {
		
		    distance [i] = distance [j] + graph [j][i];
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
    path[0] = start;
    for ( i = j - 1; i >= 0 ; i --)
		path [k++] = opposite [i];

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
