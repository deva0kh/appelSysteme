#include<stdio.h> 
#include<string.h> 
#include<signal.h> 
#include<unistd.h>  
void chrono (int sig) { 
    printf("Bien recu %d %s\n", sig, strsignal(sig)); 
    printf("********Le temps est ecoule **********\n"); 
    } 
main() { 
    signal(SIGALRM, chrono); 
    printf("Prevenez moi dans 5 secondes\n"); 
    printf("Top chrono\n"); 
    alarm(5); 
    pause(); }