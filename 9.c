#include <stdio.h>
#include <stdlib.h>

typedef struct Employee {
    char ssn[20];
    char name[50];
    char dept[20];
    char designation[20];
    float sal;
    char phno[15];
    struct Employee *prev;
    struct Employee *next;
} *EmpPtr;

EmpPtr head = NULL;
EmpPtr tail = NULL;

void createList(int N) {
    for(int i = 0; i < N; i++) {
        EmpPtr newNode = (EmpPtr)malloc(sizeof(struct Employee));
        printf("Enter SSN, Name, Dept, Designation, Salary, Phone: ");
        scanf("%s %s %s %s %f %s", newNode->ssn, newNode->name, newNode->dept, 
              newNode->designation, &newNode->sal, newNode->phno);
        newNode->next = NULL;
        newNode->prev = tail;
        if(head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }
}

void display() {
    if(head == NULL) {
        printf("List Empty\n");
        return;
    }
    EmpPtr temp = head;
    int count = 0;
    while(temp != NULL) {
        printf("%s %s %s %s %.2f %s\n", temp->ssn, temp->name, temp->dept, 
               temp->designation, temp->sal, temp->phno);
        temp = temp->next;
        count++;
    }
    printf("Node count: %d\n", count);
}

void insertEnd() {
    EmpPtr newNode = (EmpPtr)malloc(sizeof(struct Employee));
    printf("Enter SSN, Name, Dept, Designation, Salary, Phone: ");
    scanf("%s %s %s %s %f %s", newNode->ssn, newNode->name, newNode->dept, 
          newNode->designation, &newNode->sal, newNode->phno);
    newNode->next = NULL;
    newNode->prev = tail;
    if(head == NULL) {
        head = newNode;
    } else {
        tail->next = newNode;
    }
    tail = newNode;
}

void deleteEnd() {
    if(head == NULL) {
        printf("List Empty\n");
        return;
    }
    EmpPtr temp = tail;
    if(head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    free(temp);
}

void insertFront() {
    EmpPtr newNode = (EmpPtr)malloc(sizeof(struct Employee));
    printf("Enter SSN, Name, Dept, Designation, Salary, Phone: ");
    scanf("%s %s %s %s %f %s", newNode->ssn, newNode->name, newNode->dept, 
          newNode->designation, &newNode->sal, newNode->phno);
    newNode->prev = NULL;
    newNode->next = head;
    if(head == NULL) {
        head = newNode;
    } else {
        head->prev = newNode;
    }
    head = newNode;
}

void deleteFront() {
    if(head == NULL) {
        printf("List Empty\n");
        return;
    }
    EmpPtr temp = head;
    if(head == tail) {
        head = NULL;
        tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    free(temp);
}

int main() {
    int choice, N;
    while(1) {
        printf("\nDLL Operations:\n");
        printf("1.Create\n2.Display\n3.Insert End\n4.Delete End\n");
        printf("5.Insert Front\n6.Delete Front\n7.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter number of employees: ");
                scanf("%d", &N);
                createList(N);
                break;
            case 2:
                display();
                break;
            case 3:
                insertEnd();
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                insertFront();
                break;
            case 6:
                deleteFront();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
