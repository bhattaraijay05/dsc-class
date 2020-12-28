#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int travData(struct node *head)
{
    struct node *new;
    new = (malloc(sizeof(struct node)));
    new = head;
    if (new == NULL)
    {
        printf("No Data");
    }
    do
    {
        printf("%d", new->data);
        new = new->next;

    } while (new->next != head);
}

int main()
{
    struct node *head, *middle, *last;
    head = malloc(sizeof(struct node));
    middle = malloc(sizeof(struct node));
    last = malloc(sizeof(struct node));
    // head->data = 10;
    // middle->data = 20;
    // last->data = 30;

    // head->next = middle;
    // middle->next = last;
    // last->next = head;

    travData(head);
}