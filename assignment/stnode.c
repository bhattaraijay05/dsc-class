#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node *next;
} * firstNode;

void createNodeList(int n);
void displayList();

int main()
{
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    createNodeList(n);
    printf("Data entered in the list: \n");
    displayList();
    return 0;
}

void createNodeList(int n)
{
    struct node *newNode, *tmp;
    int num, i;
    firstNode = (struct node *)malloc(sizeof(struct node));

    if (firstNode == NULL)
    {
        printf("Memory cannot be allocated ");
    }
    else
    {
        for (i = 1; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            printf("Input data for node %d: ", i);
            scanf("%d", &num);
            newNode->num = num;
            newNode->next = NULL;
            tmp->next = newNode;
            tmp = tmp->next;
        }
    }
}

void displayList()
{
    struct node *tmp;
    if (firstNode == NULL)
    {
        printf("List is Empty \n");
    }
    else
    {
        tmp = firstNode;
        int i = 1;
        while (tmp != NULL)
        {
            printf("Node %d Data = %d \n", i, tmp->num);
            tmp = tmp->next;
            i++;
        }
    }
}