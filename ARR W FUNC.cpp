#include<stdio.h>
#include<conio.h>
int scores[10], sumpos=0,countpos=0, countneg=0, sumneg=0; //forward decl


int ARRAY_POSNEG(int scores[]) //array function for posneg
{ int ctr=0;
  for(ctr = 0; ctr < 10; ctr++)
    {
	  if(scores[ctr] > 0)
         { sumpos += scores[ctr]; countpos++;  }
      else
	     {sumneg += scores[ctr]; countneg++;}   
	  }
}

void DISPLAY(int scores[], int sumpos, int sumneg, int countpos, int countneg )
{ int ctr=0;
  for(ctr=0; ctr < 10; ctr++)
     {  printf("%d\t", scores[ctr]);}
 
  printf("\n");
  printf("\n The sum of positive scores = %d",sumpos); 
  printf("\n there are %d positive numbers", countpos);
  printf("\n The sum of negative scores = %d",sumneg); 
  printf("\n there are %d negative numbers",countneg);
}

main(void)
{ int ctr=0;
  printf(" Please enter 10 numbers: \n");
  for(ctr = 0; ctr < 10; ctr++)
    { scanf("%d",&scores[ctr]);}
  ARRAY_POSNEG(scores);
  DISPLAY(scores,sumpos, sumneg, countpos, countneg );
  printf("\nDONE!!");
  return 0;
}

/*#include<stdio.h>

int main (){
	
	char name[6] = {'M', 'i', 'g', 'e', 'l'};
	
	printf("My name is:");
	printf(" %s", name);
	
}*/