#include <stdio.h>
#include <stdlib.h>

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
        printf("Number of nodes cannot be negative\n.");
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

void del_beg(){
    struct Node *temp=head;
    head=head->next;
    free(temp);
    printf("Deleted\n");
}

void del_last(){
    struct Node *temp=head,*tail;
    if(head==NULL){
        printf("Empty list\n");
        return;
    }
    if(head->next==NULL){
        printf("Deleted\n");
        free(head);
        return;
    }
    while(temp->next!=NULL){
        tail=temp;
        temp=temp->next;
    }
    tail->next=NULL;
    free(temp);
    printf("Deleted\n");
}

void del_any(){
    if(head==NULL){
        printf("Empty list\n");
        return;
    }
    int value;
    printf("Enter value to delete:");
    scanf("%d",&value);
    if(head->data==value && head->next==NULL){
        printf("Deleted\n");
        free(head);
        head=NULL;
        return;
    }
    else if(head->data==value && head->next!=NULL){
        del_beg();
    }
    else{
        struct Node *temp=head,*tail;
        while(temp->data!=value){
            if(temp->next==NULL){
                printf("Value not in list.\n");
                return;
            }
            tail=temp;
            temp=temp->next;
        }
        tail->next=temp->next;
        free(temp);
        printf("Deleted.\n");
    }

}

void display(){
    struct Node *temp=head;
    if(head==NULL){
        printf("Empty list\n");
    }
    else{
        printf("Contents of list:\n");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\nEnd of list.\n");
    }
}

void main(){
    int choice=1,op,delop;
    while(choice==1){
        printf("1)Create a list\n");
        printf("2)Insert\n");
        printf("3)Display list\n");
        printf("4)Delete\n");
        printf("What would you like to do?(1,2,3,4):");
        scanf("%d",&op);
        switch(op){
            case 1:
                createlist();
                break;
            case 2:
                printf("1)Insert at beginning\n");
                printf("2)Insert at end\n");
                printf("3)Insert at any position\n");
                printf("What would you like to do?(1,2,3):");
                scanf("%d",&delop);
                switch(delop){
                    case 1:
                        insert_beg();
                        break;
                    case 2:
                        insert_end();
                        break;
                    case 3:
                        insert_anypos();
                        break;
                    default:
                        printf("Invalid input.\n");
                        break;
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("1)Delete from beginning\n");
                printf("2)Delete from end\n");
                printf("3)Delete a value\n");
                printf("What would you like to do?(1,2,3):");
                scanf("%d",&delop);
                switch(delop){
                    case 1:
                        del_beg();
                        break;
                    case 2:
                        del_last();
                        break;
                    case 3:
                        del_any();
                        break;
                    default:
                        printf("Invalid input.\n");
                        break;
                }
                break;
            default:
                printf("Invalid input.\n");
                break;
        }
        printf("Would you like to do anything else?(1 for yes,0 for no)");
        scanf("%d",&choice);
    }
}