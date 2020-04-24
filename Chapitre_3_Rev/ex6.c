#include<stdio.h> 
#include<string.h> 
#include<signal.h> 
#include<unistd.h> 
#include<sys/types.h> 
void stopSec()
{
    printf("vous avez tapez CTRL -Z il y a 3 secscl\n\n");
     kill(getpid(),SIGINT);
}
void waitOpen (int sig) { 
   
    printf("******************\n");
    signal(SIGALRM, stopSec); 
    alarm(3);
    pause();

    
    

    } 

 main() { 
     signal(SIGTSTP,waitOpen); 
     while(1);
      }