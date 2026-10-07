#include <stdio.h>
#include <stdlib.h>

int max = 10;
int top = -1;
int stack[10];

void push()
{
    int data;

    if (top == max - 1)
    {
        printf("overflow");
    }
    else
    {
        top++;
        printf("Enter the Element to push : ");
        scanf("%d", &data);
        stack[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("underflow");
    }
    else
    {
        
        top--;
    }
}

void peek(){
    if(top==-1){
        printf("Stack is empty");

    }
    else{
        printf("top element is %d",stack[top]);
    }
}

void display()
{
    if (top == -1)
    {
        printf("The stack is empty");
    }

    else
    {
        printf("The stack Elements are : ");
        for (int i = 0; i < top + 1; i++)
        {
            printf("%d \n", stack[i]);
        }
    }
}

void exits()
{
    printf("Exiting.....!");
    
}

int main()
{
    int choice;
    while (1)
    {
        printf("-----------------Stack Using Array------------------");
        printf("\n");
        printf("1. PUSH");
        printf("\n");
        printf("2. POP");
        printf("\n");
        printf("3. DISPLAY");
        printf("\n");
        printf("4. PEEK");
        printf("\n");
        printf("5.EXIT");
        printf("\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
            case 4:
            peek();
            break;
        case 5:
            exits();
            return 0;
        default:
            printf("invalid choice!!");
            break;
        }
    }
    return 0;
}