#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    char USN[10];
    char Name[20];
    char Branch[10];
    int Sem;
    char PhNo[10];
    struct Student* next;
} Student;

Student* head = NULL;

Student* createNode() {
    Student* newNode = (Student*)malloc(sizeof(Student));
    printf("Enter the details of the student:\n");
    printf("Enter the USN: ");
    scanf("%s", newNode->USN);
    printf("Enter the Name: ");
    scanf("%s", newNode->Name);
    printf("Enter the Branch: ");
    scanf("%s", newNode->Branch);
    printf("Enter the Sem: ");
    scanf("%d", &newNode->Sem);
    printf("Enter the Phone number: ");
    scanf("%s", newNode->PhNo);
    newNode->next = NULL;
    return newNode;
}

void insertFront(Student* newNode) {
    newNode->next = head;
    head = newNode;
}

void deleteFront() {
    if (head == NULL) {
        printf("The Single Linked List is Empty\n");
    } else {
        Student* temp = head;
        head = head->next;
        free(temp);
        printf("Node is deleted from the front\n");
    }
}

void insertEnd(Student* newNode) {
    if (head == NULL) {
        head = newNode;
    } else {
        Student* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteEnd() {
    if (head == NULL) {
        printf("The Single Linked List is Empty\n");
    } else if (head->next == NULL) {  // Only one node
        free(head);
        head = NULL;
    } else {
        Student* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void displayAndCount() {
    if (head == NULL) {
        printf("The Single Linked List is Empty\n");
        return;
    }
    Student* temp = head;
    int count = 0;
    printf("Details of students in the list:\n");
    while (temp != NULL) {
        printf("USN: %s, Name: %s, Branch: %s, Sem: %d, Phone: %s\n",
               temp->USN, temp->Name, temp->Branch, temp->Sem, temp->PhNo);
        temp = temp->next;
        count++;
    }
    printf("Total number of nodes: %d\n", count);
}

int main() {
    int choice;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at Front\n");
        printf("2. Delete from Front\n");
        printf("3. Insert at End\n");
        printf("4. Delete from End\n");
        printf("5. Display and Count\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertFront(createNode());
                break;
            case 2:
                deleteFront();
                break;
            case 3:
                insertEnd(createNode());
                break;
            case 4:
                deleteEnd();
                break;
            case 5:
                displayAndCount();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
