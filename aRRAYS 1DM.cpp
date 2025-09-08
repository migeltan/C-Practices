/*	One Dimensional array- a row that can handle a set of data.
- Array declaration and array definition 
- General format
*/

#include<stdio.h>

	
	int BSIT[10]; //with user input
	//int BSIT[10] = {122331,2,3425,4,52322,6,3293,8,12331,10}; //if u want no input
	//int BSIT[10] = {1,2,3,4,5,6,7,8,9,10}; //check for few inputs
	//int counter =0;
	int sum=0;
	
	//function declaration
	int EVEN();
	void DISPLAY (int BSIT[]);

main (void){
EVEN (); //returns an int
DISPLAY (BSIT); //will print BSIT input
sum= printf("\n\n The sum of even index BSIT = %d", sum); //simply adds the even input
}

int EVEN(){ //function for displaying
	for (int counter=0; counter<=9; counter++)
	{
		//user validation
		printf ("\n Please enter any non-negative number (Max of 10) Index %d is: ", counter);
		scanf("%d", &BSIT[counter]); //takes user-input
		if((counter % 2)==0){ //checks if even ang input
			sum+=BSIT[counter];
			
		} else {
			continue;
		}
		
	}
	return (sum); //when function is called, it will return line 32
}

	void DISPLAY (int BSIT[]){  //prints the user input
	// then it will print the data per iteration of the index
		printf("\n Content of array BSIT:\n");
		for (int counter=0; counter <=9; counter++)
		{
			printf("\n|%d|", BSIT[counter]);
		}
	}

