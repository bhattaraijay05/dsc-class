#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *link;
} Node;

void menu(Node *firstNode);

void createNodes(Node *firstNode)
{
    int d, i = 1;
    char c = 'y';
    Node *newNode;
    firstNode = NULL;
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
    menu(firstNode);
}

void printNodes(Node *firstNode)
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
    menu(firstNode);
}

void reverseList(Node *firstNode)
{
    Node *current = firstNode;
    Node *prev = NULL, *next = NULL;

    while (current != NULL)
    {
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    firstNode = prev;
    menu(firstNode);
}

void reverseListTransp(Node *firstNode)
{
    float size = sizeof(Node);
    Node *current = firstNode;
    Node *prev = NULL, *next = NULL;

    printf("\n Size of each Node = %f", size);
    int i = 0;

    while (current != NULL)
    {
        printf("\n--------------------------------------------\n Iteration %d :", ++i);
        next = current->link;
        printf("\n Address of Previous Node : %ul", prev);
        printf("\n Address of Current Node  : %ul", current);
        printf("\n Address of Next Node     : %ul", next);
        current->link = prev;
        prev = current;
        current = next;
    }
    firstNode = prev;
    menu(firstNode);
}

void menu(Node *firstNode)
{
    int choice;
    printf("\n----------------------------------------------------\n 1. Enter nodes.");
    printf("\n 2. Print nodes.");
    printf("\n 3. Reverse the List.");
    printf("\n 4. Reverse with complete transperency.");
    printf("\n 5. Exit");
    printf("\n----------------------------------------------------\n Enter your choice -> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        createNodes(firstNode);
        break;
    case 2:
        printNodes(firstNode);
        break;
    case 3:
        reverseList(firstNode);
        break;
    case 4:
        reverseListTransp(firstNode);
        break;
    case 5:
        return;
        break;
    default:
        printf("\n Enter your choice correctly !!!!!");
        menu(firstNode);
    }
}

int main()
{
    Node *firstNode;
    menu(firstNode);

    while (firstNode != NULL)
    {
        Node *temp;
        temp = firstNode;
        firstNode = temp->link;
        free(temp);
    }
    return 0;
}