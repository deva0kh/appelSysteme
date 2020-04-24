#include<stdio.h>
#include<sys/stat.h>
#include<errno.h>
#include<fcntl.h>
#include<unistd.h>
main(int argc, char * argv[]){
    int p;int r;
    if (argc!=2){printf("introduire un nom de fichier\n");exit(1);}
    r=mknod(argv[1], S_IFIFO | 0666, 0);
    if(r==-1 && errno!=EEXIST){perror("Pb de creation du tube nommé");exit(2);}
    if((p=open(argv[1],O_WRONLY,0))==-1)
        {perror("ouverture impossible du tube");exit(3);}
    dup2(p,1);
    execlp("./majuscul","./majuscul",NULL);
    perror("Pb execlp");exit(4);
    }