#include <stdio.h>
#include <unistd.h>

int main(){

        printf("pid %d, ppid  %d",getpid(),getppid());
        return 0;


}