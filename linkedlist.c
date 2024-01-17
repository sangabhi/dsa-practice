#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to insert a new node at the beginning of the list
struct node *insertAtBeginning(struct node *head, int value) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed.\n");
        return head;
    }

    newnode->data = value;
    newnode->next = head;
    head = newnode;

    return head;
}

int main() {
    struct node *head = NULL, *temp;
    int choice = 1;

    while (choice) {
        int data;
        printf("Enter data: ");
        scanf("%d", &data);

        head = insertAtBeginning(head, data);

        printf("Do you want to continue? (0/1): ");
        scanf("%d", &choice);
    }

    temp = head;

    while (temp != NULL) {
        printf("Number in linked list is: %d\n", temp->data);
        temp = temp->next;
    }

    // Free allocated memory
    temp = head;
    while (temp != NULL) {
        struct node *toFree = temp;
        temp = temp->next;
        free(toFree);
    }

    return 0;
}
