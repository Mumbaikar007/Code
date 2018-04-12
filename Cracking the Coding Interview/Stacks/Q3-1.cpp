//
// Created by optimus on 12/11/17.
//

# include <iostream>

# define SIZE 10


using namespace std;

void push ( int array[10], int top[3], int rank, int element){

    if ( top[rank] == rank + SIZE/3)
        cout << "stack " << rank << " is full !"<< endl;

    array[top[rank]++] = element;

}

void pop ( int top[3], int rank){

    if ( top[rank] == rank * SIZE/3)
        cout << "Empty stack !! \n";

    --top[rank];
}

void Ftop(int array[10], int top[3], int rank){
    cout << "Stack " << rank << " top is " << array[top[rank]] << endl;
}

int main(){

    int array[SIZE];

    int by3 = SIZE / 3;

    int top[3];

    for ( int i = 0 ; i < 3; i ++)
        top[i] = by3 * i;


    int choice = 0;
    while (choice < 4){

        int action, element;


        cin >> choice >> action >> element;
        switch (choice){

            case 1: (action == 1) ? push( array, top, 0, element) : pop (top, 0);
                    Ftop( array, top, 0);
                    break;

            case 2: (action == 1) ? push( array, top, 1, element) : pop (top, 1);
                    Ftop( array, top, 1);
                    break;

            case 3: (action == 1) ? push( array, top, 2, element) : pop (top, 2);
                    Ftop( array, top, 2);
                    break;

            default: cout << "Ending ... \n" << endl;

        }


    }

    return 0;
}