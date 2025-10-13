#include <stdio.h>
int queue[50];
int front=-1;
int rear=-1;

void enque(){
    if(rear==49){
        printf("Queue Overflow\n");
    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        int a;
        printf("Enter value to insert:");
        scanf("%d",&a);
        queue[rear]=a;
        printf("Value enqued successfully\n");    
    }
    else{
        int a;
        printf("Enter value to insert:");
        scanf("%d",&a);
        queue[++rear]=a;
        printf("Value enqued successfully\n");
    }
}

void deque(){
    if(front==-1 && rear==-1){
        printf("Queue Underflow\n");
    }
    else if(front==rear){
        printf("Dequed element:%d",queue[front]);
        printf("\n");
        front=-1;
        rear=-1;
    }
    else{
        printf("Dequed element:%d",queue[front]);
        printf("\n");
        front++;
    }
}

void peek(){
    if(front==-1){
        printf("Empty Queue\n");
    }
    else{
        printf("Peeked element:%d\n",queue[front]);
        printf("\n");
    }
}

void display(){
    if(front==-1 && rear==-1){
        printf("Empty Queue \n");
    }
    else if(front==rear){
        printf("%d",queue[front]);
        printf("\n");
    }
    else{
        int i=0;
        for(i=front;i<rear+1;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}

void main(){
    int choice,cont;
    do{
        printf("1)Enque\n");
        printf("2)Deque\n");
        printf("3)Display\n");
        printf("4)Peek\n");
        printf("What would you like to do?(1,2,3,4)");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enque();
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
        printf("Would you like to perform any other actions?(1 for yes,0 for no)");
        scanf("%d",&cont);
    }
    while(cont!=0);
}