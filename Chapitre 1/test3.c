#include <stdio.h>
#include <unistd.h>

int main(){

        execlp("ls","ls",NULL);
        perror("error dans execlp");
        return 0;


}