#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

 struct node{
    int data ;
    struct node* left ;
    struct node* right ;
};
struct node* create() ;
void preorder(struct node* root) ;
void inorder(struct node* root) ;
void postorder(struct node* root) ;
int main(){
struct node *root ;
root = NULL;
root = create();
int k, choice;
printf("do you want to print the binary tree(0/1) : ");
scanf("%d",&k);

if(k==1){
    printf("want to print preorder tree(1) : ");
    printf("want to print inorder tree(2) : ");
    printf("want to print postorder tree(3) : ");
    printf("want to exit(4) : ");
    scanf("%d",&choice);
}
switch (choice)
{
case 1: preorder(root);
    break;
case 2: inorder(root);
break;
case 3: postorder(root);
break;
case 4 : exit(0);
break;
default: printf("wrong input .");
    break;
}
return 0;
}
struct node* create(){
    int x;
    struct node *newnode ;
    newnode =(struct node*)malloc(sizeof(struct node));
    printf("enter the data(-1 for no data ) : ");
    scanf("%d",&x);
    if(x == -1){
        return 0 ;
    }
    else{
    newnode->data = x;
    printf("enter the left child of %d : \n",x);
    newnode->left = create();


    printf("enter the right child of %d : \n",x);
    newnode->right = create();

    return newnode ;
    }
}
void preorder(struct node* root){
    if (root == NULL){
        return ;
    }
    else{
        printf("%d\n",root->data);
        preorder(root->left);
     preorder(root->right);
    }
}
void inorder(struct node* root){
    if (root == NULL){
        return ;
    }
    else{
        inorder(root->left);
           printf("%d\n",root->data);
     inorder(root->right);
    }
}
void postorder(struct node* root){
    if (root == NULL){
        return ;
    }
    else{
        postorder(root->left);
     postorder(root->right);
      printf("%d\n",root->data);
    }
}