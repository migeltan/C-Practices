/*If the requirements ask for using binary search on an 
unsorted array, then it needs to be sorted first before 
using the binary search algorithm on it. 
For doing so, you can make use of some sorting technique, 
such as the bubble sort or the merge sort. 

NOTE: - The code mentioned below assumes that the input numbers
 follow an ascending order! 
 
 o(logn)
 */
 
 /* 
 Syntax:
 
 Data being the value to be searched. a[mid] being the middlepoint
 for finding if the value is greater than or less than mid.
  
 Case 1 - data == a[mid] 
 Case 2 - data < a[mid]
 Case 3 - data > a[mid]
 
 left- mid+1 (happens if data>a[mid], right remains as it is)
 right- mid -1 (happens if data<a[mid], left remains as it is)
 mid - (left+right)/2
  */

#include <stdio.h>

void binarySearch(int array[], int size, int search){
	int left=0; int right=size-1; int mid=0;
	int found=0;
	
	//for (int i=0; i<size; i++){
	
	while (left<=right){
		mid=(left+right)/2; //the mid computation, do it inside the loop.
		
		
		if (search==array[mid]){
			
		printf("\nValue is at index, #%d. Or in position #%d.", mid, mid+1);
			found=1; //if nahanap ang index, return a true value
			break; //if nahanap na, hindi na mag-eexecute yung loop
			
		} else if (search<array[mid]){	
			right=mid-1;
			
		} else{
			left=mid+1;
			
		} 
	} 
	
	if (!found){
		printf("\nNot found.");
	}
	
}
	
int main(){
	
	int size, search; int array[999];
	
	printf("Enter the size of array: ");
	scanf("%d", &size);
	
	printf("\nEnter the values: \n");
	for (int i=0; i<size; i++){
		scanf("%d", &array[i]);
	}
	
	printf("\nEnter the value to be searched: ");
	scanf("%d", &search);
	
	binarySearch(array, size, search);
	
	return 0;}	



/*#include <stdio.h>

int main() { 


    int c, first, last, middle, n, search, array[100]; char choice; 
    
do{
    printf("Enter number of elements:\n"); 
    scanf("%d", &n);  

    printf("Enter %d integers:\n", n); 
    for (c = 0; c < n; c++) 
        scanf("%d", &array[c]);  

	//reorder, use a function for sorting.

    printf("Enter the value to find:\n"); 
    scanf("%d", &search); 
    first = 0; //index 0
    last = n - 1; //last index
    middle = (int)(first + last) / 2;  //to find the middle index
    
    while (first <= last) //value na ito hindi na index,
    //search happens here, this executes when the first value
    //is less than the last, so obviously it is in a sorted
    //array, so this executes the whole search.
	
	{ 
        if (array[middle] < search) //since mas mababa ung mid, it will 
		//do a plus 1 sa index making it the new left/first/lowest value.
		 
            first = middle + 1;   
        else if (array[middle] == search) // as it is, meaning mid na pala 
		//yung sinesearch
		{ 
            printf("%d is present at index %d.\n", search, middle + 1); 
            break; 
        } 
        else 
            last = middle - 1; //for finding the right/last/highest value.
            //mid-1 meaning the middle index subtract by 1 will be the new 
            //right value.
            
        middle = (first + last) / 2;  //therefore, in finding the middle,
        //you just add the left and right then u have ur new midpoint.
    } 

    if (first > last)  //this is the stopping condition, because if the
    //left index will be greater than the right, it means na hindi
    //present ang sinesearch ng user.
        printf("Not found! %d is not present in the list.\n", search); 
        
         printf("Do you want to run the program again? (y/n):\n ");
        scanf(" %c", &choice);
        
    } while (choice=='y' || choice =='Y');

    return 0;   
}

*/
