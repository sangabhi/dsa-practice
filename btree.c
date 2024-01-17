#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node *createNode();
void inorderTraversal(struct node* root);

int main() {
    struct node *root = NULL;
    root = createNode();

    printf("Traversal (Inorder): ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}

struct node *createNode() {
    int x;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    
    printf("Enter the data (-1 for no data): ");
    scanf("%d", &x);

    if(x == -1){
        return NULL;
    }

    newnode->data = x;
    printf("Enter the left child of %d : ", x);
    newnode->left = createNode();
    printf("Enter the right child of %d : ", x);
    newnode->right = createNode();

    return newnode;
}

void inorderTraversal(struct node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
