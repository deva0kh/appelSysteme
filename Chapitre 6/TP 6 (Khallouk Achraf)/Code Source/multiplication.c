#include<stdio.h> 
#include<stdlib.h> 
#include "tubesem.h" 

int a=4;int b=3;
Semaphore s;
main() { int i ;
void p1(int);
void p2(int);
void p3(int);
printf("\n%-20s%-20s%-20s\n",
"a","b","Resultat");
Initsem(s,0); 
p1(1);
p2(2);
p3(3);

for(i=1;i<=5;i++)wait(0); }


void p1(int i){
    if(fork()==0)
{
message(i,"a= 4");
a=a*2;attente(1);
message(i,"a*2");
V(s);
exit(0);
}}

void p2(int i)
{
    if(fork()==0)
{
message(i,"b= 3");
b*=5;attente(1);
message(i,"b*5");
V(s);
exit(0);
}}

void p3(int i){
    if(fork()==0)
{
message(i,"Attente des valeurs");
 P(s);P(s);attente(3);
message2(i," (a * 2) + (b * 5) =",a,b);


exit(0);
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

     void message2(int i, char* s,int x,int y){
            #define colonne 20
            int Nb, j;
            Nb=(i-1)*colonne;
            for(j=0; j<Nb; j++) putchar(' '); printf("%s %d\n" ,s,((x * 2) + (y * 5)));fflush(stdout);
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