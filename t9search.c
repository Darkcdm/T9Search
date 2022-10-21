#include <stdio.h>
#include <string.h>

int getLetters (char letters[][4],char keys[], int keysLen){
    int combosLen = 0;
    for (int i=0;i < keysLen; i++){
        
        switch (keys[i]){
        
            case 50: //2
                letters[i][0] = 'A';
                letters[i][1] = 'B';
                letters[i][2] = 'C';
                letters[i][3] = "\0";

                combosLen = combosLen + 3;
            break;
            
            case 51: //3
                letters[i][0] = 'D';
                letters[i][1] = 'E';
                letters[i][2] = 'F';
                letters[i][3] = '\0';

                combosLen = combosLen + 3;
            break;
            
            case 52: //4
                letters[i][0] = 'G';
                letters[i][1] = 'H';
                letters[i][2] = 'I';
                letters[i][3] = '\0';

                combosLen = combosLen + 3;
            break;

            case 53: //5
                letters[i][0] = 'J';
                letters[i][1] = 'K';
                letters[i][2] = 'L';
                letters[i][3] = '\0';
                
                combosLen = combosLen + 3;
            break;
            
            case 54: //6
                letters[i][0] = 'M';
                letters[i][1] = 'N';
                letters[i][2] = 'O';
                letters[i][3] = '\0';
                
                combosLen = combosLen + 3;
            break;

            case 55: //7
                letters[i][0] = 'P';
                letters[i][1] = 'Q';
                letters[i][2] = 'R';
                letters[i][3] = 'S';
                letters[i][4] = '\0';

                combosLen = combosLen + 4;
            break;
            
            case 56: //8
                letters[i][0] = 'T';
                letters[i][1] = 'U';
                letters[i][2] = 'V';
                letters[i][3] = '\0';
                
                combosLen = combosLen + 3;
            break;

            case 57: //
                letters[i][0] = 'W';
                letters[i][1] = 'X';
                letters[i][2] = 'Y';
                letters[i][3] = 'Z';
                letters[i][4] = '\0';

                combosLen = combosLen + 4;
            break;
            
            default:
                printf("Invalid argument! %d", keys[i]);
                return -1;
            break;
        }
    }
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
    
    char keys[] = argv[1];
    int keysLen = strlen(keys);

    char letters [keysLen][5];

    int combosLen = getLetters(letters, keys, keysLen);
    char combos [combosLen][keysLen];
    createCombos(letters, combos);


    for (int i = 0; i < combosLen; i++){
        printf("%s", combos[i]);
    }
} 