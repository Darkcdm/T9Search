#include <stdio.h>
#include <string.h>

int getLatters (char latters[][],char keys[], ){
    for (int i=0;i < strlen(keys); i++){
        int combosLen = 0;
        switch (keys[i]){
        
            case 50: //2
                latters[i][0] = 'A';
                latters[i][1] = 'B';
                latters[i][2] = 'C';
                latters[i][3] = "\0";

                combosLen = combosLen + 3;
            break;
            
            case 51: //3
                latters[i][0] = 'D';
                latters[i][1] = 'E';
                latters[i][2] = 'F';
                latters[i][3] = '\0';

                combosLen = combosLen + 3;
            break;
            
            case 52: //4
                latters[i][0] = 'G';
                latters[i][1] = 'H';
                latters[i][2] = 'I';
                latters[i][3] = '\0';

                combosLen = combosLen + 3;
            break;

            case 53: //5
                latters[i][0] = 'J';
                latters[i][1] = 'K';
                latters[i][2] = 'L';
                latters[i][3] = '\0';
                
                combosLen = combosLen + 3;
            break;
            
            case 54: //6
                latters[i][0] = 'M';
                latters[i][1] = 'N';
                latters[i][2] = 'O';
                latters[i][3] = '\0';
                
                combosLen = combosLen + 3;
            break;

            case 55: //7
                latters[i][0] = 'P';
                latters[i][1] = 'Q';
                latters[i][2] = 'R';
                latters[i][3] = 'S';
                latters[i][4] = '\0';

                combosLen = combosLen + 4;
            break;
            
            case 56: //8
                latters[i][0] = 'T';
                latters[i][1] = 'U';
                latters[i][2] = 'V';
                latters[i][3] = '\0';
                
                combosLen = combosLen + 3;
            break;

            case 57: //
                latters[i][0] = 'W';
                latters[i][1] = 'X';
                latters[i][2] = 'Y';
                latters[i][3] = 'Z';
                latters[i][4] = '\0';

                combosLen = combosLen + 4;
            break;
            
            default:
                printf("Invalid argument! %d", keys[i]);
                return -1;
            break;
        }
    }
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
    
    char currentKey;
    char keys[] = argv[1];
    int keyLen = strlen(keys);

    char latters [keyLen][5];

    int combosLen = getLatters(latters[][], keys[]);
    char combos [combosLen][keyLen];
    createCombos(latters, combos);


    for (int i = 0; i < combosLen; i++){
        printf("%s", combos[i]);
    }
} 