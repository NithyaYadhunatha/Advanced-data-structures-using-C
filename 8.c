#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char USN[20];
    char Name[50];
    char Branch[20];
    int Sem;
    char PhNo[15];
    struct Student* next;
} *StudentPtr;

StudentPtr head = NULL;

void createList(int N) {
    for (int i = 0; i < N; i++) {
        StudentPtr newNode = (StudentPtr)malloc(sizeof(struct Student));
        printf("USN Name Branch Sem Phone: ");
        scanf("%s %s %s %d %s", newNode->USN, newNode->Name, newNode->Branch, &newNode->Sem, newNode->PhNo);
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            StudentPtr temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

void displayList() {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    StudentPtr temp = head;
    while (temp != NULL) {
        printf("%s %s %s %d %s\n", temp->USN, temp->Name, temp->Branch, temp->Sem, temp->PhNo);
        temp = temp->next;
    }
    printf("Nodes: %d\n", countNodes());
}

void insertAtEnd() {
    StudentPtr newNode = (StudentPtr)malloc(sizeof(struct Student));
    printf("USN Name Branch Sem Phone: ");
    scanf("%s %s %s %d %s", newNode->USN, newNode->Name, newNode->Branch, &newNode->Sem, newNode->PhNo);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        StudentPtr temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    StudentPtr temp = head;
    StudentPtr prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

void insertAtFront() {
    StudentPtr newNode = (StudentPtr)malloc(sizeof(struct Student));
    printf("USN Name Branch Sem Phone: ");
    scanf("%s %s %s %d %s", newNode->USN, newNode->Name, newNode->Branch, &newNode->Sem, newNode->PhNo);
    newNode->next = head;
    head = newNode;
}

void deleteAtFront() {
    if (head == NULL) {
        printf("Empty\n");
        return;
    }
    StudentPtr temp = head;
    head = head->next;
    free(temp);
}

int countNodes() {
    int count = 0;
    StudentPtr temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int choice, N;
    while (1) {
        printf("\n1.Create 2.Display 3.Insert End 4.Delete End 5.Insert Front 6.Delete Front 7.Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Num students: ");
                scanf("%d", &N);
                createList(N);
                break;
            case 2:
                displayList();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                deleteAtEnd();
                break;
            case 5:
                insertAtFront();
                break;
            case 6:
                deleteAtFront();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid\n");
        }
    }
    return 0;
}
