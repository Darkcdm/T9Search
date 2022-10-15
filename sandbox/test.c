#include <stdio.h>

int main(int argc, char **argv){
    int i = 0;
    for (i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }
    printf("%d\n",argc);

    char buffer[256];
    while(fgets(buffer, 256, stdin)) puts(buffer);

    return 0;
}