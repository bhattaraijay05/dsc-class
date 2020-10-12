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
    char c = 'y';
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
        printf("\n Do u want to enter more node ->[y/n] ");
        scanf("%s", &c);
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

void del_any()
{
    bool flag = false;
    int n, i = 2;
    printf("\n Enter position -> ");
    scanf("%d", &n);
    Node *temp, *pretemp;
    pretemp = firstNode;
    temp = firstNode->link;
    if (n == 1)
    {
        flag = true;
        firstNode = temp;
        printf("\n Deleted Element -> %d", pretemp->data);
        free(pretemp);
    }
    while (temp != NULL && !flag)
    {
        if (i == n)
        {
            pretemp->link = temp->link;
            printf("\n Deleted Element -> %d", temp->data);
            free(temp);
            flag = true;
        }
        if (!flag)
        {
            pretemp = pretemp->link;
            temp = temp->link;
            i++;
        }
    }
    if (!flag)
    {
        printf("\n Please enter valid position!!!! [ Less than %d ] ", i - 1);
    }
    menu();
}

void del_before()
{
    bool flag = false;
    int n;
    printf("\n Enter data before which u want to delete Node[not first one] -> ");
    scanf("%d", &n);
    Node *temp, *pretemp;
    pretemp = firstNode;
    temp = firstNode->link;
    if (n == pretemp->data)
    {
        flag = true;
    }
    while (temp != NULL && !flag)
    {
        if (temp->link->data == n)
        {
            pretemp->link = temp->link;
            printf("\n Deleted Element -> %d", temp->data);
            free(temp);
            flag = true;
        }
        if (!flag)
        {
            pretemp = temp;
            temp = temp->link;
        }
    }
    if (!flag)
    {
        printf("\n Please enter valid Node!!!! ");
    }
    menu();
}

void del_after()
{
    bool flag = false;
    int n;
    printf("\n Enter data after which u want to delete Node[not last one] -> ");
    scanf("%d", &n);
    Node *temp, *pretemp;
    pretemp = firstNode;
    temp = firstNode->link;
    if (n == pretemp->data)
    {
        flag = true;
        printf("\n Deleted Element -> %d", pretemp->data);
        firstNode = pretemp->link;
        free(pretemp);
    }
    while (temp != NULL && !flag)
    {
        if (pretemp->data == n)
        {
            pretemp->link = temp->link;
            printf("\n Deleted Element -> %d", temp->data);
            free(temp);
            flag = true;
        }
        if (!flag)
        {
            pretemp = temp;
            temp = temp->link;
        }
    }
    if (!flag)
    {
        printf("\n Please enter valid Node!!!! ");
    }
    menu();
}

void del_nodes_beg()
{
    Node *temp;
    temp = firstNode;
    printf("\n Deleted Element -> %d", temp->data);
    firstNode = temp->link;
    free(temp);
}

void del_nodes_end()
{
    Node *temp, *pretemp;
    pretemp = firstNode;
    temp = firstNode->link;

    while (temp->link != NULL)
    {
        temp = temp->link;
        pretemp = pretemp->link;
    }
    pretemp->link = NULL;
    printf("\n Deleted Element -> %d", temp->data);
    free(temp);
}

void menu()
{
    int option;
    char c = 'y';
    printf("\n----------------------------------------------------\n 1. Enter nodes.");
    printf("\n 2. Print nodes.");
    printf("\n 3. Delete node at desired position.");
    printf("\n 4. Delete nodes from begining.");
    printf("\n 5. Delete nodes from End.");
    printf("\n 6. Delete node before a particular node.");
    printf("\n 7. Delete node after a particular node.");
    printf("\n 8. Exit\n----------------------------------------------------\n Enter your option ->");
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
        del_any();
        break;
    case 4:
        printf("\n \n Do u want to delete first element ?[y/n]: ");
        scanf("%s", &c);

        while ((c == 'y' || c == 'Y') && (firstNode != NULL))
        {
            del_nodes_beg();
            printf("\n Do u want to delete more ?[y/n] : ");
            scanf("%s", &c);
        }
        menu();
        break;
    case 5:
        printf("\n \n Do u want to delete last element ?[y/n]: ");
        scanf("%s", &c);

        while ((c == 'y' || c == 'Y') && (firstNode != NULL))
        {
            del_nodes_end();
            printf("\n Do u want to delete more ?[y/n] : ");
            scanf("%s", &c);
        }
        menu();
        break;
    case 6:
        del_before();
        break;
    case 7:
        del_after();
        break;
    case 8:
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
        firstNode = temp->link;
        free(temp);
    }
    return 0;
}