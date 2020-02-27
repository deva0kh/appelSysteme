#include<stdio.h> 
#include<signal.h> 
#include<unistd.h> 
#include<string.h> 


main() { 
    int i; 
    sigset_t masque; 
    sigemptyset(&masque); 
    sigaddset(&masque,SIGINT); 
    sigaddset(&masque,SIGQUIT); 
    if (sigismember(&masque,SIGINT)) 
        {
            printf("SIGINT est membre\n");
            } 
    if (sigismember(&masque,SIGALRM)) 
        {
            printf("SIGALRM est membre"); 
        }
    
    sigprocmask(SIG_BLOCK,&masque,NULL);  

    for(;;); 
    }