#include<bits/stdc++.h>
using namespace std;

void isPrime(vector<bool> &vec)
{
    
    vector <int> prime;


    vec[0] = vec[1] = false ;
 
    for ( int i = 2 ; i < 1000000 ; i ++)
        vec[i] = true;
    
    for (int i=2; i < 1000000 ; i++)
    {
        if (vec[i])
        {
    
            prime.push_back(i);
 
            //SPF[i] = i;
        }
 

            for ( int j=0; j < prime.size() && i*prime[j] < 1000000; j++)
            {
                vec[i*prime[j]]=false;
     
        
                //SPF[i*prime[j]] = prime[j] ;
            }
            
        
    }
}


void queue_and_stack (vector<int> A) {
    
    vector <bool> vec(1000000);
    isPrime ( vec ); 

    stack <int> mystack;
    queue <int> myqueue;
    
    /*for ( int i = 0 ; i < 100 ; i ++)
        cout << (vec[i] ? i : 0) << " ";
    */
    
    for ( int i = 0 ; i< A.size() ; i ++){
        if (vec[A[i]])
            myqueue.push(A[i]);
        else
            mystack.push(A[i]);

    }

    while ( !myqueue.empty() ){
        cout << myqueue.front() << " ";
        myqueue.pop();
    }

    cout << endl;

    while (!mystack.empty() ){
        cout << mystack.top() << " ";
        mystack.pop();
    }


    cout << endl;
   
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i_A=0; i_A<n; i_A++)
    {
    	cin >> A[i_A];
    }

    queue_and_stack(A);

    return 0;
}