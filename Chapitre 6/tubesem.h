#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
typedef int Semaphore [2];

 void Initsem(Semaphore S, int N);
 void P(Semaphore S);
 void V(Semaphore S);
 void attente(int N);
 void message(int i, char* s);
 void message2(int i, char* s,int x,int y);