#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
void inorder_traversal(struct node *ptr);
struct node *create(void);
struct node *BST_create(struct node *root, int data);
int main()
{
    printf("\n CREATE A BST ");
    struct node *ptr = create();
    for (;;)
    {
        printf("\n Choose 1 for in-order traversal");
        printf("\n Choose 2 to recreate new BST");
        printf("\n Choose 0 for termination");
        printf("\n Choose : ");
        int type;
        scanf("%d", &type);
        switch (type)
        {
        case 1:
            printf("\n In-order traversal: ");
            inorder_traversal(ptr);
            printf("\n");
            break;
        case 2:
            printf("\n Recreating new BST...\n");
            ptr = create();
            break;
        case 0:
            printf("\n Terminated\n");
            exit(0);
        default:
            printf("\n INVALID CHOICE ");
        }
    }
    return 0;
}
struct node *BST_create(struct node *root, int data)
{
    if (root == NULL)
    {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->lchild = NULL;
        newNode->rchild = NULL;
        return newNode;
    }
    if (data < root->data)
    {
        if (root->lchild == NULL)
        {
            printf("  -> Inserting %d as left child of %d\n", data, root->data);
        }
        root->lchild = BST_create(root->lchild, data);
    }
    else if (data > root->data)
    {
        if (root->rchild == NULL)
        {
            printf("  -> Inserting %d as right child of %d\n", data, root->data);
        }
        root->rchild = BST_create(root->rchild, data);
    }
    else
    {
        printf("  -> Duplicate data not allowed in BST: %d\n", data);
    }
    return root;
}
struct node *create(void)
{
    struct node *root = NULL;
    int data;
    printf("\n Enter node values (Enter -1 to stop): \n");
    while (1)
    {
        printf(" Enter data: ");
        scanf("%d", &data);

        if (data == -1)
        {
            break;
        }
        if (root == NULL)
        {
            printf("  -> Inserting %d as the root node\n", data);
        }
        root = BST_create(root, data);
    }
    return root;
}
void inorder_traversal(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    inorder_traversal(ptr->lchild);
    printf("%d ", ptr->data);
    inorder_traversal(ptr->rchild);
}
