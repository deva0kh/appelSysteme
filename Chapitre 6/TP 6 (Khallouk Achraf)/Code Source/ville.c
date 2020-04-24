#include<stdio.h> 
#include<stdlib.h> 
#include "tubesem.h" 

Semaphore ville2, ville3, ville4;
main() { int i ;
void train(int);
void voiture(int);
void avion(int);
void autocar(int); printf("\n%-20s%-20s%-20s%-20s%-20s\n","TRAIN",
"VOITURE1","VOITURE2","AVION","AUTOCAR");
Initsem(ville2,0); Initsem(ville3,0); Initsem(ville4,0);
train(1);
voiture(3);
voiture(2);
avion(4);
autocar(5); 
for(i=1;i<=5;i++)wait(0); }
void train(int i) {
if(fork()==0)
{
message(i,"Depart de ville1"); attente(2);
message(i,"Arrivee a ville2"); V(ville2);
V(ville2); V(ville2); exit(0);
}}
void voiture(int i)
{
if(fork()==0)
{
message(i,"Attente a ville2"); P(ville2);
message(i,"Depart de ville2"); attente(4);
message(i,"Arrivee ville3"); V(ville3);
exit(0);
}}
void avion(int i)
{
if(fork()==0)
{
message(i,"Attente ville2"); P(ville2); message(i,"Decollage ville2"); attente(4);
message(i,"Arrivee ville4"); V(ville4);
exit(0);
}}
void autocar(int i) {
if (fork()==0)
{
    message(i,"Attente ville3"); P(ville3);
P(ville3); message(i,"Depart ville3"); attente(3); message(i,"Arrivee ville4"); P(ville4); 
message(i,"Depart ville4"); attente(2); message(i,"Arrivee ville5"); exit(0);
}}
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