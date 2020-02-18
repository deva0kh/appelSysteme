#include<stdio.h> 
#include<fcntl.h> 
#include<unistd.h> 
main(int argc, char* argv[]) {
     char* nomfe; int p[2];
     if(argc !=2) {printf ("specifier le fichier traiter"); exit(1);}
     nomfe=argv[1]; 
     
     if(fork()==0){       
          int fe=open(argv[1],O_RDONLY);
          if(fe==-1){perror("ouverture de fe");exit(2);} 
          dup2(fe,0);      
          dup2(p[1],1);   
          close(fe);         
          close(p[0]);    
          close(p[1]);    
          execlp("./mini","./mini",NULL); 
          perror("Pb avec execlp majuscul"); exit(3); 
          } 
          wait(0);

          dup2(p[0],0);
          
          
}
