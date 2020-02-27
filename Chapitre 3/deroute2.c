#include<stdio.h> 
#include<string.h> 
#include<signal.h> 
void test(int sig) { 
    printf("bien recu signal %d %s\n",sig,strsignal(sig));
     if (sig == SIGINT) { printf("fin volontaire\n"); exit(1); } 
     }
 main() { 
     signal(SIGINT,test); 
     signal(SIGQUIT,test);  
     signal(SIGTSTP,test); 
     signal(SIGUSR1,test);  
     if(signal(SIGSTOP, test) == SIG_ERR) {perror ("SIGSTOP");} 
     if(signal(SIGKILL, test) == SIG_ERR) {perror ("SIGKILL");} 
     for(;;); 
      }