#include <stdio.h>
#include<unistd.h>    
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

void CreerSem(key_t cle, int N);
void InitSem(int N, int V);
void P (int N);
void V (int N);
void DetruireSem();
void message(int i, char* s);