#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    
    int n;
    cin >> n;
    
    int vols;
    cin >> vols;
    
    vector < vector  < int> > vec ( vols);
    for ( int i = 0 ; i < vols ; i ++ )
        vec[i].resize(3);
    
    for ( int i = 0 ; i < vols ; i++){
        
        for ( int j = 0 ; j < 3 ; j ++)
            cin >> vec[i][j];
        
    }
    
    int max = 0 ;
    
    
    for ( int i = 0 ; i < n; i ++){

        for ( int j = 0 ; j < n; j ++){
            
            int cell = 0 ;
            
            for ( int k = 0 ; k < vols; k ++){
                if ( j - vec[k][1] == 0  && i - vec[k][0] == 0)
                    cell += vec[k][2];
                
                else if ( abs ( j - vec[k][1]) < vec[k][2]){
                    if  ( abs ( i - vec[k][0]) < vec[k][2] ){
                            if ( abs ( i - vec[k][0]) < abs ( j - vec[k][1]) )
                                cell += (vec[k][2] - ( abs ( j - vec[k][1])));
                            else 
                                cell += (vec[k][2] - ( abs ( i - vec[k][0])));
                    }
                }
                
            }
            //cout << cell << " ";
            if ( cell > max)
                max = cell;
            
        }
        //cout << endl;
    }
    
    cout << max;
    
        
    
    
    
    return 0;
}
