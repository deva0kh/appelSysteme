#include<stdio.h> 
#include<fcntl.h> 
#include<unistd.h> 
main(int argc, char* argv[]) {
     char* nomfe; int p[2];
     if(argc !=2) {printf ("specifier le fichier traiter"); exit(1);}
     nomfe=argv[1]; 
     if(pipe(p)==-1) {perror("pipe"); exit (1);}
     if(fork()==0){       
          int fe=open(nomfe,O_RDONLY);
          if(fe==-1){perror("ouverture de fe");exit(1);} 
          dup2(fe,0);      
          dup2(p[1],1);   
          close(fe);         
          close(p[0]);    
          close(p[1]);    
          execlp("./majuscule","./majuscule",NULL); 
          perror("Pb avec execlp majuscul"); exit(1); 
          } 
          
          dup2(p[0],0);   
          close(p[0]);      
          close(p[1]);     
          execlp("./par","./par","4",NULL); 
          perror("Pb avec execlp par"); exit(1);
           }