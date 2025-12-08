#include <stdio.h>

struct Node{
    int data;
    struct Node *next;
};
struct Node *head=NULL;

void createlist(){
    int n,data;
    int i=0;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    if(n<0){
        printf("Number of nodes cannot be negative.\n");
        return;
    }
    else{
        struct Node *newnode,*temp;
        while(i<n){
            struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
            printf("Enter data for node %d:",i+1);
            scanf("%d",&data);
            newnode->next=NULL;
            newnode->data=data;
            if(head==NULL){
                head=newnode;
            }
            else{
                temp->next=newnode;
            }
            temp=newnode;
            i=i+1;
        }
    }
    printf("List created successfully\n");
}

void insert_beg(){
    int data;
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter data for newnode:");
    scanf("%d",&data);
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    printf("Node inserted successfully\n");
}

void insert_end(){
    int data;
    struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
    struct Node *temp=head;
    printf("Enter data for newnode:");
    scanf("%d",&data);
    newnode->data=data;
    if(head==NULL){
        head=newnode;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
    printf("Node inserted successfully.\n");
}

void insert_anypos(){
    int pos,data,i=0;
    struct Node *newnode,*temp=head;
    printf("Enter position to insert node:");
    scanf("%d",&pos);
    if(pos<1){
        printf("Position cannot be negative.\n");
    }
    else if(pos==0){
        insert_beg();
    }
    else{
        for(i=0;i<pos-1 && temp!=NULL;i++){
            temp=temp->next;
        }
        if(temp==NULL){
            printf("Position out of range.\n");
        }
        else{
            newnode=(struct Node *)malloc(sizeof(struct Node));
            printf("Enter data for newnode:");
            scanf("%d",&data);
            newnode->data=data;
            newnode->next=temp->next;
            temp->next=newnode;
            printf("Node inserted at position %d\n",pos);
        }
    }
}

void display(){
    struct Node *temp=head;
    if(head==NULL){
        printf("Empty list\n");
    }
    else{
        printf("Contents of list:\n");
        while(temp->next!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d ",temp->data);
        printf("\nEnd of list.\n");
    }
}

void main(){
    int choice=1,op;
    while(choice==1){
        printf("1)Create a list\n");
        printf("2)Insert at beginning\n");
        printf("3)Insert at end\n");
        printf("4)Insert at any position\n");
        printf("5)Display list\n");
        printf("What would you like to do?(1,2,3,4,5):");
        scanf("%d",&op);
        switch(op){
            case 1:
                createlist();
                break;
            case 2:
                insert_beg();
                break;
            case 3:
                insert_end();
                break;
            case 4:
                insert_anypos();
                break;
            case 5:
                display();
                break;
            default:
                printf("Invalid input.\n");
        }
        printf("Would you like to do anything else?(1 for yes,0 for no)");
        scanf("%d",&choice);
    }
}