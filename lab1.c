#include <stdio.h>


int stack[10];
int top=-1;


void push(){
    if(top==sizeof(stack)-1){
        printf("Stack Overflow");
    }
    else{
        int x;
        printf("Enter value to push:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}


void pop(){
    if(top==-1){
        printf("Stack Underflow \n");
    }
    else{
        int copy;
        copy=stack[top];
        top--;
        printf("Popped Value:%d \n",copy);
    }
}


void peek(){
    if(top==-1){
        printf("Stack is empty.\n");
    }
    else{
        printf("Peeked value:%d \n",stack[top]);
    }
}


int main(){
    int i=0;
    int choice;
    do{
        printf("1)Push \n");
        printf("2)Pop \n");
        printf("3)Peek \n");
        printf("Which operation would you like to perform?");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            default:
                printf("Invalid input");
                break;
        }
        printf("Would you like to perform more actions?(0 for yes, 1 for no)");
        scanf("%d",&i);
    }
    while(i==0);  
     
    return 0;
}
