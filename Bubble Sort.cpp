/*
Comparison based simple sorting algorithm, works by comparing them
and swapping them if the elements are unsorted
Time complexity o(n^2)
nested for, one for the index and the other for the value, then an if 
statement for the swap.
*/

#include <stdio.h>
#include <stdbool.h>

//For sorting integers
void bubbleSort(int a[], int length);

int main(){
	
	int length; int array[999];
	
	printf("Enter the length of array: ");
	scanf("%d", &length);
	
	printf("\nEnter the arrays:\n");
	for (int i=0; i<length; i++){
		printf("#%d: ",i+1);
		scanf("%d", &array[i]);
	}
	
 bubbleSort(array, length);	
	
	
	return 0;
}

void bubbleSort(int a[], int length){

	//Control passes
	for (int i=0; i<length; i++){
		//Compares the elements then does swaps if needed
		for (int j=0; j<(length-i-1); j++)
		/*reason why may -1 kasi
		sa first loop pa lang, naka-lagay na yung biggest 
		digit sa last placement, so per sort nag-minus 1 siya dahil
		sorted na ang last from the firs loop pa lang.*/
		
		{
			if (a[j]>a[j+1]) //Change operator for ascending/descending
			/* if a[j] is bigger than the next
			value, it will do a swap, if no, it will stay there
			until the next loop happens.*/
			
			{
				
				//swap happens
				int temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
		
			}
		}
	}

	printf("\n");
	for (int i=0; i<length; i++)//for printing obvi
	{
		printf("Sorted[%d]= %d\n", i+1, a[i]);
	}
}

/*
//Sorting char
#include <stdio.h>

void bubbleSortChar(char a[], int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                char temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Print the sorted characters
    printf("Sorted characters: ");
    for (int i = 0; i < length; i++) {
        printf("%c ", a[i]);
    }
    printf("\n");
}

int main() {
    char letters[] = {'d', 'a', 'c', 'b', 'e'};
    int length = sizeof(letters) / sizeof(letters[0]);

    bubbleSortChar(letters, length);

    return 0;
}

*/

//BubbleSort as function
/*
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
*/