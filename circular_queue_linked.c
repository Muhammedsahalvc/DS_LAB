#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    
}node;

node *front=NULL,*rear=NULL;

void enqueue(){
    int value;
    node *newNode=malloc(sizeof(node));
    printf("Enter value : ");
    scanf("%d",&value);
    newNode->data=value;
    newNode->next=NULL;
    if(front==NULL){
        front=newNode;
        rear=newNode;
    }
    
        rear->next=newNode;
        rear=newNode;
    
}

void dequeue(){
    node *temp;
    if(front==NULL){
        printf("Underflow");
        return;
    }
    temp=front;
    front=front->next;
    printf("deleted %d",temp->data);
    free(temp);
    rear->next=front;

}

void display(){
    if(front==NULL){
        printf("Empty queue");
        return;
    }

    node *temp=front;
while(1){
     printf("%d ",temp->data);
     if(temp==rear){
        break;
     }
     temp=temp->next;
}
}



int main()
{
    int choice;
    while (1)
    {
        printf("-----------------Queue Using Array------------------");
        printf("\n");
        printf("1. ENQUEUE");
        printf("\n");
        printf("2. DEQUEUE");
        printf("\n");
        printf("3. DISPLAY");
        printf("\n");
        printf("4. EXIT");
        printf("\n");
       

        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        
        case 4:
            printf("Exiting/....");
            return 0;
        default:
            printf("invalid choice!!");
            break;
        }
    }
    return 0;
}