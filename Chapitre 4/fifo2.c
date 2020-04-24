#include<stdio.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
main(int argc, char * argv[]){
    int p;
    if (argc!=2){printf("introduire un nom de fichier\n");exit(1);}
    if((p=open(argv[1],O_RDONLY,0))==-1)
    {perror("ouverture impossible du tube");exit(2);}
    dup2(p,0);
    execlp("./par","./par","4",NULL);
    perror("Pb execlp");exit(3);
    }