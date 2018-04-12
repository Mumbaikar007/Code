//
// Created by optimus on 25/1/18.
//

# include <iostream>

using namespace std;

int main(){

    while ( 1){

        int H, U, D, F;
        cin >> H >> U >> D >> F;

        //cout << H << U << D << F << endl;

        if ( H == 0 ) break;

        float climbed = 0;
        float up = U;
        float fatigue = ((float)U * ((float)F /  (float)100.0));
        int day = 1;


        //cout << "Fat: " << (float)fatigue << endl;

        while ( 1 ){



            climbed += up;
            //cout << day << " Day: " << climbed << " ";
            if  ( climbed > H ){
                break;
            }



            climbed -= D;
            //cout << day << " Night: " << climbed << endl;
            if  ( climbed < 0 ){
                break;
            }

            up -= fatigue;
            if ( up < 0 )
                up = 0;

            day ++;
        }

        if (climbed < H ){
            cout << "failure on day " << day << endl;
        }
        else {
            cout << "success on day " << day << endl;
        }

    }

    return 0;
}