// doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

void linkTravPrev(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void linkTravNext(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}
void beginning_delete(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n UNDERFLOW\n");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\nNode Deleted: %d\n", head);
    }
    else
    {
        ptr = head;
        head = head->next;
        head->prev = NULL;
        free(ptr);
        printf("\nNode Deleted: %d\n", head);
    }
}

int main()
{
    struct node *head, *second, *third;
    head = (struct node *)(malloc(sizeof(struct node *)));
    second = (struct node *)(malloc(sizeof(struct node *)));
    third = (struct node *)(malloc(sizeof(struct node *)));
    second->data = 20;
    third->data = 30;
    head->data = 10;
    head->prev = NULL;
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = NULL;
    linkTravPrev(head);
    linkTravNext(third);
    beginning_delete(head);
    linkTravPrev(head);
    return 0;
}
