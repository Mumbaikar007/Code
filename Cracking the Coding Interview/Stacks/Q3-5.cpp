//
// Created by optimus on 18/11/17.
//


# include <iostream>
# include <stack>

using namespace std;

int main(){

    stack <int> r, s;

    for ( int i = 1; i <= 10; i ++){
        int num;
        cin >> num ;
        s.push(num);

    }


    while ( !s.empty() ){

        int temp = s.top();
        s.pop();
        while (!r.empty() && temp < r.top() ){
            s.push((int) r.top() );
            r.pop();
        }

        r.push(temp);

    }


    while (!r.empty()){
        cout << r.top() << " ";
        r.pop();
    }

    return 0;
}
