#include <stdio.h>
#include <stdlib.h> // Include stdlib.h for malloc


struct node *insertatbeg(struct node *head) ;
struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL, *newnode, *temp;
    int choice = 1; // Initialize choice to a non-zero value

    while (choice) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Do you want to continue? (0/1): ");
        scanf("%d", &choice);
    } int insert ;
    printf("do you want to insert(0,1 : ");
scanf("%d",&insert);
    if(insert==1){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("eter data : ");
    scanf("%d",&newnode->data);
    newnode->next = head ;
    head = newnode ;
    }
    temp = head; // Reset temp to head before printing the list

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
struct node *insertatbeg(struct node *head){
    struct node *Newnode = (struct node*)malloc(sizeof(struct node));
    printf("enter data : ");
    scanf("%d",&Newnode->data);
    Newnode->next = head;
    head = Newnode;

}
