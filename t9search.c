#include <stdio.h>
char * parseInputList(){
    int maxSize = 100;
    char * parsedList [1][1];
    int size = 0;
    char buffer[maxSize];
    while(fgets(buffer, maxSize, stdin)){
        size++;


        
        //puts(buffer);
    } 
}
char * parseInputArgs(int argc, char **argv){

}


int main(int argc, char **argv){
    //Check if a file has been loaded
    //check if there is an input argument. 
    //If there is no input argument, then print the whole list
    //get all possible characters from the input arguments
    //load two first lines from stdin
    //copare all possible characters with the loaded lines
    //if there is a match --> print out the line with highlighted matches
    //put spacer inbetween outputs
    // 



    char * searchedChars[] = parseInputArgs(argc, argv);


    int i = 0;
    
    for (i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    printf
    ("%d\n",argc);

    
    //fgets(buffer, 256, stdin);
    //puts(buffer);

    return 0;
}