#include<stdio.h> 
#include<string.h> 
#include<signal.h> 
#include<unistd.h> 

void openn(){

     execlp("/Applications/Firefox.app/Contents/MacOS/firefox","/Applications/Firefox.app/Contents/MacOS/firefox",NULL); 
     perror("error de execlp");
}
void openMozilla (int sig) { 
   
    printf("******** Mozilla **********\n");
   
    signal(SIGALRM, openn); 
    alarm(5);
    pause();
    

    } 

 main() { 
     signal(SIGINT,openMozilla); 
     while(1);
      }