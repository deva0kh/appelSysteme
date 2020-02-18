#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<sys/wait.h>
int main(int argc, char* argv[]){
    char nomfm[1000]="2";
    char* nomfe;
    
    if(argc!=2){
        printf("choisir un fichier");
        exit(1);
    }
    nomfe=argv[1]; 
    sprintf(nomfm,"one"); 
    if(fork()==0){ 
        int fe=open(nomfe,O_RDONLY); 
        if(fe==-1){perror("pb ouverture de fe");
         exit(1);}
     dup2(fe,0); 
     int fm=open(nomfm,O_WRONLY | O_TRUNC | O_CREAT, 0666);
      if(fm==-1){perror("pb ou verture de fm"); exit(1);}
      dup2(fm,1); execlp("./majuscule","./majuscule",NULL); 
      perror ("pb de execlp"); exit(1); }

    wait(0);
    if (fork()==0){ 
        int fm=open(nomfm,O_RDONLY); 
    if (fm==-1){perror("pb ouverture de fm");exit(1);} 
    dup2(fm,0); 
    unlink(nomfm);
     execlp("./par","./par","8",NULL);
      perror("pb de execlp"); exit(1);
   
}
 wait(0);
    return 0;
} 