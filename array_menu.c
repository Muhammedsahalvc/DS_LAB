#include <stdio.h>
#include <stdlib.h>
int a[100];
int n;
void insert()
{
    int value, pos;
    printf("Enter value to insert: ");
    scanf("%d", &value);
    printf("Enter the position to add : ");
    scanf("%d", &pos);
    for (int i = n; i >= pos; i--)
    {
        a[i] = a[i - 1];
    }
    a[pos - 1] = value;
    n = n + 1;
}

void delete()
{
    int pos;
    printf("Enter the position to delete : ");
    scanf("%d", &pos);
    if (pos < 1 || pos > n)
    {
        printf("no such position!!");
        return;
    }
    else
    {
        for (int i = pos - 1; i < n-1; i++)
        {
            a[i] = a[i + 1];
        }
        n--;
    }
}
void display()
{
    if(n==0){
        printf("its a empty Array ");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{

    printf("Enter number to values :");
    scanf("%d", &n);
    printf("Enter elements :");
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    
    int choice;
    while (1)
    {
        printf("Choose your option : ");
        printf("\n");
        printf("1. insert :");
        printf("\n");
        printf("2.delete:");
        printf("\n");
        printf("3.Display :");
        printf("\n");
        printf("4. Exit");
        printf("\n");
        printf("Enter your choice number : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting...../");
            return 0;

        default:
            printf("Invalid choice");
            break;
        }
    }if(choice!=4)

    return 0;
}
