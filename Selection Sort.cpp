/*
An assaulting algorithm that works by finding the smallest number from
 the array and then placing it to the first position. the next array 
 that is to be traversed will start from index next to the position where 
 the smallest number is placed. 
 
 uses nested for loop and some if statements to declare a variable for the
 swap.
*/

#include<stdio.h>

void selectionSort(int array[], int length);

int main(){
	int a[]= {5,3,2,1,4,8,10,9,7,6};
	int length=10;

selectionSort(a, 10);
return 0;
}

void selectionSort(int array[], int length){
	
	//outer loop goes through each element one by one
	/*Length-1 since the selection sort sees the smallest element and stoes
	it in index 0, then moves until we have the second to the last pass, so
	the last element is already at place since it would have been the
	largest element in the array.*/
	
	for (int i=0; i<length-1; i++){
		
		int minpos=i; //assumes the current index has minimum value
		
		//find the index of the minimum number and swap it to the current number.
		for (int j=i+1; j<length; j++){
			
			//if a smaller element is found, it remembers the index through this:
			if (array[j]<array[minpos]) minpos=j;
			
			//after finding the smallest element, swap it with the current position.
			if (minpos != i){
				
				//swap happens if needed
				int temp = array[i];
				array[i]=array[minpos];
				array[minpos]=temp;
			}
		}
	}
	
	for (int i=0; i <length; i++){
		printf("array[%d] = %d\n", i, array[i]);
	}
}


/* Swapping

#include <stdio.h>  

void swap(int* xp, int* yp) {  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

void selectionSort(int arr[], int n) {  
    int i, j, min_idx;  

    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n - 1; i++) {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i + 1; j < n; j++)  
            if (arr[j] < arr[min_idx])  
                min_idx = j;  

        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  

/* Function to print an array 
void printArray(int arr[], int size) {  
    int i;  
    for (i = 0; i < size; i++)  
        printf("%d ", arr[i]);  
    printf("\n");  
}  

// Driver program to test above functions  
int main() {  
    int arr[] = { 64, 25, 12, 22, 11 };  
    int n = sizeof(arr) / sizeof(arr[0]);  

    selectionSort(arr, n);  

    printf("Sorted array: \n");  
    printArray(arr, n);  

    return 0;  
}  */

/* //Maam Rosita

#include<stdio.h>
#include<conio.h>

#define p printf

int main() {
   
   int arr[999], n=0;
   int i, j, position, swap;
   p("Please enter size of array:\n");
   scanf("%d",&n); 
   
   printf("\nPlease enter the %d elements of the array:\n", n);
   for(i=0; i < n; i++)
   { printf("#%d: ",i+1);
     scanf("%d", &arr[i]); }
     
   // SELECTION SORT
   for (i = 0; i < (n - 1); i++) {
      position = i;
      // looking for the minimum element
	  for (j = i + 1; j < n; j++)
	  {
         if (arr[position] > arr[j])
            position = j;
      }
     // swapping  
	  if (position != i) 
	  {
         swap = arr[i];
         arr[i] = arr[position];
         arr[position] = swap;
      }
      
   }
   printf("\nAscending order: ");
   for (i = 0; i < n; i++)
      printf("|%d|\t", arr[i]);
   return 0;
}
*/

//InsertionSort as Function
/*
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }
        // Swap
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
*/





