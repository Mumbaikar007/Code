//
// Created by optimus on 6/2/18.
//

# include <iostream>

using namespace std;


struct Pass1Print {

    int locaiton, num;
    string instruction;

    Pass1Print ( int locationCounter, int integerInWords, string machineInstruction) :
            locaiton(locationCounter), num(integerInWords), instruction (machineInstruction){}
};

int main(){


    int a = 10, b = 20;
    string abc = "abc";

    Pass1Print pass1Print ( a, b, abc);
    cout << pass1Print.locaiton << " " << pass1Print.num << " " << pass1Print.instruction;
    return 0;

}
