#include <stdio.h>
#include <unistd.h>


int main(){

       if(fork()==0)
       {
           
           printf("execution de pwd/n");
           execlp("pwd","pwd",NULL);
           perror("Pb pwd");
           exit(1);
       }
        wait(0);
        if(fork()==0)
       {k
           
           printf("execution de ls -l/n");
           execlp("ls","ls","-l",NULL);
           perror("Pb ls -l");
           exit(2);
       }
       wait(0);

       printf("\nprossessus pere =%d,PPID2= $%d\n",getpid(),getppid());
        return 0;


}