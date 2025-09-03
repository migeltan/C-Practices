/* Multi-dimensional array-  defined in much the same manner as 
one-dimensional. Requires two pairs of square brackets.

define:
storage-class data-type anrrayname [expression 1] [expression 2];
1st expression=row
2nd expression=column

2 for loops, 1 for the row, 1 for the column if this is a user-input array

- storage for this always starts with row 0, column 0, then an increase in column
until max, then continue with the next row.

example: row 0, col 0, row 0 col 1, ... , row 2, col 0

*/

#include<stdio.h>

main(void){
	int IT[3][3], row=0, col=0, sumrow[3]={0,0,0}, sumcol[3]={0,0,0}; //initialization
	
	//input: once nakapag-input ka na rito, it will proceed to line 31
	printf("Please enter values of array IT:\n");
	for(row=0; row<3; row++){ //Use  a nested for to execute the array
		for(col=0; col<3; col++){ 
			scanf("%d", &IT[row][col]); //user input
		}
	}
	
	for(row=0; row<3; row++){ //process in solving 
		for(col=0; col<3; col++){
			sumrow[row] += IT [row][col]; /*initialized sumrow, then insert the row in the brackets
			for the iteration process, then it will add to IT [][] respectively. */
			sumcol[col] += IT [row][col]; 
		}
	}
	
	//printing the arrays
	printf("\nContent of array IT:\n");
	for (row=0; row<3; row++){
		for (col=0; col<3; col++){
			printf ("%d\t", IT[row][col]);	
		}
		printf("\n");
	}
	
	printf("\nSUM of rowsIT\n");
	for (row=0; row<3; row++){
		printf("\t%d", sumrow[row]);
	}
	
		printf("\nSUM of colsIT\n");
	for (col=0; col<3; col++){
		printf("\t%d", sumcol[col]);
	}
}
