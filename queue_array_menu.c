#include <stdio.h>
#include<stdlib.h>
int front = -1, rear = -1;
int qeue[20];
int temp;

void enqeue()
{
    int value;
    printf("Enter the value to add : ");
    scanf("%d", &value);
    if (rear >= 19)
    {
        printf("OVERFLOW");
    }
    else
    {
        
        rear++;
        qeue[rear] = value;
        if(front==-1){
            front = 0;
        }
    }
}

void dequeue()
{
    if (front == -1)
    {
        printf("Empty queue,UNDERFLOW");
    }
    else
    {

        temp = front;
        front++;
        

        
        printf("dequeued element is %d ", qeue[temp]);
        
    }
}
void display()
{
    if (front == -1)
    {
        printf("Empty Queue");
    }
    else
    {
       for(int i=front;i<=rear;i++){
        printf("%d ",qeue[i]);
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
            enqeue();
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