#include <stdio.h>

int main(int argc, char **argv) {
    //Reassign input arguments into local values
    // Check if inputs are valid
    // translate the input string
    //assign the list into a nested string

    //search for translated string in the list
    //save all found cases
    //print all found cases

    int i = 0;
    for (i = 0; i < argc; i++) {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    printf("%d",argc);
    return 0;
}