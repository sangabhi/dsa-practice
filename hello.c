
#include <stdio.h>
#include<stdlib.h>
#include<math.h>



#define Max 10

int stack[Max];
int top = -1 ;

void push(int value) {
    if(top == Max-1){
        printf("stack is overflow");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("stack is empty\n");
        return -1;}
        return stack[top--];
    }

    int peek(){
        int i;
        if(top==-1){
            printf("stack is underflow");
            return 0;
        }
            else
           { for(int i=top; i>=0; i--)
                printf("items in the stack are : %d\n",stack[i]);
             
    }
    }
int isempty(){
    if(top==-1)
    return 1;
    else 
    return 0;
    }
int isfull(){
    if(top=Max-1)
    return 1;
    else
    return 0;
}

int main(){

int choice, value;
 while(1){
    
    printf("1. Push\n");
    printf("2. pop\n");
    printf("3. peek/print\n");
    printf("4. exit\n");
    printf("enter your choice : ");
    scanf("%d", &choice);
    switch(choice){
        case 1 :
        printf("enter the value to push : ");
        scanf("%d", &value);
        push(value);
        break;

        case 2 :
        value = pop();
        if (value != -1){
          printf("popped value is : %d\n",value);
        }
        break;
        case 3:
        
        value = peek() ;
        
        break;
        case 4 : 
        printf("you are out of stack");
        exit(0);
        break;
        default :
        printf("invalid choice\n");
        }
    }
     return 0;

 }


   