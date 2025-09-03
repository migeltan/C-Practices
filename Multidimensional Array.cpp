/* 2-Dimensional Array - has 2 indexes, is represented in the form of
rows and columns, like a matrix.
- other dimensional arrays are called multidimensional 
*/
Declaration:
int matrix [2] [2]; 
int matrix [2] [2] = {2,3,5,6};

#include<stdio.h>
int main()
{
	int matrix [2][2], i, j;
	printf("Enter the Matrix elements:\n");
	for (i=0; i<=1; i++)
	{
		for (j=0; j<=1; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("Matrix elements:\n");
	
	for (i=0; i<=1; i++)
	{
		for (j=0; j<=1; j++){
			printf("|%d|", matrix[i][j]);
			
		}
		printf("\n");
}
}


