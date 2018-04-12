//
// Created by optimus on 16/1/18.
//

# include <iostream>
# include <vector>
# include <cmath>


using namespace std;


int distance ( pair<int,int> a, pair<int,int> b){
    return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main(){

    pair<int,int> botA = { 2, 6}, botB = { 6, 6}, botC = { 2, 3};

    vector < vector <pair<int,int>> > vec ( 2, vector<pair<int,int> >(6));
    int a, b;

    for ( int i = 0 ;  i < 6; i ++){
        for ( int j = 0; j < 2; j ++){
            cin >> a >> b;
            vec[j][i] = make_pair( a, b);
        }
    }

    /*
(6, vector <Point> (2))

2 1 2 7
4 1 4 7
6 1 6 7

1 2 7 2
1 4 7 4
1 6 7 6

     */


    pair<int,pair<int,int>> botA_Array[6], botB_Array[6], botC_Array[6];
    pair <int,int> minAH, minAV, minBH, minBV, minCH, minCV;

    minAH.first = minAV.first = minBH.first = minBV.first = minCH. first = minCV.first = 1000;

    for ( int i = 0 ; i < 6; i ++) {

        a = distance(botA, vec[0][i]);
        b = distance(botA, vec[1][i]);

        if (a < b) {

            botA_Array[i].first = a;
            botA_Array[i].second= vec[0][i];
            //cout << "a: " << a << " " << vec[0][i].second << endl;
        }

        else {
            botA_Array[i].first = b;
            botA_Array[i].second = vec[1][i];
            //cout << "b: " << b << " " << vec[1][i].first << endl;
        }

        a = distance(botB, vec[0][i]);
        b = distance(botB, vec[1][i]);

        if (a < b) {
            botB_Array[i].first = a;
            botB_Array[i].second = vec[0][i];
        }

        else {
            botB_Array[i].first = b;
            botB_Array[i].second = vec[1][i];
        }

        a = distance(botC, vec[0][i]);
        b = distance(botC, vec[1][i]);

        if (a < b) {
            botC_Array[i].first = a;
            botC_Array[i].second = vec[0][i];
        }

        else {
            botC_Array[i].first = b;
            botC_Array[i].second = vec[1][i];
        }


        /*
        if ( i < 3 ){

            if ( minAH.first < botA_Array[i].first){
                minAH = botA_Array[i];
            }


            if ( minBH.first < botB_Array[i].first && minAH.second != botB_Array[i].second){
                minBH = botB_Array[i];
            }


            if ( minCH.first < botC_Array[i].first && minBH.second != botC_Array[i].second
                                                      && minAH.second != botC_Array[i].second){
                minCH = botC_Array[i];
            }

        }
        else{

            if ( minAV.first < botA_Array[i].first){
                minAV = botA_Array[i];
            }


            if ( minBV.first < botB_Array[i].first && minAV.second != botB_Array[i].second){
                minBV = botB_Array[i];
            }


            if ( minCV.first < botC_Array[i].first && minAV.second != botC_Array[i].second
                                                      && minBV.second != botC_Array[i].second){
                minCV = botC_Array[i];
            }

        }

        */
    }


    int best_sum_horizontal = 1000;
    int sum_now;
    for ( int a = 0 ; a < 3; a ++){

        sum_now = botA_Array[a].first;
        for ( int b = 0; b < 3 && b != a; b ++){

            sum_now += botB_Array[b].first;
            for ( int c = 0 ; c < 3 && c != a && c != b ; c ++ ){

                sum_now += botC_Array[c].first;
                if ( sum_now < best_sum_horizontal ){
                    minAH = botA_Array[a].second;
                    minBH = botB_Array[b].second;
                    minCH = botC_Array[c].second;
                    best_sum_horizontal = sum_now;
                }

                sum_now -= botC_Array[c].first;
            }

            sum_now -= botB_Array[b].first;
        }
    }

    int best_sum_vertical = 1000;
    for ( int a = 3 ; a < 6; a ++){

        sum_now = botA_Array[a].first;
        for ( int b = 3; b < 6 && b != a; b ++){

            sum_now += botB_Array[b].first;
            for ( int c = 3 ; c < 6 && c != a && c != b ; c ++ ){

                sum_now += botC_Array[c].first;
                if ( sum_now < best_sum_vertical ){
                    minAV = botA_Array[a].second;
                    minBV = botB_Array[b].second;
                    minCV = botC_Array[c].second;
                    best_sum_vertical = sum_now;
                }

                sum_now -= botC_Array[c].first;
            }

            sum_now -= botB_Array[b].first;
        }
    }


    if ( best_sum_horizontal < best_sum_vertical ){
        cout << "Horizon" << endl;
        cout << minAH.first << " " << minAH.second <<endl;
        cout << minBH.first << " " << minBH.second <<endl;
        cout << minCH.first << " " << minCH.second <<endl;
    }
    else{
        cout << "Verti" << endl;
        cout << minAV.first << " " << minAV.second <<endl;
        cout << minBV.first << " " << minBV.second <<endl;
        cout << minCV.first << " " << minCV.second <<endl;
    }

    //cout << minAH.second << " " << minBH.second << " " << minCH.second << endl;


    return 0;
}