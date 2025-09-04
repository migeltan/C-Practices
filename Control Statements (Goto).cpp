/* Control Statements:
1. Jump Statements- branching statements, control to another part of the program.
goto, break, continue 

#include<stdio.h>
int main ()
{
	int num;
	printf("Enter a number to check\n\n");
	scanf("%d", &num);
	
	if (num<0)
	goto a;
	
	else
	goto b;
	
	a: {
	printf("Negative number.");
	goto end;
	}
	
	b:{
		printf("Positive number.");
	}
	
	end:{
		
	}
}

*/

/* 2. Nested if statement */

#include <stdio.h>

int main() {
    int num;
    printf("Enter a number to check its value and if it's odd/even:\n");
    scanf("%d", &num);

    if (num > 0) { /*Checks if the statement is positive, the use a nested if-else to 
    further check if it is odd/even */
        if (num % 2 == 0) {
            printf("Your number is positive and even.");
        } else {
            printf("Your number is positive and odd.");
        }
    } else if (num < 0) { // Checks if its negative, then if-else for odd. 
        if (num % 2 == 0) {
            printf("Your number is negative and even.");
        } else {
            printf("Your number is negative and odd.");
        }
    } else { 
        printf("Your number is zero and even.");
    }

    return 0;
}



			



	