/*
A simple sorting algorithm that works by building a sortes array one element
at a time. It is considered an "in-place" sorting algorithm, doesnt require
a temporary algorithm.  

for loop and a while
*/

#include<stdio.h>

void insertionSort(int array[], int length);

int main(){
	int a[]={1,6,7,2,4,9,8};
	int length=7;
	
	insertionSort(a, length);
	
	return 0;
}

void insertionSort(int array[], int length){
	
	/*loop starts at index 1 rather than 0 since we assume that the first one
	is already sorted*/
	
	for (int i=1; i<length; i++){
		int key = array[i]; //current value to be inserted 
		int j = i-1; //element before key
		
		while (j>=0 && array[j]>key){
			array[j+1]= array[j]; 	//moves the element one step to the right
			j=j-1;					// moves to the left of array
		}
		
		//place the key after the last smaller element found
		array[j + 1] = key; 
		
		printf("Pass %d: ", i);
        for (int k = 0; k < length; k++) {
            printf("%d ", array[k]);
        }
        printf("\n");
	}
	

}

/*
#include <math.h> 
#include <stdio.h> 

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

// Driver program to test insertion sort 
int main() 
{ 
    //int arr[] = { 12, 11, 13, 5, 6 }; // unorganized
	 int n=0, i, arr [999];1
	 
	 printf("Enter the size of the array: \n");
	 scanf("%2d", &n);
	 
	 printf("\nEnter elements of the array:\n");
	 for(i=0; i<n; i++){
	 	scanf("%d", &arr[i]);
	 }
	 printf("Original content of array:\n");
	 for (i=0; i<n; i++){
	 	printf("|%d|\t\n", arr[i]);
	 }
    
    insertionSort(arr, n); 
    printf("\nContent of array after insertion:\n");
    for (i=0; i<n; i++){
    	printf("\nArray[i] = |%d|\t", arr[i]);
    }
    
    return 0; 

} 

// Function to sort an array using insertion sort

void insertionSort(int arr[], int n) 

{ 
    int i, key, j; 

    for (i = 1; i < n; i++) { 
        key = arr[i]; 
        j = i - 1; 
        //Move elements of arr[0..i-1], that are 
          //greater than key, to one position ahead 
          //of their current position

        while (j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j]; 
            j = j - 1; 
        } 
        arr[j + 1] = key; 
    } 
} 
// A utility function to print an array of size n 
void printArray(int arr[], int n) 
{ 
   int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} */


//InsertionSort as a function
/*
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
*/