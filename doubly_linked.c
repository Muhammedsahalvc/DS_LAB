#include <stdio.h>
#include <stdlib.h>

typedef struct node
{

    int data;
    struct node *prev;
    struct node *next;

} node;

node *head = NULL;

void insertbegin()
{
    int val;
    node *newNode = malloc(sizeof(node));

    printf("Enter the value: ");
    scanf("%d", &val);

    newNode->data = val;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
    }

    head = newNode;
}

void insertend()
{
    int val;
    node *temp = head;
    node *newNode = malloc(sizeof(node));
    printf("Enter the value :");
    scanf("%d", &val);
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    newNode->prev = temp;
}

void insertpos()
{
    int val, pos;
    node *temp = head;
    node *newNode = malloc(sizeof(node));
    printf("Enter the value :");
    scanf("%d", &val);
    printf("Enter the position to add : ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        free(newNode);
        printf("Invalid poition");
        return;
    }
    newNode->data = val;
    newNode->next = head;
    newNode->prev = NULL;

    if (pos == 1)
    {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    int i = 1;
    while (i < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Invalid position");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deletebegin()
{
    if (head == NULL)
    {
        printf("Underflow\n");
        return;
    }

    node *temp = head;

    printf("Deleted %d\n", temp->data);

    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);
}




void deleteend()
{
    if (head == NULL)
    {
        printf("Underflow");
        return;
    }
    node *temp = head;
    if (head->next == NULL)
    {
        printf("Deleted %d", head->data);
        free(head);
        head = NULL;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    printf("Deleted %d", temp->data);
    temp->prev->next = NULL;
    free(temp);
}



void deletepos()
{
    int pos;
    node *temp = head;
    if (head == NULL)
    {
        printf("Underflow");
        return;
    }
    printf("Enter the position to delete : ");
    scanf("%d", &pos);
    if (pos < 1)
    {
        printf("invalid position");
        return;
    }
    if (pos == 1)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        return;
    }
    int i = 1;
    while (i < pos && temp != NULL)
    {
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Invalid position");
        return;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    else
    {
        head = temp->next;
    }

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    printf("Deleted %d\n", temp->data);

    free(temp);
}

void search()
{
    int s;
    node *temp = head;

    printf("Enter the value to search: ");
    scanf("%d", &s);

    int i = 1;

    while (temp != NULL)
    {
        if (temp->data == s)
        {
            printf("The value %d found at position %d\n", s, i);
            return;
        }

        temp = temp->next;
        i++;
    }

    printf("Not found\n");
}


void display()
{
    node *temp = head;
    if (head == NULL)
    {
        printf("Empty Linked List : ");
        return;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
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
            insertbegin();
            break;
        case 2:
            insertend();
            break;
        case 3:
            insertpos();
            break;
        case 4:
            deletebegin();
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
