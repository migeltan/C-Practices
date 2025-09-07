//Contains arrays, functions, arrays in function, 2/multidimensional arrays


/*ChatGPT Quiz:

Write a C program that:

Asks the user to enter the size of an array (up to 100).

Takes n integer inputs from the user and stores them in an array.

Uses a function called findMax() that takes the array and its size as arguments and returns the maximum element.

Prints the maximum number found.*/

#include<stdio.h>

int findMax(int arr[], int size){
	int i, max=arr[0]; 
	for (i=1; i<size; i++){ //executes until the max index
		if (arr[i]>max) max=arr[i]; //updates the value of arr[i] per loop.
	}								/*Lets say na sa 1st loop, 22 ung value, itll be the new value of
	arr[i], then itll check if its greater than max, which has 0 as its array, then executes the 
	next, which will initialize max as the arr[i], so 22 na si max. Mag-uupdate lang siya nang
	mag-uupdate based sa loop, so lets say 44 ang next value ng input from the size index, 
	it will execute the if statement and check if the new arr[i], which is 44, is greater than the max
	which was 22. If true, then execute, and continue as the new initialization of max. */
	
	printf("\nThe maximum number is: %d", max);
	
	return max;
}

main (void){
	int size, i;
	int number[100];
	
	printf("\nEnter the array size: ");
	scanf("%d", &size);
	
	for (i=0;i<size; i++){
		printf("\nEnter the #%d array: ", i+1);
		scanf("%d", &number[i]);
	}
	
	findMax(number, size);
	
	return 0;
} 

/*
//Array problem in book, no.2
#include<stdio.h>

int main(){
	int a, b=0;
	static int c[10]={1,2,3,4,5,6,7,8,9,10};
	
	for(a=0; a<10; a++){
		if ((c[a]%2)==0)
		b+=c[a];
	}
	
	printf("%d", b);
	
	return 0;
}*/

/*ChatGPT Quiz

Problem: Count Even and Odd Numbers in an Array
Description:

Write a C program that:

Asks the user to input the number of elements in an array.

Takes that many numbers from the user.

Uses two separate functions:

countEven() to count how many even numbers are in the array.

countOdd() to count how many odd numbers are in the array.

Prints the number of even and odd values.

Enter the size of the array: 6
Enter 6 numbers:
5
12
7
4
9
10
Even numbers: 3
Odd numbers: 3 

#include <stdio.h>

int countEven(int num[], int size);
int countOdd(int num[], int size);

int main(){
	
	int size, i;
	int numbers[100];
	
	printf("Enter the size of array: ");
	scanf("%d", &size);
	
	for (i=0; i<size; i++){
	printf("\nEnter the %d numbers (#%d): ", size, i+1);
	scanf("%d", &numbers[i]);	
	}
	
	int evenCount=countEven(numbers, size);
	int oddCount=countOdd(numbers, size);
	
	printf("\n\nThe count of Even numbers: |%d|\n", evenCount);
	printf("\nThe count of Odd numbers: |%d|\n", oddCount);
	
	return 0;

}

int countEven(int num[], int size){
	int i;
	int even=0;
	
	printf("\n\nEven numbers:\n");
	
	
	for (i=0; i<size; i++){
		if ((num[i]%2)==0) {
			printf("|%d|\t", num[i]);
			even++;
		}
	}
	return even;
}

int countOdd(int num[], int size){
	int i, odd=0;
	
	printf("\n\nOdd numbers:\n");
	
	for (i=0; i<size; i++){
		if ((num[i]%2)!=0){
			printf("|%d|\t", num[i]);
			odd++;
		}
	}
	return odd;
} */

/* #include <stdio.h>

int countEven(int arr[][10], int rows, int cols);
int countOdd(int arr[][10], int rows, int cols);

int main() {
    int arr[10][10], rows, cols, i, j;

    printf("Enter rows: ");
    scanf("%d", &rows);
    printf("Enter columns: ");
    scanf("%d", &cols);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }

    int even = countEven(arr, rows, cols);
    int odd = countOdd(arr, rows, cols);

    printf("\nEven numbers: %d", even);
    printf("\nOdd numbers: %d", odd);

    return 0;
}

int countEven(int arr[][10], int rows, int cols) {
    int i, j, count = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] % 2 == 0)
                count++;
        }
    }
    return count;
}

int countOdd(int arr[][10], int rows, int cols) {
    int i, j, count = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (arr[i][j] % 2 != 0)
                count++;
        }
    }
    return count;
}*/


