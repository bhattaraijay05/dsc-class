#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data1;
    struct node *link;
};
int main()
{
    struct node *ob1, *ob2;
    ob1 = (struct node *)malloc(sizeof(struct node));
    ob1->link = NULL;
    ob1->data1 = 10;
    ob2 = (struct node *)malloc(sizeof(struct node));
    ob2->link = NULL;
    ob2->data1 = 10;
    ob2->link = &ob1;
    printf("%d", ob2->link->data1);
    return 0;
}
