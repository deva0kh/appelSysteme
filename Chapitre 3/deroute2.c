#include<stdio.h> 
#include<string.h> 
#include<signal.h> 
void test(int sig) { 
    printf("bien recu signal %d %s\n",sig,strsignal(sig));
     if (sig == SIGINT) { printf("fin volontaire\n"); exit(1); } 
     }
 main() { 
     signal(SIGINT,test); 
     for(;;); 
      }