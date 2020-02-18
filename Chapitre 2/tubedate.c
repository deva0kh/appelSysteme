#include<stdio.h> 
#include<unistd.h> 
#include<sys/wait.h>

#include <fcntl.h>

main() { 
    int i, p[2]; 
    char c, 
    res[50]; 

    if(pipe(p)==-1){perror("Pb tube");exit(1);} 
    if(fork()==0){ 
        dup2(p[1],1);
         close(p[0]);
         close(p[1]); 
         execlp("date","date","+%d/%m/%Y",NULL);
         perror("Pb avec execlp date"); exit(1); 
         }
         close(p[1]); 
        int f=open("kal1.txt",O_WRONLY | O_CREAT, 0666); 
        if(f==-1){perror("pb ouverture de fe");
         exit(1);}
         dup2(f,1);
    
         i=0; 
         while(read(p[0],&c,1)!=0) 
         {
             res[i++]=c;
        }

         //res[i-1]=0;    
            
             printf("Date du jour: %s\n",res); close(p[0]); 
             wait(0);
              } 
