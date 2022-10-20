#include <stdio.h> 
#include <string.h>
#include <math.h>

char getKeyChars(char key, char letters[]){
    static char buffer [4];

    switch (key){
        
        case 50: //2

            buffer[0] = 'A';
            buffer[1] = 'B';
            buffer[2] = 'C';
            //buffer[3] = NULL;
            
            //char* buffer [] = {"A", "B", "C"};
            break;
        
        case 51: //3
            buffer[0] = 'D';
            buffer[1] = 'E';
            buffer[2] = 'F';
            //buffer[3] = NULL;
            //char* buffer [] = {"D", "E", "F"};
            break;
        
        case 52: //4
            buffer[0] = 'G';
            buffer[1] = 'H';
            buffer[2] = 'I';
            //buffer[3] = NULL;
            //char buffer [] = {"G", "H", "I"};
            break;

        case 53: //5
            buffer[0] = 'J';
            buffer[1] = 'K';
            buffer[2] = 'L';
            //buffer[3] = NULL;
            //char buffer [] = {"J", "K", "L"};
            break;
        
        case 54: //6
            buffer[0] = 'M';
            buffer[1] = 'N';
            buffer[2] = 'O';
            //buffer[3] = NULL;
            //char buffer [] = {"M", "N", "O"};
            break;

        case 55: //7
            buffer[0] = 'P';
            buffer[1] = 'Q';
            buffer[2] = 'R';
            buffer[3] = 'S';
            //char buffer [] = {"P", "Q", "R", "S"};
            break;
        
        case 56: //8
            buffer[0] = 'T';
            buffer[1] = 'U';
            buffer[2] = 'V';
            //buffer[3] = NULL;
            //char buffer [] = {"T", "U", "V"};
            break;

        case 57: //
            buffer[0] = 'W';
            buffer[1] = 'X';
            buffer[2] = 'Y';
            buffer[3] = 'Z';
            //char buffer [] = {"W", "X", "Y", "Z"};
            break;
        
        default:
            printf("Invalid argument! %d", key);
            return 0;
            break;
        
    }

    return buffer;
}

char parseInputArgs(int argc, char **argv){
    if (argc < 2){
        printf("No arguments specified\n");
        return 0;
    } 
    if (argc > 2){
        printf("Too many arguments specified\n");
        return 0;
    } 
    if (argc == 2) printf("One argument is specified\n");
    
    //we know that only one argument is specified so we can statically set argmument array
    int keysLength = strlen(argv[1]);
    

    int lettersLength = keysLength;
    char letters [lettersLength][4];

    for (int i = 0; i < lettersLength; i++){
        char *buffer;
        buffer = getKeyChars(*argv[1]);
            
        strcpy(letters[i], buffer);

            for (int j = 0; j < 4; j++){
                if (*(buffer + j) !=  NULL){
                //printf( "*(p + %d) : %c\n", j, *(buffer + j));
            }
        
        }
        //buffer = getKeyChars(keys[i]);
        //strcpy(letters[i],*buffer);
    }

    int combinationsLength = pow(4,lettersLength);
    char combinations [combinationsLength][4];
    
    for (int startIndex = 0; startIndex < lettersLength; startIndex++){
        for (int depth = 0; depth < lettersLength; depth++){
            if (letters[depth][startIndex] != NULL){
                printf( "*(p + %d) : %c\n", depth, letters[depth][startIndex]);
            }
        }
        

    }
    return combinations;
}

int main(int argc, char **argv){

    
    //Check if a file has been loaded

    //check if there is an input argument.

    //If there is no input argument, then print the whole list

    //get all possible characters from the input arguments
    char *combinations;
    combinations = parseInputArgs(argc, argv);

    for (int i = 0; i < strlen(combinations); i++) {
        printf("%s", combinations[i]);
    }
    //load two first lines from stdin
    char line1[100];
    char line2[100];

    fgets(line1, 100, stdin);
    fgets(line2, 100, stdin);

    printf("%s\n", line1);
    printf("%s\n", line2);
    //copare all possible characters with the loaded lines

    //if there is a match --> print out the line with highlighted matches
    
    //put spacer inbetween outputs
    // 




    return 0;
}





//CODE GRAVEYARD
/*


    <Used for pulling data out of included file/stdin>

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

*/