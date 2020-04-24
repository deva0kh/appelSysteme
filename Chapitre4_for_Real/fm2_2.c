#include<stdio.h>
#include<sys/msg.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
void recoi(){

    /* (cours) Structure pour recevoir les messages  */   
   typedef struct{
            long mtype;
            char mtext[256];  }MESSAGE;
    
    MESSAGE message;
    #define LGMES sizeof(message.mtext)

    key_t cle;
    int n;
    int numfms;

    printf("saisir le Num interne generer : ");
    scanf("%d",&numfms);
    n=msgrcv(numfms,&message,LGMES,0,IPC_NOWAIT); 
        
         if(n==-1){perror("case 5 erreur msgrcv");
         exit(1);}
         else printf("Recu %d caracteres **%s**\n",n,message.mtext);
}
main(){

      signal(SIGTSTP,recoi);
  for(;;);
}