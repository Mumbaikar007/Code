//
// Created by optimus on 18/2/18.
//


# include <iostream>
# include <stack>


using namespace std;


int Priority ( char operand ){

    switch ( operand){

        case '/':
        case '*': return 2;

        case '+':
        case '-': return 1;

        default: return 0;

    }
}

string MakePostfix ( string equation ){

    string postfix = "";
    stack <char> stack1;

    for ( char i : equation ){

        if ( i == '(') {
            stack1.push(i);
        }

        else if ( i == ')'){
            while ( stack1.top() != '('){
                postfix += stack1.top();
                stack1.pop();
            }
            stack1.pop();
        }

        else if ( !Priority(i)){
            postfix += i;
        }

        else {

            if ( stack1.empty() ){
                stack1.push(i);
            }
            else {
                while ( !stack1.empty() && stack1.top() != '(' && Priority(i) <= Priority(stack1.top()) ){
                    postfix += stack1.top();
                    stack1.pop();
                }
                stack1.push(i);
            }
        }

    }

    while ( !stack1.empty() ){
        postfix += stack1.top();
        stack1.pop();
    }

    return postfix;

}


int SolvePostfix( string postfix){

    stack <int> theNumbers;
    int a, b;

    for ( char i : postfix ){

        switch ( i ){

            case '+':   a = theNumbers.top();
                        theNumbers.pop();
                        b = theNumbers.top();
                        theNumbers.pop();
                        theNumbers.push(b+a);
                        break;

            case '-':
                        a = theNumbers.top();
                        theNumbers.pop();
                        b = theNumbers.top();
                        theNumbers.pop();
                        theNumbers.push(b-a);
                        break;

            case '*':   a = theNumbers.top();
                        theNumbers.pop();
                        b = theNumbers.top();
                        theNumbers.pop();
                        theNumbers.push(b*a);
                        break;

            case '/':   a = theNumbers.top();
                        theNumbers.pop();
                        b = theNumbers.top();
                        theNumbers.pop();
                        theNumbers.push(b/a);
                        break;
            default :   theNumbers.push(i-'0');
        }
    }

    return theNumbers.top();

}


int main(){

    string equation = "1+2-3*4";

    string postfix = MakePostfix (equation);



    cout << SolvePostfix ( postfix );


    return 0;
}