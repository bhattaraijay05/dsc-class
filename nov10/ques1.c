
// 2.Operations of queue  using array
#include <stdio.h>
#include <stdlib.h>
#define maxsize 10
int front = -1, rear = -1;
int queue[maxsize];
void enQueue()
{
    int item;
    printf("\nEnter the element\n");
    scanf("\n%d", &item);
    if (rear == maxsize - 1)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
    }
    else
    {
        rear = rear + 1;
    }
    queue[rear] = item;
    printf("\nValue inserted ");
}
void deQueue()
{
    int item;
    if (front == -1 || front > rear)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        item = queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = front + 1;
        }
        printf("\nvalue deleted ");
    }
}

void display()
{
    int i;
    if (rear == -1)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nprinting values \n");
        for (i = front; i <= rear; i++)
        {
            printf(" %d ", queue[i]);
        }
    }
}
void main()
{
    int choice;
    while (choice != 4)
    {
        printf("\n1.insert an element\n2.Delete an element\n3.Display the queue\n4.Exit\n");
        printf("\nEnter your choice ?");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nEnter valid choice??\n");
        }
    }
}