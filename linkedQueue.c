#include <stdio.h>
#include <stdlib.h>

struct Node {
    char usn[20], name[10], branch[5];
    unsigned long long int phno;
    int sem;
    struct Node *next;
};

typedef struct Node *NODE;
NODE temp, front = NULL, rear = NULL;

void insert();
void delete();
void display();

void main() {
    int choice;
    printf("\nQueue Implementation using Linked List\n");
    while (1) {
        printf("\n****** MENU ******\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nWrong selection!!! Please try again!!!\n");
        }
    }
}

void insert() {
    NODE newNode;
    newNode = (NODE)malloc(sizeof(struct Node));
    
    printf("Enter USN: ");
    scanf("%s", newNode->usn);
    printf("Enter NAME: ");
    scanf("%s", newNode->name);
    printf("Enter Branch: ");
    scanf("%s", newNode->branch);
    printf("Enter Phone Number: ");
    scanf("%llu", &newNode->phno);
    printf("Enter Semester: ");
    scanf("%d", &newNode->sem);
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
        front->next = NULL;
        rear->next = NULL;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = NULL;
    }
    printf("\nInsertion is Success!!!\n");
}

void delete() {
    if (front == NULL) {
        printf("\nQueue is Underflow!!!\n");
    } else {
        temp = front;
        front = front->next;
        printf("\nDeleted node is with USN: %s\n", temp->usn);
        free(temp);
    }
}

void display() {
    if (front == NULL) {
        printf("\nQueue is Empty!!!\n");
    } else {
        temp = front;
        while (temp != NULL) {
            printf("\nThe Student information in the node is:\n");
            printf("USN: %s\nNAME: %s\nBRANCH: %s\nPHONE NO.: %llu\nSEM: %d\n", 
                   temp->usn, temp->name, temp->branch, temp->phno, temp->sem);
            temp = temp->next;
        }
    }
}
