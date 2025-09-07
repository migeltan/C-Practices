//Contains functions, call by reference, call by value, predefined functions

//Call by reference

//ChatGPT Quiz Functions with multidimensional array
 //Ask the user to input values for a 2x3 matrix (2 rows, 3 columns). 
 //Then, use a function to calculate and display the sum of all elements.
 
#include <stdio.h>

void addfunct(int addition[2][3]);

 int main(){

 	int twothree[2][3]; int i, j;
 	
 	printf("Enter the values to be added: \n");
 	printf("\n");
 	
for (int i = 0; i < 2; i++) {
	for (int j = 0; j < 3; j++) {
		printf("Element [%d][%d]: ", i, j);
		scanf("%d", &twothree[i][j]);
	}
}
	 
	 addfunct(twothree);

 }
void addfunct(const int addition[2][3]){
	int row, col;
	int sum=0;
	
	for (row=0; row<2; row++){
		for (col=0; col<3; col++){
			sum+=addition[row][col];
		}
	}
	printf("\nTotal sum of all input: %d\n", sum);
}


/*ChatGPT Quiz CBR maxmin arrays

Write a program that asks the user to enter 5 numbers. 
Then, using a function and call by reference, find the maximum and minimum
 number and store them in variables in main()
 
#include <stdio.h>

void findMaxMin(int arr[], int size, int *max, int *min);

int main() {
    int nums[5];
    int max, min;

    for (int i = 0; i < 5; i++) {
    	printf("Enter 5 numbers (#%d): ", i+1);
        scanf("%d", &nums[i]);
    }

    findMaxMin(nums, 5, &max, &min);

    printf("\nMaximum: %d\n", max);
    printf("Minimum: %d\n", min);

    return 0;
}

void findMaxMin(int arr[], int size, int *max, int *min) {

    
    int i=0;
    *max=arr[0];
    *min=arr[0];
    
    for (i=0; i<size; i++){
    	if (arr[i]>*max) *max=arr[i]; 
		if (arr[i]<*min) *min=arr[i];   
	}
	
} */



/* ChatGPT Quiz CBR with arrays
Ask the user to enter 5 numbers. Then use a function that doubles 
each number in the array using pointers (call by reference).

#include<stdio.h>

void doublefunct(int array[]);

int main(){
	
	int input[5];
	
	for (int i=0; i<5; i++){
		printf("Enter 5 numbers (#%d): ", i+1);
		scanf("%d", &input[i]);
	}
	
	doublefunct(input);

}

void doublefunct(int array[]){
	int i;
	int res=0;
	printf("\n");
	for (i=0; i<5; i++){
		res=array[i]*2;
		printf("The answers are (#%d): %d\n", i+1, res);
	}
}*/

/* CHatGPT Quiz CBR
Write a program that asks the user for two numbers, 
and then swaps their values using a function. 
The swap function should use call by reference.

#include<stdio.h>

void swap(int *m, int *t);

int main(){
	int a, b;
	
	printf("First number: ");
	scanf("%d", &a);
	printf("Second number: ");
	scanf("%d", &b);
	
	swap(&a, &b);
}

void swap(int *m, int *t){
	
	//printf("Before swap: %d %d\n", *m, *t);
	
//	printf("After swap: %d %d", *t, *m);
	
	printf("Before swap: %d %d\n", *m, *t);
	
	int same = *m; //same being a temporary variable
	*m=*t;
	*t=same;
	
	printf("After swap: %d %d\n", *m, *t);
	

} */


/* CBR
#include<stdio.h>

int change(int *x, int *y);

int main(){
	
	int a=10; int b=20;
	
	printf("Before: %d %d\n", a, b); 
			//act parameters
	change(&a, &b);
	
	return 0;
}
			//formal parameters
int change(int *x, int *y){
	
	printf("Inside: %d %d\n", *x, *y);
	*x= *x+10;
	*y=*y+10;
	printf("After: %d %d\n", *x, *y);
	
	return *x, *y;
} */

/*	Sample 1 (Basic function) CBR 

#include<stdio.h>

int multfive(int *x);

int main(){
	
	int num;
	
	printf("Enter a number to be multiplied: ");
	scanf("%d", &num);
	
	multfive(&num);
	
}

int multfive(int *x){
	
	*x*=5;
	printf("Number after: %d", *x);
	
	return *x;
}*/

//Call by value

/* Sample 2 Basic funct CBV
#include<stdio.h>

int add(int a, int b);

int main (){
	
	int input1, input2;
	
	printf("Enter two numbers: ");
	scanf("%d %d", &input1, &input2);
	
	add(input1, input2);
}

int add(int a, int b){
	
	int sum;
	
	sum= a+b;
	
	printf ("Result: %d", sum);
	
	return sum;
}*/

//Predefined funct

/* Funct 3 Predefined

#include<stdio.h>
#include<math.h>

int main(){
	float input;
	
	printf("Enter a decimal: ");
	scanf("%f", &input);
	
	printf("Floored value is: %f", floor(input));
	
	
}*/