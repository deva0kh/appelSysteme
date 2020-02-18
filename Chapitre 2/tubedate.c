#include<stdio.h> 
#include<unistd.h> 
#include<sys/wait.h>
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
         i=0; 
         while(read(p[0],&c,1)!=0) 
         {
             res[i++]=c;
        }

         //res[i-1]=0;    
            
             printf("Date du jour: %s\n",res); close(p[0]); 
             wait(0);
              } 
