#include"ipcsem.h"
int Num;
/* Fournit le numero Num du groupe de semaphores crees */
void CreerSem(key_t cle, int N) {
    Num=semget(cle, N, 0600 | IPC_CREAT);

    if(Num==-1){perror("Pb CreerSem");exit(1);}
    
    }

void DetruireSem() {semctl(Num, 0, IPC_RMID, 0);}

void InitSem(int N, int V) {semctl(Num, N, SETVAL, V);}

void P(int N) {
    struct sembuf Tabop;
Tabop.sem_num=N;
Tabop.sem_op=-1;
Tabop.sem_flg=0;
semop(Num, &Tabop,1);

}
void V(int N) {struct sembuf Tabop; 
Tabop.sem_num=N;Tabop.sem_op=1;Tabop.sem_flg=0;semop(Num, &Tabop, 1);}

void attente(int N){sleep(rand() % N);}



main(){
    
    int i ;
    void voiture(int,int);
    
    printf("\n%s%20s%20s%20s\n","VOITURE 1","VOITURE 2","VOITURE 3","VOITURE 4");
    CreerSem(1000,2);
    InitSem(Num,2);
  
    
    voiture(1,3); 
    voiture(2,1);
    voiture(3,3);
    voiture(4,2);
     
    for(i=1;i<=4;i++)wait(0);
    DetruireSem();
    }

    void voiture(int n,int duree){
    if(fork()==0){attente(duree);
        message(n,"Arrivee");
        P(Num);
        message(n,"Traversee");
        attente(duree);
        message(n,"Depart");
        V(Num);
        exit(0);}
}
 void message(int i, char* s){
            #define colonne 20
            int Nb, j;
            Nb=(i-1)*colonne;
            for(j=0; j<Nb; j++) putchar(' '); printf("%s\n" ,s);fflush(stdout);
            }