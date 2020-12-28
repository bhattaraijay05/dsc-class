#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};
int max(int a, int b);
int height(struct node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
struct node *newNode(int data)
{
    struct node *node = (struct node *)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}
int getBalance(struct node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}
struct node *insert(struct node *node, int data)
{
    if (node == NULL)
        return (newNode(data));
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;
    node->height = 1 + max(height(node->left),
                           height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && data < node->left->data)
        return rightRotate(node);
    if (balance < -1 && data > node->right->data)
        return leftRotate(node);
    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct node *deleteNode(struct node *root, int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            struct node *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            struct node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    if (root == NULL)
        return root;
    root->height = 1 + max(height(root->left),
                           height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}
void preOrder(struct node *root)
{
    if (root != NULL && root->data != -1)
    {
        printf("%d ->", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main()
{
    int userChoice, insNode, delNode;
    struct node *rootNode = NULL;
    printf("Enter -1 to stop\n");
    do
    {
        printf("Enter node to be inserted: ");
        scanf("%d", &insNode);
        rootNode = insert(rootNode, insNode);
    } while (insNode != -1);
    do
    {
        printf("\n\nEnter your choice\n1: Insert \n2: Display \n3: Delete \n4: Exit\n");
        scanf("%d", &userChoice);
        switch (userChoice)
        {
        case 1:
            printf("\nEnter node to be inserted: ");
            scanf("%d", &insNode);
            rootNode = insert(rootNode, insNode);
            break;
        case 2:
            printf("\nPreorder Traversal is:\n");
            preOrder(rootNode);
            break;
        case 3:
            printf("Enter the node to delete: ");
            scanf("%d", &delNode);
            deleteNode(rootNode, delNode);
            preOrder(rootNode);
            break;
        case 4:
            break;
        default:
            printf("\nEnter valid choices\n");
            break;
        }
    } while (userChoice != 4);
    return 0;
}