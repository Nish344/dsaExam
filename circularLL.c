#include <stdio.h>
#define MAX 4

int q[MAX], front = 0, rear = -1, count = 0, item, choice;

void insert(int item) {
    if (count == MAX) {
        printf("The Queue is full\n");
    } else {
        rear = (rear + 1) % MAX;
        q[rear] = item;
        count++;
    }
}

void delete() {
    if (count == 0) {
        printf("The Queue is empty\n");
    } else {
        item = q[front];
        front = (front + 1) % MAX;
        printf("The item deleted is: %d\n", item);
        count--;
    }
}

void display() {
    if (count == 0) {
        printf("The Queue is empty\n");
    } else {
        printf("Contents of the Circular Queue: ");
        int temp = front;
        for (int i = 0; i < count; i++) {
            printf("%d ", q[temp]);
            temp = (temp + 1) % MAX;
        }
        printf("\n");
    }
}

int main() {
    do {
        printf("\nEnter Your Choice:\n");
        printf("1. To Insert in Circular Queue\n");
        printf("2. To Delete from Circular Queue\n");
        printf("3. To Display the Circular Queue\n");
        printf("4. To Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item you want to insert: ");
                scanf("%d", &item);
                insert(item);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
