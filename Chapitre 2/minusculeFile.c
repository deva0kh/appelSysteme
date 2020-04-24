#include<stdio.h> 
#include<fcntl.h> 
#include<unistd.h> 
main(int argc, char* argv[]) {
     char* nomfe; int p[2];
     char* nomfm;
     char* nomfm1;
     char c;
     char res[50];
     int i;
     if(argc !=3) {printf ("specifier le fichier traiter"); exit(1);} nomfm1="kal.txt";
     nomfe=argv[1]; 
     nomfm=argv[2];
     if(fork()==0){       
          int fe=open(argv[1],O_RDONLY);
          if(fe==-1){perror("ouverture de fe");exit(2);} 
          dup2(fe,0);      
          dup2(1,p[1]);   
          close(fe);         
          close(p[0]);    
          close(p[1]);    
          execlp("./mini","./mini",NULL); 
          perror("Pb avec execlp majuscul"); exit(3); 
          } 
          wait(0);

          char buffer[100];
          
       int fm=open(nomfm1,O_WRONLY | O_TRUNC | O_CREAT, 0666); 
        if (fm==-1){perror("FM error");exit(4);}
                 dup2(0,p[0]);
                 read(p[0], buffer,100);
                 dup2(fm,1);
                 
                 printf("%s\n",buffer);
          
}
