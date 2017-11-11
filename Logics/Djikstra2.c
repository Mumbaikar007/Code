// Djikstra using adj mat


# include <stdio.h>
# include <limits.h>


int dijkstra ( int graph[6][6], int source){

	// Declare
	int max_heap[6], visited[6], distance[6], parent[6];
	int i, j, k;

	// Initialize
	for ( i = 0 ; i < 6 ; i ++ ){
		max_heap[i] = INT_MAX;
		visited[i] = 0;
	}

	// For initial point
	distance[source] = 0;
	parent[source] = 0;

	for ( i = 0; i < 6; i ++){

		int u;
		int min = INT_MAX;
		
		for ( j = 0 ; j < 6; j ++){
			if ( max_heap[j] && min > max_heap[j]){
				u = j; 
				min = max_heap[j];
			}
		}

		max_heap[u] = 0;

		for ( k = 0 ; k < 6 ; k ++){
			if ( !visited[i] && graph[i][k]  )
		}



	}



}



int main(){

	int graph[6][6] = { { 0, 5, 0, 9, 2, 0},
						{ 5, 0, 2, 0, 0, 0},
						{ 0, 2, 0, 3, 0, 0},
						{ 9, 0, 3, 0, 0, 2},
						{ 2, 0, 0, 0, 0, 3},
						{ 0, 0, 0, 2, 3, 0}
					  };


	return 0;

}