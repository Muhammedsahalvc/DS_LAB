#include<stdio.h>
#define max 5

int arr[max];
int rear=-1,front=-1;


void enqueue(){
    int val;
    if((rear+1)%max==front){
printf("Overflow");
return;
    }
  
    printf("Enter the value to insert : ");
    scanf("%d",&val);
      if(front==-1){
        front=0;
        
    }
    rear=(rear+1)%max;
    arr[rear]=val;
}

void dequeue(){
    if(front==-1){
        printf("Underflow");
        return;
    }
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else{
        front=(front+1)%max;
    }



}

    void display(){
        if(front==-1){
            printf("Empty Queue");
            return;
        }

       int i=front;
       while(1){
        printf("%d ",arr[i]);
        if(i==rear){
            break;
        }
        i=(i+1)%max;

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