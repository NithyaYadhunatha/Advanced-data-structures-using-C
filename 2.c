#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct {
    char name[20];
    int bal;
    int accNo;
} C;

// Function to display customers with balance below 200
void lowbal(C cust[], int count) {
    for(int i = 0; i < count; i++) {
        if(cust[i].bal < 200) {
            printf("%s \n", cust[i].name);
        }
    }
}

// Function to increase balance of customers with balance greater than 1000
void highbal(C cust[], int count) {
    for(int i = 0; i < count; i++) {
        if(cust[i].bal > 1000) {
            cust[i].bal += 100;
            printf("%d %d\n", cust[i].accNo, cust[i].bal);  
        }
    }
}

int main() {
    int i, n;
    C cust[Max];
    
    // Read number of customers
    scanf("%d", &n);

    // Read customer details
    for(i = 0; i < n; i++) {
        printf("Enter the details of Customer %d\n", i + 1);
        scanf("%s", cust[i].name);  
        scanf("%d", &cust[i].accNo);
        scanf("%d", &cust[i].bal);
    }

    // Display customers with low balance
    lowbal(cust, n);

    // Update and display customers with high balance
    highbal(cust, n);

    return 0;
}
