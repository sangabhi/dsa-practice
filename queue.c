#include <stdio.h>
#include <stdlib.h>

#define N 20

int queue[N] ;

int front = -1 ;
int rear = -1 ;
void enqueue(int x) ;
void dequeue(){
    if( front == -1 && rear == -1){
        printf("queue is underflow\n .");
    }
        else if(front == rear){
            front = rear = -1;
        }
        else{
            printf("deleted item is %d\n",queue[front]);
            front++;
        }

        }
     
void display(){
        printf("elements in the queue is : \n");
        for(int i=front; i<=rear; i++){
            printf("%d\n",queue[i]);
        }

     }



int main(){
int choice, value;
while(1){
    printf("1.enqueue\n");
    printf("2.dequeue\n");
    printf("3.display\n");
    printf("4.exit");
    printf("enter your choice : ");
    scanf("%d", &choice);

switch (choice)
{
case 1:
    printf("enter the value to enqueue : ");
    scanf("%d",&value);
     enqueue(value);
    break;
case 2:
 dequeue();
break;
case 3:
 display();
break;
case 4:
printf("you are out of queue .");
exit(0);
display();
default:
printf("invalid input");
    break;
}
}
return 0;
}
void enqueue(int x){
    if(rear==N-1){
        printf("queue is overflow\n");
    }
    else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x ;
    }
    else{
        rear++;
        queue[rear] = x;
    }
}
