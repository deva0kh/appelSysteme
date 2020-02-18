#include <stdio.h>
#include <unistd.h>


int main(){

       if(fork()==0)
       {
           
           printf("execution de id\n\n");
           
           execlp("id","id",NULL);
            printf("le pid : %d , ppid : %d",getpid(),getppid());
           perror("Pb id");
           exit(1);
       }
        wait(0);
        if(fork()==0)
       {
           
           printf("\n=======================================================\n");
           printf("execution de tty\n\n");
           execlp("tty","tty",NULL);
            printf("le pid : %d , ppid : %d",getpid(),getppid());
           perror("Pb tty ");
           exit(2);
       }
       wait(0);
       if(fork()==0)
       {
           printf("\n=======================================================\n");
           printf("execution de who\n\n");
           execlp("who","who",NULL);
           printf("le pid : %d , ppid : %d",getpid(),getppid());
           perror("Pb who ");
           exit(3);
       }
       wait(0);


       //printf("\nprossessus pere =%d,PPID2= $%d\n",getpid(),getppid());
        return 0;


}