#include <stdio.h>
#include <string.h>

int createCombos(int maxDepth,char letters[][5], char combos[][maxDepth]){
    //set up of all variables
  
    int depth = 0;
    int selector [maxDepth];
    int combosLen = 0;

    //seting up the selector
    for (int i = 0; i < maxDepth; i++){
        selector[i] = 0;
    }


    //will continue the loop until the selected character in the first row is '\0'
    while (letters[0][selector[0]] != '\0'){

        //Load the first combination into combos array (the fist combination is all zeros)
        //simplify the char selection to one variable
        char selectedChar = letters[depth][selector[depth]];

        int resetCheck = 0;

        for (int i = 0; i < maxDepth; i++){
            if (letters[i][selector[i]] == '\0'){
                resetCheck = i;
            }
        }


        //Check that I haven't selected the end of the line char
        if (selectedChar == '\0' || resetCheck != 0){
            //if I did selected the end of the line, then go back to start and up the selector above
            selector[resetCheck] = 0;
            selector[resetCheck - 1]++;
        }else{
            //else, enter the selectedChar into combos Array and print it out for debuging
            combos[combosLen][depth] = selectedChar;
            //printf("%c", selectedChar);
        }


    

        if (resetCheck != 0){
            depth = 0;
        }else{
            //if the depth is maxed, then go back to zero and start another combo
            if (depth == maxDepth-1){
                depth = 0;
                combosLen++;

                //move the lower selector by one
                selector[maxDepth-1]++;

                //printf("\n");
            }else{
                depth++;
            }
        }
    }
    printf("%d\n", combosLen);
    return 0;
}

int getLetters (char letters[][5],char keys[], int keysLen){
    int combosLen = 1;
    for (int i=0;i < keysLen; i++){
        
        switch (keys[i]){
        
            case 50: //2
                letters[i][0] = 'A';
                letters[i][1] = 'B';
                letters[i][2] = 'C';
                letters[i][3] = '\0';

                combosLen = combosLen * 3;
            break;
            
            case 51: //3
                letters[i][0] = 'D';
                letters[i][1] = 'E';
                letters[i][2] = 'F';
                letters[i][3] = '\0';

                combosLen = combosLen * 3;
            break;
            
            case 52: //4
                letters[i][0] = 'G';
                letters[i][1] = 'H';
                letters[i][2] = 'I';
                letters[i][3] = '\0';

                combosLen = combosLen * 3;
            break;

            case 53: //5
                letters[i][0] = 'J';
                letters[i][1] = 'K';
                letters[i][2] = 'L';
                letters[i][3] = '\0';
                
                combosLen = combosLen * 3;
            break;
            
            case 54: //6
                letters[i][0] = 'M';
                letters[i][1] = 'N';
                letters[i][2] = 'O';
                letters[i][3] = '\0';
                
                combosLen = combosLen * 3;
            break;

            case 55: //7
                letters[i][0] = 'P';
                letters[i][1] = 'Q';
                letters[i][2] = 'R';
                letters[i][3] = 'S';
                letters[i][4] = '\0';

                combosLen = combosLen * 4;
            break;
            
            case 56: //8
                letters[i][0] = 'T';
                letters[i][1] = 'U';
                letters[i][2] = 'V';
                letters[i][3] = '\0';
                
                combosLen = combosLen * 3;
            break;

            case 57: //
                letters[i][0] = 'W';
                letters[i][1] = 'X';
                letters[i][2] = 'Y';
                letters[i][3] = 'Z';
                letters[i][4] = '\0';

                combosLen = combosLen * 4;
            break;
            
            default:
                printf("Invalid argument! %d", keys[i]);
                return -1;
            break;
        }
    }
    printf("%d\n", combosLen);
    return combosLen;
}

int main(int argc, char **argv){
    if (argc < 2){
        printf("No arguments specified\n");
        return 1;
    } 
    if (argc > 2){
        printf("Too many arguments specified\n");
        return 1;
    } 
    if (argc == 2) printf("One argument is specified\n");
    
    int keysLen = strlen(argv[1]);
    char keys[keysLen];
    strcpy (keys, argv[1]);
    
    char letters [keysLen][5];

    int combosLen = getLetters(letters, keys, keysLen);
    if (combosLen < 0) return 1;
    char combos [combosLen][keysLen];
    createCombos(keysLen,letters, combos);

    /*
    for (int i = 0; i < combosLen; i++){
        printf("%s", combos[i]);
    }
    */
} 