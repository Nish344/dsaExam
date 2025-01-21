#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Employee structure
typedef struct Employee {
    char SSN[15];
    char Name[50];
    char Dept[20];
    char Designation[30];
    char PhNo[15];
    float Sal;
    struct Employee* next;
    struct Employee* prev;
} Employee;

Employee* head = NULL;

// Function to create a new employee node
Employee* createNode() {
    Employee* newNode = (Employee*)malloc(sizeof(Employee));
    printf("Enter the details of the employee:\n");
    printf("SSN: ");
    scanf("%s", newNode->SSN);
    printf("Name: ");
    scanf("%s", newNode->Name);
    printf("Department: ");
    scanf("%s", newNode->Dept);
    printf("Designation: ");
    scanf("%s", newNode->Designation);
    printf("Salary: ");
    scanf("%f", &newNode->Sal);
    printf("Phone Number: ");
    scanf("%s", newNode->PhNo);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insert at the front of the list
void insertFront(Employee* newNode) {
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

// Delete from the front of the list
void deleteFront() {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        Employee* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("Node deleted from the front.\n");
    }
}

// Insert at the end of the list
void insertEnd(Employee* newNode) {
    if (head == NULL) {
        head = newNode;
    } else {
        Employee* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Delete from the end of the list
void deleteEnd() {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        Employee* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
    }
    printf("Node deleted from the end.\n");
}

// Display the list and count nodes
void displayAndCount() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    Employee* temp = head;
    int count = 0;
    printf("Employee details:\n");
    while (temp != NULL) {
        printf("SSN: %s, Name: %s, Dept: %s, Designation: %s, Salary: %.2f, Phone: %s\n",
               temp->SSN, temp->Name, temp->Dept, temp->Designation, temp->Sal, temp->PhNo);
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
