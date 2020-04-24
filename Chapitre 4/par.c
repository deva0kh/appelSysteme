#include <stdio.h>
#include <ctype.h>
int main(int argc, char* argv[]){

    int largeur=10;
    int n=0;
    char c;
    
    if(argc==2)largeur=atoi(argv[1]);
      while((c=getchar())!=EOF){
   if(c=="\n") c="";
    putchar(c);
        if(++n >=largeur){
            putchar('\n');
            n=0;

        }
      }
      putchar ('\n');
    return 0;
} 