#include <stdio.h>
#include <unistd.h>

int main(){

        int tube[2];
        unsigned char buffer[256];
        int i;

        printf("creation de la tube\n\n\n");
        if(pipe(tube)!=0){
                perror("pipe");
                exit(1);
}
        for ( i = 0; i < 256; i++) buffer[i]=i;
        
            printf("ecreture dans tube\n");
            if ((write(tube[1],buffer,256))!=256){
                perror("ecriture");
                exit(2);
            }
        printf("lecture depuis le pipe/n");
        if(read(tube[0],buffer,256)!=256){
        perror("lire");
        exit(3);}

        printf("tube[0]: %d \n ",tube[0]);
        printf("tube[1]: %d ",tube[1]);
        printf("\n");
        


        return 0;


}