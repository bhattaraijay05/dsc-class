#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data[3];
    struct node *left, *right;
};
void Inorder(struct node *node)
{
    if (node == NULL)
        return;
    Inorder(node->left);
    printf(" %s", node->data);
    Inorder(node->right);
}
struct node *addNode(char data[3])
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    strcpy(newNode->data, data);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct node *insert(struct node *node, char data[3])
{
    if (node == NULL)
        return addNode(data);
    if (strcmpi(data, node->data) > 0)
        node->left = insert(node->left, data);
    else if (strcmpi(data, node->data) < 0)
        node->right = insert(node->right, data);
    return node;
}
struct node *InsertNewNode(struct node *root)
{
    char d[3];
    char c = 'y';
    while (c == 'y' || c == 'Y')
    {
        printf("\n Enter the element for BST -> ");
        scanf("%s", &d);
        root = insert(root, d);
        printf("\n Do you want to enter more ?[y/n] : ");
        scanf("%s", &c);
    }
    return root;
}
int main()
{
    int data;
    struct node *root = NULL;
    root = InsertNewNode(root);
    printf("\n Inorder traversal of the tree :");
    Inorder(root);
    return 0;
}