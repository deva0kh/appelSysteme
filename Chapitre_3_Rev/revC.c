#include<stdio.h> 
#include<string.h> 
#include<signal.h> 
#include<unistd.h>  
#include<time.h>  
void readSs(int sig) { 
   
    printf("\t********  temps est écoulé  **********\n");
    execlp("/Applications/VLC.app/Contents/MacOS/VLC","/Applications/VLC.app/Contents/MacOS/VLC","IDIR.mp3",NULL); 
    perror("error de execlp");


    } 
int * getTime(){
     time_t now;
    time(&now);
    int temps[2];
    struct tm *local = localtime(&now);
    temps[0]= local->tm_hour;        
    temps[1] = local->tm_min;    
    return temps;

}


main() { 
    
    int heure=25,minute=61,*t,t1[2],heureActuel,minuteActuel;
    signal(SIGALRM, readSs); 
     t=getTime();
     heureActuel=t[0];
     minuteActuel=t[1];
    
    printf("\n\n################ Réveil ###################\n");
    printf("Le temp Actuel : %02d:%02d\n\n", heureActuel, minuteActuel);
   
   while(heure>24 || heure <0) {printf("sasir l'heure:\t");   scanf("%d",&heure);}
      while(minute>60 || minute <0) {printf("sasir les minutes:\t");   scanf("%d",&minute);}
   
    t1[0]=(heureActuel<=heure)?heure-heureActuel:(24-heureActuel)+heure;
    t1[1]=(minuteActuel<=minute)?minute-minuteActuel:(60-minuteActuel)+minute;
   
    printf("\n\t\tsonne dans %02d heures  et %02d minutes\n\n",t1[0],t1[1]);
    printf("%02d:%02d\n",heure,minute);
   
    alarm((t1[0]*3600)+(t1[1]*60)); 
    pause();
     }