#include <stdio.h>

void bubbleSort(int a[], int n);  // Function prototype for bubble sort
int binarySearch(int a[], int n, int key);  // Function prototype for binary search

int main() {
    int i, low, high, mid, n, key;
    int array[100];  // Array to store the integers
    
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);  // Input the number of elements
    
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);  // Input the array elements
    }
    
    // Sort the array using bubble sort
    bubbleSort(array, n);
    
    printf("Elements after sorting are: ");
    for (i = 0; i < n; i++) {
        printf("%3d ", array[i]);  // Display sorted array
    }
    printf("\n");

    // Ask for the key to search
    printf("Enter value to find: ");
    scanf("%d", &key);
    
    // Perform binary search
    int result = binarySearch(array, n, key);
    
    if (result == -1) {
        printf("%d is not present in the list.\n", key);
    } else {
        printf("%d found at position %d.\n", key, result + 1);  // Print 1-based index
    }

    return 0;
}

// Bubble Sort function to sort the array in ascending order
void bubbleSort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap elements if they are in the wrong order
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Binary Search function to find the element in the sorted array
int binarySearch(int a[], int n, int key) {
    int low = 0, high = n - 1, mid;
    
    while (low <= high) {
        mid = (low + high) / 2;
        
        if (a[mid] == key) {
            return mid;  // Key found, return index
        } else if (a[mid] < key) {
            low = mid + 1;  // Key is on the right side
        } else {
            high = mid - 1;  // Key is on the left side
        }
    }
    
    return -1;  // Key not found
}
