/* while loops - executes a set of atatements repeatedly until the given
conditions remain true.
- given condition is checked first and and then program control executes
the block of code only if the condition evaluates to true.

while(condition){
statements;
} */

/*#include<stdio.h>
int main()
{
	int a=1;
	while(a<=9){
		printf("Hi\n");
		printf("The value of a= %d\n", a);
		a++;
	}ppp
	while(a<=20){
		
		if (a%2 == 0){
		printf("%d\n", a);	
		}
		a++;
} */

 //for loops 1-20 even numbers
#include<stdio.h>
int main()
{
	for (int i=2; i<=20; i += 2){
		printf("%d\n", i);
	}
} 
	

#include<stdio.h> //while loop 1-10 sum
int main()
{
	int a=1, sum=0;
	
	while (a<=10){
		sum+=a;
	a++;
	}
	printf("%d\n", sum);
} 


#include<stdio.h> // do while loop 10-1 order
int main() {
   int a=10;
   
   do{
   	printf("%d\n", a--);
   } while (a>=1); 
   
}

#include<stdio.h> //sum of 5 arrays
int main()
{
	int arr[] = {1,2,3,4,5};
	int total=0;
	
	for(int i=0; i<5; i++){
		total = total + arr[i];	
	}
	printf("Sum of all arrays is: %d", total);
	return 0;
	
}

#include<stdio.h> //reverse order
int main()
{
	int arr[] = {1,2,3,4,5};
	
	for(int i=4; i>=0; i--)
	{
	
		printf("%d\n", arr[i]);
	}
}

 #include<stdio.h> // Largest value in an array
int main()
{
    int arr[5]; // Declare an array of size 5
    int largest;

    // Input 5 values
    printf("Input 5 values:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize largest with the first element
    largest = arr[0];

    // Find the largest value
    for (int i = 1; i < 5; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    // Print the largest value
    printf("The largest value is: %d\n", largest);

    return 0;
}

#include<stdio.h> //factorial

int factorial(int n);

int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, factorial(num));
    return 0;
}


