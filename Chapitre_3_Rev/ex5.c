#include<stdio.h> 
#include<string.h> 
#include<signal.h> 
#include<unistd.h> 
#include<time.h>

int * getTime(){
     time_t now;
    time(&now);
    int temps[3];
    struct tm *local = localtime(&now);
    temps[0]= local->tm_year;        
    temps[1] = local->tm_mon;    
    temps[2]=local->tm_mday;
    return temps;

}
void usrFunction(int sig){
    int *t;
     t=getTime();
printf("la date: %d,%d,%d",t[0]+1900,t[1]+1,t[2]);

}

void intFunction (int sig) { 
   
    printf("******** signal 2 bien recu **********\n");
    } 

 main() { 
     signal(SIGINT,intFunction); 
     signal(SIGUSR1,usrFunction);
     signal(SIGTSTP,SIG_IGN);
    while(1);
      }