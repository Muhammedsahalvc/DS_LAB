#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *head = NULL;

void insertBegin()
{
    int value, n;
    node *newNode;
    newNode = malloc(sizeof(node));
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void insertend()
{
    int value, n;
    node *newNode;
    newNode = malloc(sizeof(node));
    printf("Enter value to insert: ");
    scanf("%d", &value);
    newNode->data = value;
    newNode->next = NULL;
    struct node *temp;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertposition()
{
    node *newNode, *temp;
    newNode = malloc(sizeof(node));
    int i, value, pos;
    printf("Enter value to insert : ");
    scanf("%d", &value);
    printf("Enter the position at which to add : ");
    scanf("%d", &pos);
    newNode->data = value;
    newNode->next = NULL;
    if (pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("invalid position");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletebegin()
{
    node *temp;
    if (head == NULL)
    {
        printf("underflow");
    }
    else if (head->next == NULL)
    {
        printf("Last node is deleted!");
        free(head);
        head = NULL;
    }
    else
    {
        temp = head;
        head = head->next;
        temp->next=NULL;
        free(temp);
    }
}

void deleteend()
{
    node *temp, *prev;
    temp = head;
    if (head == NULL)
    {
        printf("underflow");
    }
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    free(temp);
    prev->next = NULL;
}

void deletepos()
{
    int pos;
    node *temp,*prev;
    printf("Enter the position to delete:");
    scanf("%d", &pos);
    temp=head;
    if (pos == 1)
    {
        deletebegin();
        return;
    }
    
    int i = 1;
    while (i < pos && temp != NULL)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    if (temp == NULL)
    {
        printf("Invalid position");
        return;
    }
    else if (temp->next == NULL)
    {
        deleteend();
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void searchs()
{
    int item, i = 1;
    node *temp;
    temp=head;
    printf("Enter item to search: ");
    scanf("%d", &item);
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            printf("item found at position %d\n", i);
            return;
        }
        temp = temp->next;
        i++;
    }
    printf("Item not found");
    
}
void display()
{
    node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Linked list: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
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
            insertBegin();
            break;
        case 2:
            insertend();
            break;
        case 3:
            insertposition();
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
            searchs();
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
