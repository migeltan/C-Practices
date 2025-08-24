#include <stdio.h>

#define SIZE 5

// Function Prototypes
void bubbleSort(int arr[], int size, int ascending);
void selectionSort(int arr[], int size, int ascending);
int binarySearch(int arr[], int size, int target);
void findMinMax(int arr[], int size);

int main() {
    int N[SIZE], B[SIZE], MERGE_ARRAY[SIZE * 2];
    int merge_size = 0, i, j, found, choice;
    char repeat;

    do {
        // Input arrays
        printf("Enter 5 integers for Array N:\n");
        for (i = 0; i < SIZE; i++) {
            scanf("%d", &N[i]);
        }

        printf("Enter 5 integers for Array B:\n");
        for (i = 0; i < SIZE; i++) {
            scanf("%d", &B[i]);
        }

        // Merging unique elements from N
        for (i = 0; i < SIZE; i++) {
            found = 0;
            for (j = 0; j < merge_size; j++) {
                if (N[i] == MERGE_ARRAY[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                MERGE_ARRAY[merge_size++] = N[i];
            }
        }

        // Merging unique elements from B
        for (i = 0; i < SIZE; i++) {
            found = 0;
            for (j = 0; j < merge_size; j++) {
                if (B[i] == MERGE_ARRAY[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                MERGE_ARRAY[merge_size++] = B[i];
            }
        }

        // Displaying the merged array
        printf("\nMerged Array: ");
        for (i = 0; i < merge_size; i++) {
            printf("|%d| ", MERGE_ARRAY[i]);
        }
        printf("\n");

        // Asking user for next action
        printf("\nChoose an option:\n1. Search\n2. Sort\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) { // Search Option
            int search_choice;
            printf("\nChoose search method:\n1. Linear Search (Find Min & Max)\n2. Binary Search\nEnter choice: ");
            scanf("%d", &search_choice);

            if (search_choice == 1) {
                findMinMax(MERGE_ARRAY, merge_size);
            } else if (search_choice == 2) {
                // Sorting before binary search
                bubbleSort(MERGE_ARRAY, merge_size, 1);

                int target;
                printf("\nEnter number to search: ");
                scanf("%d", &target);

                int position = binarySearch(MERGE_ARRAY, merge_size, target);
                if (position != -1) {
                    printf("\nNumber %d found at index %d.\n", target, position);
                } else {
                    printf("\nNumber %d not found in the array.\n", target);
                }
            } else {
                printf("\nInvalid choice!\n");
            }
        } 
        else if (choice == 2) { // Sort Option
            int sort_choice, order_choice;
            printf("\nChoose sorting method:\n1. Bubble Sort\n2. Selection Sort\nEnter choice: ");
            scanf("%d", &sort_choice);

            printf("\nChoose order:\n1. Ascending\n2. Descending\nEnter choice: ");
            scanf("%d", &order_choice);
            int ascending = (order_choice == 1) ? 1 : 0;

            if (sort_choice == 1) {
                bubbleSort(MERGE_ARRAY, merge_size, ascending);
            } else if (sort_choice == 2) {
                selectionSort(MERGE_ARRAY, merge_size, ascending);
            } else {
                printf("\nInvalid choice!\n");
            }

            // Display sorted array
            printf("\nSorted Array: ");
            for (i = 0; i < merge_size; i++) {
                printf("|%d| ", MERGE_ARRAY[i]);
            }
            printf("\n");
        } 
        else {
            printf("\nInvalid choice!\n");
        }

        // Repeat process?
        printf("\nDo you want to repeat the process? (Y/N): ");
        scanf(" %c", &repeat);
    } while (repeat == 'Y' || repeat == 'y');

    return 0;
}

// Bubble Sort Function
void bubbleSort(int arr[], int size, int ascending) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Selection Sort Function
void selectionSort(int arr[], int size, int ascending) {
    int i, j, minMaxIdx, temp;
    for (i = 0; i < size - 1; i++) {
        minMaxIdx = i;
        for (j = i + 1; j < size; j++) {
            if ((ascending && arr[j] < arr[minMaxIdx]) || (!ascending && arr[j] > arr[minMaxIdx])) {
                minMaxIdx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minMaxIdx];
        arr[minMaxIdx] = temp;
    }
}

// Binary Search Function (assumes sorted array)
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid; // Element found
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // Element not found
}

// Function to find min and max values using linear search
void findMinMax(int arr[], int size) {
    int min = arr[0], max = arr[0], i;
    for (i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    printf("\nMinimum Value: %d\nMaximum Value: %d\n", min, max);
}