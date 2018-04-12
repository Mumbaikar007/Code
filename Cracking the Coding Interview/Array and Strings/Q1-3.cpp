//
// Created by optimus on 4/11/17.
//

//INCOMPLETE

# include <cstdio>


using namespace std;

int main(){

    char str[100];
    int size;
    scanf("%d\n", &size);

    fgets(str, sizeof(str), stdin);

    int spaces = 0;
    for ( int i = 0 ; i < size; i ++){
        if ( str[i] == ' ')
            spaces ++;
    }

    int index = size + (spaces * 2);
    str[index] = '\0';

    for ( int i = size-1 ; i >= 0; i --){

        if ( str[i] == ' '){
            str[index - 1] = '0';
            str[index - 2] = '2';
            str[index - 3] = '%';
            index -= 3;
        }

        else {
            str[index-1] = str[i];
            index --;
        }
    }

    /*
    for ( int i = 0 ; i < index; i++ ){
        printf
    }*/

    printf("%s", str);

    //fputs(stdout,"%s\n", str);

    return 0;
}
