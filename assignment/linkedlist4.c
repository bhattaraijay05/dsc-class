#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

Node *firstNode;

void menu();

void createNodes()
{
    int d, i = 1;
    int c = 1;
    Node *newNode;

    while (c == 'y' || c == 'Y')
    {
        newNode = (Node *)malloc(sizeof(Node));
        if (!newNode)
        {
            printf("\n Error in allocating memory!!!");
            exit(0);
        }
        newNode->link = NULL;
        printf("\n Enter the data for node %d : ", i++);
        scanf("%d", &d);
        newNode->data = d;
        newNode->link = firstNode;
        firstNode = newNode;
        printf("\n Do u want to enter more node ->[1/-1] ");
        scanf("%d", &c);
    }
    menu();
}

void printNodes()
{
    int i = 1;
    Node *temp;
    temp = firstNode;
    while (temp != NULL)
    {
        printf("\n Data %d", i++);
        printf(":  %d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
    menu();
}

void insertAny()
{
    bool flag = false;
    int d, n, i = 2;
    printf("\n Enter data at position [greater than 1]-> ");
    scanf("%d", &n);
    Node *temp, *newNode;
    temp = firstNode;
    while (temp != NULL)
    {
        if (i == n)
            ;
        {
            flag = true;
            newNode = (Node *)malloc(sizeof(Node));
            if (!newNode)
            {
                printf("\n Error in allocating memory!!!");
                exit(0);
            }
            newNode->link = NULL;
            printf("\n Enter the data for node %d : ", i);
            scanf("%d", &d);
            newNode->data = d;
            newNode->link = temp->link;
            temp->link = newNode;
            break;
        }
        temp = temp->link;
        i++;
    }
    if (!flag)
    {
        printf("\n Please enter valid position!!!! [ Less than %d ] ", i - 1);
    }
    menu();
}

void del_nodes()
{
    Node *temp;
    temp = firstNode;
    printf("\n Deleted Element -> %d", temp->data);
    firstNode = temp->link;
    free(temp);
}

void menu()
{
    int option;
    int c = 1;
    printf("\n----------------------------------------------------\n 1. Enter nodes.");
    printf("\n 2. Print nodes.");
    printf("\n 3. Enter node at desired position.");
    printf("\n 4. Delete nodes.");
    printf("\n 5. Exit\n----------------------------------------------------\n Enter your option ->");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
        createNodes();
        break;
    case 2:
        printNodes();
        break;
    case 3:
        insertAny();
        break;
    case 4:
        printf("\n \n Do u want to delete first element ?[1/-1]: ");
        scanf("%d", &c);

        while ((c == 'y' || c == 'Y') && (firstNode != NULL))
        {
            del_nodes();
            printf("\n Do u want to delete more ?[1/-1] : ");
            scanf("%d", &c);
        }
        menu();
        break;
    case 5:
        return;
        break;
    default:
        printf("\n\n Enter correct choice !!!\n");
        menu();
    }
}

int main()
{
    menu();

    while (firstNode != NULL)
    {
        Node *temp;
        temp = firstNode;
        //printf("\n Deleted Element -> %d", temp->data);
        firstNode = temp->link;
        free(temp);
    }
    return 0;
}