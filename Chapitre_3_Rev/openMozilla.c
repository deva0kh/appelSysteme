#include<stdio.h> 
#include<string.h> 
#include<signal.h> 
#include<unistd.h>  
void openMozilla (int sig) { 
   
    printf("******** Mozilla **********\n");
    execlp("/Applications/Firefox.app/Contents/MacOS/firefox","/Applications/Firefox.app/Contents/MacOS/firefox",NULL); 
    perror("error de execlp");


    } 
main() { 
    signal(SIGALRM, openMozilla); 
    printf("Ouvrir mozilla dans 5 secs\n"); 
    alarm(5); 
    pause(); }