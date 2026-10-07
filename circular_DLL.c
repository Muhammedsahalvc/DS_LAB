#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *prev;
    struct node *next;
}node;

node *head=NULL;
node *last;


void insertbeg(){
    int val;
    node *newNode=malloc(sizeof(node));

    printf("Enter value to insert");
    scanf("%d",&val);
    newNode->data=val;
    if(head==NULL){
        newNode->next=newNode;                   
                                                                    // dwdsfw
        newNode->prev=newNode;
        head=newNode;
    }
    else{
    last=head->prev;

        newNode->next=head;
        newNode->prev=last;

        last->next=newNode;
        head->prev=newNode;

        head=newNode;


    }}


void insertend(){
    int val;
    node *newNode;newNode=malloc(sizeof(node));

    printf("Enter value to insert");
    scanf("%d",&val);
    newNode->data=val;
    if(head==NULL){
        newNode->next=head;
        newNode->prev=head;
        head=newNode;
    }
    else{
last=head->prev;

        newNode->next=head;
        newNode->prev=last;

        last->next=newNode;
        head->prev=newNode;
    }

}

void insertpos(){
    int val,pos;
    
    node *newNode;newNode=malloc(sizeof(node));

    printf("Enter value to insert");
    scanf("%d",&val);
    printf("Enter position at to insert :");
scanf("%d",&pos);
if(pos<=-1){
    printf("INVALID POSITION!!");
    return;
}
    newNode->data=val;
    if(head==NULL){
        newNode->next=head;
        newNode->prev=head;
        head=newNode;
        return;
    }
node *temp=head;
int i=1;
    
while(i<pos-1 && temp!=NULL){
temp=temp->next;
i++;
}
newNode->next=temp->next;
newNode->prev=temp;

temp->next->prev=newNode;
temp->next=newNode;

    }


void deletebeg(){
    if(head==NULL){
        printf("UNDERFLOW");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
        return;
    }
    else{
        last=head->prev;

        last->next=head->next;
        head->next->prev=last;

        head=head->next;
    }
}

void deleteend(){
    if(head==NULL){
        printf("UNDERFLOW");
        return;
    }
    if(head->next==head){
        free(head);
        head=NULL;
    }
    else{
        last=head->prev;


        head->prev=last->prev;
        last->prev->next=head;
        free(last);

    }
}

void deletepos(){
    int pos;
    node *temp=head;
    printf("Enter a position to delete : ");
    scanf("%d",&pos);
    if(temp==NULL){
        printf("Empty list");
        return;
    }
    if(pos<=-1){
        printf("INVALID POSITION");
        return;
    }
    if(pos==1){
        deletebeg();
        return;
    }
    int i=1;
    while(i<pos && temp!=NULL){
        temp=temp->next;
        i++;
    }
    if(temp==NULL){
        printf("INVALID POSITION");
        return;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
    temp->next->prev=temp->prev;}
    free(temp);
}

void search(){
    int val,i=1;
    printf("Enter value to search : ");
    scanf("%d",&val);
    node *temp=head;
    while(1){
        if(temp->data==val){
            printf("found at position : %d ",i);
            return;
        }
        else{
            temp=temp->next;
            i+=1;
            if(temp==head){
                printf("Not found...!!");
                return;
            }
        }

    }
    
}

void display(){
    node *temp=head;
    if(head==NULL){
        printf("Empty list~~");
        return;
    }
   while(1){
    printf("%d -> ",temp->data);
    temp=temp->next;
    if(temp==head){
        return;
    }
   }
}

int main()
{
    int choice;
    while (1)
    {
        printf("Choose your option : ");
        printf("\n");
        printf("1. insert beginning of the list :");
        printf("\n");
        printf("2. insert end of the list :");
        printf("\n");
        printf("3. insert at a specified position of the list :");
        printf("\n");
        printf("4. delete from beginning");
        printf("\n");

        printf("5. delete from end");
        printf("\n");
        printf("6. delete from a position");
        printf("\n");
        printf("7. search for an item");
        printf("\n");
        printf("8. to display");
        printf("\n");
        printf("9.To exit/\n");
        printf("\n");
        printf("Enter your choice number : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insertbeg();
            break;
        case 2:
            insertend();
            break;
        case 3:
            insertpos();
            break;
        case 4:
            deletebeg();
            break;

        case 5:
            deleteend();
            break;
        case 6:
            deletepos();
            break;
        case 7:
            search();
            break;
        case 8:
            display();
            break;

        case 9:
            printf("Exiting...../");
            return 0;

        default:
            printf("Invalid choice");
            break;
        }
    }

    return 0;
}
