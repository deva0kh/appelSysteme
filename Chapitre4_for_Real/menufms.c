#include<stdio.h>
#include<sys/msg.h>
#include<unistd.h>
#include<time.h>
typedef enum{faux, vrai} booleen;
int menu(key_t cle, int numfms)
{int Nb, i, N;char* message[]=
{"Fin\n",
"Creation ou consultation d'une file de messgae",
"Destruction de la file courante",
"Caracteristique d une file courante",
"Envoi d un message",
"Reception d'un message (type quelconque)"};
Nb=6;
printf("\nFILE DE MESSAGES\n\n");
for(i=0; i<Nb; i++)
printf("%2d -%s\n",i,message[i]);
if(numfms==-1)
printf("\nPas de file de messages courante\n");
printf("\nPID=%d, Cle=%d, Num interne=%d",getpid(),cle,numfms);
printf("\nEntrez votre choix ?"); 
scanf("%d",&N);
    return N;}
main(){
    key_t cle;int numfms=-1;
    booleen Fin = faux;
    int n;
    /* Structure pour envoyer ou recevoir les messages */
    typedef struct{
            long mtype;
            char mtext[256];  }MESSAGE;
    
    MESSAGE message;
    #define LGMES sizeof(message.mtext)
    /* reception des caracteristique de la file */
    struct msqid_ds buf;
    while(!Fin){
        switch ( menu(cle,numfms) ){
        case 0 :Fin = vrai;
        break;
        
        case 1 :   /* creation ouconsultation d une file de message */
        printf("introduire la cle: ");
        scanf("%d",&cle);numfms=msgget(cle,IPC_CREAT | 0666);
        if(numfms==-1){perror("case 1 erreur msgget");  exit(1);}
        printf("Num interne: %d\n",numfms);
        break;
        
        case 2 :   /* destruction de la file  */
        printf("destruction de la file numero: %d",numfms);
        if (msgctl(numfms,IPC_RMID,NULL)==-1){perror("case 2 msgctl");exit(1);}
        numfms=-1;
        break;
        
        case 3 :  /*  caracteristiques de la file courante  */
        if (msgctl(numfms,IPC_STAT,&buf)==-1){perror("case 3 erreur msgctl");exit(1);}
        printf("Num interne de la file %d\n",numfms);
        printf("Nombre d octets %d\n",buf.msg_cbytes);
        printf("Nombre de messages %d\n",buf.msg_qnum);
        break;
        
        case 4 :  /*  Envoi de message  */
        printf("Numero de PID destinataire ?");
        scanf("%d",&message.mtype);
        sprintf(message.mtext,"**un message du pid: %d**", getpid());
        printf("le messag est %s\n",message.mtext);
        if(msgsnd(numfms,&message,LGMES,IPC_NOWAIT)==-1){perror("case 4 erreur msgsnd");}
        break;
        case 5 :  /*  Reception d un message  *///n=msgrcv(numfms,&message,LGMES,0,IPC_NOWAIT);
         /* type quelconque */
         n=msgrcv(numfms,&message,LGMES,getpid(),IPC_NOWAIT); 
         /* type determine */
         if(n==-1){perror("case 5 erreur msgrcv");
         exit(1);}
         else printf("Recu %d caracteres **%s**\n",n,message.mtext);
         break;
         }}}