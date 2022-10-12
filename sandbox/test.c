#include <stdio.h>

int main () {
   char str[60];
   FILE *fp;

   if( fgets (str, 60, fp)!=NULL ) {
      /* writing content to stdout */
      puts(str);
   }
   
   return(0);
}