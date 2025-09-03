#include<stdio.h>
#include<conio.h>

int AT=0,AR=0;
char FIGURE;

int AREA_REC()
{ int B=0, H=0;
	   printf("Enter BASE and HEIGHT: \n");
       scanf("%d %d", &B, &H);
       AR = B * H;
       return(AR);
 }
 
 int AREA_TRI()
 { int B=0, H=0;
       printf("Enter BASE and HEIGHT: \n");
       scanf("%d %d", &B, &H);
       AT = 0.5 * B * H;
       return(AT);
 }
 
 
void AREA(char FIGURE1)
{

if (FIGURE1 == 'R' || FIGURE1 == 'r')
       {
	   AR=AREA_REC();
       printf("\nAREA OF RECTANGLE = %d",AR);}
    else
	{ if(FIGURE1 == 'T' || FIGURE1 == 't')
	   {
	    AT=AREA_TRI();
        printf("\nAREA OF TRIANGLE %d", AT);}
       
	  else 
	     printf("INVALID ENTRY");
	  
	 } 
}
	 
  
main(void)
{ 
  
  
   printf("What figure to compute (R-Rectangle and T for Triangle): \n");
   scanf("%c",&FIGURE);
   AREA(FIGURE);
 
   printf("\nDONE!");
getch();       
}