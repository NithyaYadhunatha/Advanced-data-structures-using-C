#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} *NodePtr;

NodePtr createNode(int coeff, int exp) {
    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(NodePtr* poly, int coeff, int exp) {
    NodePtr newNode = createNode(coeff, exp);
    if (*poly == NULL) {
        newNode->next = newNode;
        *poly = newNode;
    } else {
        NodePtr temp = *poly;
        while (temp->next != *poly)
            temp = temp->next;
        newNode->next = *poly;
        temp->next = newNode;
    }
}

void printPolynomial(NodePtr poly) {
    if (poly == NULL) {
        printf("Empty polynomial\n");
        return;
    }
    NodePtr temp = poly;
    do {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != poly) printf(" + ");
    } while (temp != poly);
    printf("\n");
}

NodePtr addPolynomials(NodePtr poly1, NodePtr poly2) {
    NodePtr result = NULL;
    NodePtr temp1 = poly1;
    NodePtr temp2 = poly2;
    
    do {
        if (temp1->exp == temp2->exp) {
            insertTerm(&result, temp1->coeff + temp2->coeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if (temp1->exp > temp2->exp) {
            insertTerm(&result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        }
        else {
            insertTerm(&result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    } while (temp1 != poly1 && temp2 != poly2);
    
    return result;
}

int main() {
    NodePtr poly1 = NULL;
    NodePtr poly2 = NULL;

    insertTerm(&poly1, 5, 3);
    insertTerm(&poly1, 4, 2);
    insertTerm(&poly1, 2, 0);

    insertTerm(&poly2, 3, 2);
    insertTerm(&poly2, 6, 1);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);
    printf("Polynomial 2: ");
    printPolynomial(poly2);
    printf("Sum: ");
    printPolynomial(addPolynomials(poly1, poly2));

    return 0;
}
