#include<stdio.h> 
#include<signal.h>

main(){
  signal(SIGINT,SIG_IGN);
  for(;;);
}