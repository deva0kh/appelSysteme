#include<stdio.h>
#include<stdlib.h>
#include "tubesem.h"

Semaphore C;

main(){
    int i ;
    void voiture(int,int);
    printf("\n%s%20s%20s%20s\n","VOITURE 1","VOITURE 2","VOITURE 3","VOITURE 4");
    Initsem(C,2);voiture(1,3);
    voiture(2,1);voiture(3,3);
    voiture(4,2);
    for(i=1;i<=4;i++)wait(0);}
void V (Semaphore S){
    char c='a';write(S[1],&c,1);}
    /* Attendre un nombre aleatoire de secondes entre 0 et N-1*/
    void attente(int N){
        sleep(rand() % N);
        }/* Ecrire un message s dans la i eme colonne, la premiere colonne a le numero 1 */
        void message(int i, char* s){
            #define colonne 20
            int Nb, j;
            Nb=(i-1)*colonne;
            for(j=0; j<Nb; j++) putchar(' '); printf("%s\n" ,s);fflush(stdout);
            }
            void Initsem(Semaphore S, int N){
                int i;
                char c='a';
                pipe(S);
                for(i=1;i<=N;i++)write(S[1],&c,1);
                }
                /* P sur le semaphore S, prendre un jeton 'a' */
                void P (Semaphore S){
                    char c;read(S[0],&c,1);
                    }    

void voiture(int n,int duree){
    if(fork()==0){attente(duree);
        message(n,"Arrivee");
        P(C);
        message(n,"Traversee");
        attente(duree);
        message(n,"Depart");
        V(C);
        exit(0);}
}