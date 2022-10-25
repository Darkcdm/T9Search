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
            }else{
                depth++;
            }
        }
    }
    return 0;
}

int getLetters (char letters[][5],char keys[], int keysLen){
    int combosLen = 1;
    for (int i=0;i < keysLen; i++){
        
        switch (keys[i]){
            case 48: //0
                //Zero has no assigned letter but must be counted as a valid argument
                return 1;
            break;
            
            case 49: //1
                //One has no assigned letter but must be counted as a valid argument
                return 1;
            break;
        
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

            case 57: //9
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
    return combosLen;
}

int sortContacts (int comboLen, int keyLen, char combos [comboLen][keyLen]){
    
    char line1[100];
    char line2[100];
    
    /*
    while (fgets(line1, 100, stdin) && fgets(line2, 100, stdin)){
            printf("%s\n", line1);
            printf("%s\n", line2);
    }
    */
    
    while (fgets(line1, 100, stdin) && fgets(line2, 100, stdin)){
        
        char buffer [keyLen];
        char sifter [keyLen];
        char selectedLine [100];
        
        
        for (int linePicker = 0; linePicker < 2; linePicker++){
            if (linePicker == 0){
                strcpy(selectedLine, line1);
            }else{
                strcpy(selectedLine, line2);            }
            for (int comboIndex = 0; comboIndex < comboLen; comboIndex++){
                
                int cursor = 0;
                int comboFound = 1;
                while (selectedLine[cursor+keyLen-1] != '\0'){
                    for (int i = 0; i < keyLen; i++){
                        char pickedChar = selectedLine[i+cursor];
                        if (pickedChar >= 97 && pickedChar <= 122){
                            pickedChar = pickedChar - 32;
                        }
                        buffer[i] = pickedChar;
                        sifter[i] = combos[comboIndex][i];
                    }
                    
                    int check = 0;
                    for (int i = 0; i < keyLen; i++){
                        
                        if (sifter[i] == buffer[i]){
                            check++;
                        }
                    }
                    if (check == keyLen){
                        printf("%s\n", line1);
                        printf("%s\n", line2);
                        printf("Matching Chars: %s\n", sifter);
                        comboFound = 0;
                        break;
                    }else{
                        //printf("%s  NOT FOUND\n",sifter);
                    }

                    cursor++;
                }
                if (comboFound == 0){
                    break;
                }
            }
        }
    }
    

    return 0;
}

int printAllContacts(){
    char line1[100];
     while (fgets(line1, 100, stdin)){
        printf("%s\n", line1);
     }
    return 0;
}

int main(int argc, char **argv){
    if (argc < 2){
        printf("No arguments specified\n");
        printAllContacts();
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

    if (combosLen < 0) printf("ERROR, ComboLen too small!\n");

    char combos [combosLen][keysLen];

    if (combosLen != 1){
        combosLen++;        
        createCombos(keysLen,letters, combos);
    }
    for (int i = 0; i < keysLen; i++){
        combos [combosLen-1][i] = keys[i];
    }
    
    sortContacts(combosLen, keysLen, combos);
    return 0;        
} 