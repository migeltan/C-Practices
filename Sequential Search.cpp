/*
Sequential search is also known as linear search or serial. 
The Sequential search method is a very simple and straightforward 
technique to search a specified data item in an unordered list. 

Mayroong break statement para makita yung matched variable.
*/

#include<stdio.h>
#include<conio.h>

int main()
{ int array[5], n, i=0, pos;
char choice;

do{
printf("\nPlease enter 5 integer values:\n");
for( i=0; i <= 4; i++)
{ scanf("%d",&array[i]);}
printf("\n");
// searching 

 printf("Enter any value to search:\n");
 scanf("%d", &n);
 
  pos=-1;
  
for(i=0; i <= 5; i++)
{ if (n == array[i])

/*if the value to search matches in the array, it will
execute the next block, which is if pos=i, it will break and end 
the program.*/

  { pos = i; //initialized value for print in line 30
    break; 
  }
   
 } 
 if(pos == -1)
    printf("\n\nLocation not found");
 else
    printf("\n\nLocation found at index %d or position %d.\n\n", pos, pos+1); 
    

    printf("Do you want to run the program again? (y/n):\n ");
        scanf(" %c", &choice);
        
} while (choice=='y' || choice=='Y');
printf("\n");

return 0;
}