#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;

} node;
int value;
node *top = NULL;

void push()
{
    node *newNode;

    newNode = (node *)malloc(sizeof(node));

    printf("Enter data to push :");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = top;
    top = newNode;

}

void pop()
{
    node *temp;

    
    if (top == NULL)
    {
        printf("Underflow");
    }
    else
    {
        temp = top;
        top = top->next;
        free(temp);
    }
}

void peek()
{

    if (top == NULL)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("%d ", top->data);
    }
}

void display()
{
    node *temp;
    temp = top;
    if (top == NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack elements are :\n");
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
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
            printf("Exiting......!!");
            return 0;
        default:
            printf("invalid choice!!");
            break;
        }
    }
    return 0;
}