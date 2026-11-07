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
struct node *search(struct node *root, int data);
struct node *delete(struct node *root, int data);
int main()
{
    printf("\n CREATE A BST ");
    struct node *ptr = create();
    for (;;)
    {
        printf("\n Choose 1 for in-order traversal");
        printf("\n Choose 2 for searching in BST");
        printf("\n Choose 3 for deletion in BST");
        printf("\n Choose 4 to recreate new BST");
        printf("\n Choose 0 for termination");
        printf("\n Choose : ");
        int type;
        scanf("%d", &type);
        switch (type)
        {
        case 1:
            printf("\n In-order traversal : ");
            inorder_traversal(ptr);
            printf("\n");
            break;
        case 2:
            printf("\n Searching in BST");
            printf("\n Enter data to search : ");
            int search_data;
            scanf("%d", &search_data);
            struct node *search_result = search(ptr, search_data);
            if (search_result != NULL)
            {
                printf("\n  -> Data %d found in BST.", search_data);
            }
            else
            {
                printf("\n  -> Data %d not found in BST.", search_data);
            }
            break;
        case 3:
            printf("\n Deleting from BST");
            printf("\n Enter data to delete : ");
            int delete_data;
            scanf("%d", &delete_data);
            if (search(ptr, delete_data) != NULL)
            {
                ptr = delete(ptr, delete_data);
                printf("\n  -> Deleted %d from BST.", delete_data);
            }
            else
            {
                printf("\n  -> Data %d not found in BST.", delete_data);
            }
            break;
        case 4:
            printf("\n Recreating new BST");
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
            printf("\n  -> Inserting %d as left child of %d", data, root->data);
        }
        root->lchild = BST_create(root->lchild, data);
    }
    else if (data > root->data)
    {
        if (root->rchild == NULL)
        {
            printf("\n  -> Inserting %d as right child of %d", data, root->data);
        }
        root->rchild = BST_create(root->rchild, data);
    }
    else
    {
        printf("\n  -> Duplicate data not allowed in BST: %d", data);
    }
    return root;
}
struct node *create(void)
{
    struct node *root = NULL;
    int data;
    printf("\n Enter node values (Enter -1 to stop): ");
    while (1)
    {
        printf("\n Enter data: ");
        scanf("%d", &data);
        if (data == -1)
        {
            break;
        }
        if (root == NULL)
        {
            printf("\n  -> Inserting %d as the root node", data);
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
struct node *search(struct node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->lchild, data);
    }
    else
    {
        return search(root->rchild, data);
    }
}
struct node *delete(struct node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->lchild = delete(root->lchild, data);
    }
    else if (data > root->data)
    {
        root->rchild = delete(root->rchild, data);
    }
    else
    {
        if (root->lchild == NULL)
        {
            struct node *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            struct node *temp = root->lchild;
            free(root);
            return temp;
        }
        struct node *temp = root->rchild;
        while (temp && temp->lchild != NULL)
        {
            temp = temp->lchild;
        }
        root->data = temp->data;
        root->rchild = delete(root->rchild, temp->data);
    }
    return root;
}
