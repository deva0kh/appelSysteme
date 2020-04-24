#include<stdio.h>
#include<sys/msg.h>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>



void envoi(){

/* (cours) Structure pour envoyer les messages  */   
   typedef struct{
            long mtype;
            char mtext[256];  }MESSAGE;
    
    MESSAGE message;
    #define LGMES sizeof(message.mtext)


    key_t cle;
    int numfms=-1;

    //creation de la file
    printf("\n\n++++++++++++++++Creation de la fil++++++++++++++++++++++\n\n");
    printf("introduire la cle:  ");
        scanf("%d",&cle);
        numfms=msgget(cle,IPC_CREAT | 0666);
        if(numfms==-1){perror("case 1 erreur msgget");  exit(1);}
        printf("Num interne: %d\n",numfms);

    //envoi de message
         printf("\n\n++++++++++++++++Envoi de la message++++++++++++++++++++++\n\n");
        printf("entrer le PID de destinataire : ");
        scanf("%d",&message.mtype);
        sprintf(message.mtext,"test IPC");
        printf("\nle message est %s\n","test IPC");
        if(msgsnd(numfms,&message,LGMES,IPC_NOWAIT)==-1){perror("case 4 erreur msgsnd");}

}


main(){

        signal(SIGINT,envoi);
  for(;;);




  

}