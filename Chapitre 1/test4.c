#include <stdio.h>
#include <unistd.h>

int main(){

       if(fork()==0)
       {
           sleep(5);
           printf("prossessus fils =%d,PPID= $%d\n",getpid(),getppid());
           exit(0);
       }
       printf("prossessus pere =%d,PPID2= $%d\n",getpid(),getppid());
        return 0;


}