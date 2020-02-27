#include<stdlib.h> 
#include<signal.h> 
main() { 
    struct sigaction act ; 
    act.sa_handler = SIG_IGN;                          
    act.sa_flags = 0; 
    sigaction(SIGINT,&act,NULL); 
    for(;;); 
     }