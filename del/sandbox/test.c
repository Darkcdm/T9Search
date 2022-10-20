#include <stdio.h>
int *getMeArray(){
    static int array [2] = {0,1};
    return array;
}


int main(){
    int *arrayp;

    arrayp = getMeArray();

    int array[5];

    for (int i = 0; i < 5; i++) {
        array[i] = *(arrayp+i);
    }


    for(int i = 0; i < 5; i++){
        printf("%d ", array[i]);
    }

    return 0;
}