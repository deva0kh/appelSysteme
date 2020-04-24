#include<stdio.h> 
#include<string.h> 
#include<signal.h> 
#include<unistd.h>  
void readSs(int sig) { 
   
    printf("********Chanson **********\n");
    execlp("/Applications/VLC.app/Contents/MacOS/VLC","/Applications/VLC.app/Contents/MacOS/VLC","IDIR.mp3",NULL); 
    perror("error de execlp");


    } 
main() { 
    signal(SIGALRM, readSs); 
    printf("Lecture de chanson dans 3 secs \n"); 
    alarm(1); 
    pause(); }