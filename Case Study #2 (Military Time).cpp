/* Group #20
Members:
Agojo, Aleckz V.
Felipe, Cyrus Kishinn
Tan, Migel H. 
*/

#include<stdio.h>
#define p printf
#define s scanf

void MILITARY_TIME(int military_time){
     
     if(military_time < 0 || military_time >= 2400 || military_time % 100>= 60){
         p("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nINVALID OUTPUT PLEASE TRY AGAIN\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
         
         return;
     }
     int hour = military_time / 100;
     int minute = military_time % 100;
     
     char *period = "AM";
     
     if (hour == 0){
         hour = 12;
     }else if (hour ==12){
     period = "PM";
     
     }else if (hour > 12){
    hour-=12;
    period = "PM";
         
     }
    
    p("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n%02d:%02d %s\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", hour, minute, period);

    }

     int main(){
         
         int military_time;
         
            p("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nEnter your military time: ");
            s("%d", &military_time);
            
            MILITARY_TIME(military_time);
            return 0;
     }
