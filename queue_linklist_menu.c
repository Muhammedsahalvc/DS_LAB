#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct  node *next;
}node;

node *temp;
node *front=NULL;
node *rear=NULL;

void enqueue(){
node *newNode;
int value;
newNode=malloc(sizeof(node));
printf("Enter value to add : ");
scanf("%d",&value);
newNode->data=value;
newNode->next=NULL;
if(front==NULL){
front=newNode;
rear=newNode;
}
else{
rear->next=newNode;
rear=newNode;
}

}

void dequeue(){
if(front==NULL){
    printf("Queue is Empty");

}
else{
    
    temp=front;
    front=front->next;
    free(temp);

    if(front==NULL){
        rear=NULL;
    }
}

}


void display(){
    temp=front;
if(front==NULL){
printf("Empty Queue");
}
else{
    while(temp!=NULL){
printf("%d ",temp->data);
temp=temp->next;
    }
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