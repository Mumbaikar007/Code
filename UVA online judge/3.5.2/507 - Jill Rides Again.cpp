//
// Created by optimus on 30/1/18.
//

/*
# include <iostream>
#include <vector>

using namespace std;

int main(){


    int t, cases = 0;
    cin >> t;

    while ( t -- ){

        int n;
        cin >> n;

        int x;

        int start = 0, end, temp = 1 ;
        //cout << "Start: " << start << endl;

        int sum = 0, ans = 0;
        for ( int i = 2; i <= n; i ++){

            cin >> x;
            sum += x;

            if ( sum < 0 ){
                sum = 0;
                temp = i;
            }

            if ( sum >= ans){

                if  ( sum > ans || (sum == ans && ( ( i - temp ) > ( end - start) ) ) ){
                    start = temp;
                    end = i;
                    ans = sum;
                }


            }


        }

        if ( ans > 0 ){
            cout << "The nicest part of route " << ++cases << " is between stops " << start << " and " << end << "\n";
        }
        else {
            cout << "Route " << ++cases << " has no nice parts\n";
        }

    }

    return 0;
}*/

#include<cstdio>

using namespace std;

int b, s, n[30000];

int main() {
    scanf("%d", &b);
    for(int i = 1; i <= b; i++) {
        scanf("%d", &s);
        n[0] = 0;
        for(int j = 1; j < s; j++)
            scanf("%d", &n[j]);
        int a = 0, b = 0, c = 0, sum = 0, max = 0;
        for(int j = 1; j < s; j++) {
            sum += n[j];
            if(sum > max || (sum == max && j - a > b - c)) {
                max = sum;
                b = j;
                c = a;
            }
            if(sum < 0) {
                a = j;
                sum = 0;
            }
        }
        if(max > 0)
            printf("The nicest part of route %d is between stops %d and %d\n", i, c + 1, b + 1);
        else
            printf("Route %d has no nice parts\n", i);
    }
}