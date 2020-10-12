#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;

void create()
{
    struct node *newnode, *temp;
    int i = 2, data;
    head = (struct node *)malloc(sizeof(struct node));
    if (newnode = NULL)
    {
        printf("Space is not allocated\n");
        exit(0);
    }
    else
    {
        printf("Space is allocated successfully,Enter -1 to stop\n");
        printf("Enter the data for node 1 : ");
        scanf("%d", &data);
        if (data == -1)
            return;
        head->data = data;
        head->next = NULL;
        temp = head;
        while (1)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            if (newnode == NULL)
            {
                printf("Space is not allocated\n");
                exit(0);
            }
            else
            {
                printf("Enter the data for %d node : ", i);
                scanf("%d", &data);
                if (data == -1)
                    break;
                newnode->data = data;
                newnode->next = NULL;
                temp->next = newnode;
                temp = temp->next;
                i++;
            }
        }
    }
}

void display()
{
    struct node *temp;
    printf("\n");
    if (head == NULL)
    {
        printf("Space is empty\n");
    }
    else
    {
        temp = head;
        int i = 1;
        while (temp != NULL)
        {
            printf("The node %d contains the data %d\n", i, temp->data);
            temp = temp->next;
            i++;
        }
        printf("\n");
    }
}

int insert_beg(int data)
{
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = head;
    head = new;
}

int insert_end(int value)
{
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newnode->data = value;
    newnode->next = NULL;
    temp->next = newnode;
    printf("\nInserted %d at the end\n\n\n", value);
    return 0;
}

int insert_before()
{
    struct node *newnode, *ptr, *preptr;
    int val;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Element to insert-> ");
    scanf("%d", &newnode->data);
    printf("\nEnter the Position Before which node to be inserted: ");
    scanf("%d", &val);
    ptr = head;
    preptr = ptr;
    if (ptr->data == val)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        while (ptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("Value not found\n");
                return 1;
            }
        }
        preptr->next = newnode;
        newnode->next = ptr;
    }
}

int insert_after()
{
    struct node *newnode, *ptr, *preptr;
    int val;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the Element to insert-> ");
    scanf("%d", &newnode->data);
    printf("\nEnter the Position Before which node to be inserted: ");
    scanf("%d", &val);
    ptr = head;
    preptr = ptr;
    if (ptr->data == val)
    {
        newnode->next = head->next;
        head->next = newnode;
    }
    else
    {
        while (preptr->data != val)
        {
            preptr = ptr;
            ptr = ptr->next;
            if (ptr == NULL)
            {
                printf("Value not found\n");
                return 1;
            }
        }
        preptr->next = newnode;
        newnode->next = ptr;
    }
}

int insert_n(int ele, int pos)
{
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    int i;
    if (pos == 1)
    {
        newnode->data = ele;
        newnode->next = head;
        head = newnode;
        printf("\nInserted %d at %d'th node SUCESSFULLY\n\n\n", ele, pos);
        return 0;
    }
    else
    {
        temp = head;
        i = 2;
        while (temp != NULL)
        {
            if (i == pos)
            {
                newnode->data = ele;
                newnode->next = temp->next;
                temp->next = newnode;
                printf("\nInserted %d at %d'th node SUCESSFULLY\n\n\n", ele, pos);
                return 0;
            }
            temp = temp->next;
            i++;
        }
        printf("\nNot a valid position...\n\n\n");
    }
}

int main()
{
    int arg, n, a, ele, pos;
    create();
    display();
    while (1)
    {
        printf("Enter 2 to Insert at beginning of the node \nEnter 3 to Insert at the End of the node \nEnter 4 to Insert before the element \nEnter 5 to Insert After the element \nEnter 6 to Insert at the Nth Position \nEnter 7 to Display \nEnter 0 to Exit\n ");
        scanf("%d", &arg);
        if (arg == 2)
        {
            printf("Enter the Element to insert at beginning: ");
            scanf("%d", &n);
            insert_beg(n);
        }
        else if (arg == 3)
        {
            printf("Enter the Element to insert at End: ");
            scanf("%d", &a);
            insert_end(a);
        }
        else if (arg == 4)
        {
            insert_before();
        }
        else if (arg == 5)
        {
            insert_after();
        }
        else if (arg == 6)
        {
            printf("\nEnter the Element to insert : ");
            scanf("%d", &ele);
            printf("\nEnter the Position to insert : ");
            scanf("%d", &pos);
            insert_n(ele, pos);
        }
        else if (arg == 7)
        {
            display();
        }
        else if (arg == 0)
        {
            exit(0);
        }
        else
        {
            printf("Enter a Valid Number\n");
        }
    }
}