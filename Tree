#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct nodec
{
    char datac;
    struct nodec *lchildc;
    struct nodec *rchildc;
};
void preorder_traversal(struct node *ptr);
void inorder_traversal(struct node *ptr);
void postorder_traversal(struct node *ptr);
void preorder_traversalc(struct nodec *ptrc);
void inorder_traversalc(struct nodec *ptrc);
void postorder_traversalc(struct nodec *ptrc);
struct node *create(void);
struct nodec *createc(void);
int main()
{
    printf("\n CREATE A TREE ");
    int cn;
    printf("\n Will you use character or number ? 1 for characters and 2 for numbers : ");
    scanf("%d", &cn);
    if (cn == 1)
    {
        struct nodec *ptrc = createc();
        for (;;)
        {
            printf("\n Types of Traversal");
            printf("\n Choose 1 for pre-order traversal");
            printf("\n Choose 2 for in-order traversal");
            printf("\n Choose 3 for post-order traversal");
            printf("\n Choose 0 for termination");
            printf("\n Choose type of traversal : ");
            int type;
            scanf("%d", &type);
            switch (type)
            {
            case 1:
                preorder_traversalc(ptrc);
                break;
            case 2:
                inorder_traversalc(ptrc);
                break;
            case 3:
                postorder_traversalc(ptrc);
                break;
            case 0:
                printf("\n Terminated");
                exit(0);
            default:
                printf("\n INVALID CHOICE ");
            }
        }
    }
    if (cn == 2)
    {
        struct node *ptr = create();
        for (;;)
        {
            printf("\n Types of Traversal");
            printf("\n Choose 1 for pre-order traversal");
            printf("\n Choose 2 for in-order traversal");
            printf("\n Choose 3 for post-order traversal");
            printf("\n Choose 0 for termination");
            printf("\n Choose type of traversal : ");
            int type;
            scanf("%d", &type);
            switch (type)
            {
            case 1:
                preorder_traversal(ptr);
                break;
            case 2:
                inorder_traversal(ptr);
                break;
            case 3:
                postorder_traversal(ptr);
                break;
            case 0:
                printf("\n Terminated");
                exit(0);
            default:
                printf("\n INVALID CHOICE ");
            }
        }
    }
    else
    {
        printf("\n Invalid Choice");
    }
}
struct node *create(void)
{
    int data;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter -1 for no node. Enter data of node : ");
    scanf("%d", &data);
    if (data == -1)
    {
        free(ptr);
        return NULL;
    }
    ptr->data = data;
    printf("\n Enter left child of %d", data);
    ptr->lchild = create();
    printf("\n Enter right child of %d", data);
    ptr->rchild = create();
    return ptr;
}
void preorder_traversal(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    printf("%d ", ptr->data);
    preorder_traversal(ptr->lchild);
    preorder_traversal(ptr->rchild);
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
void postorder_traversal(struct node *ptr)
{
    if (ptr == NULL)
    {
        return;
    }
    postorder_traversal(ptr->lchild);
    postorder_traversal(ptr->rchild);
    printf("%d ", ptr->data);
}
void preorder_traversalc(struct nodec *ptrc)
{
    if (ptrc == NULL)
    {
        return;
    }
    printf("%c ", ptrc->datac);
    preorder_traversalc(ptrc->lchildc);
    preorder_traversalc(ptrc->rchildc);
}
void inorder_traversalc(struct nodec *ptrc)
{
    if (ptrc == NULL)
    {
        return;
    }
    inorder_traversalc(ptrc->lchildc);
    printf("%c ", ptrc->datac);
    inorder_traversalc(ptrc->rchildc);
}
void postorder_traversalc(struct nodec *ptrc)
{
    if (ptrc == NULL)
    {
        return;
    }
    postorder_traversalc(ptrc->lchildc);
    postorder_traversalc(ptrc->rchildc);
    printf("%c ", ptrc->datac);
}
struct nodec *createc(void)
{
    char datac;
    struct nodec *ptrc = (struct nodec *)malloc(sizeof(struct nodec));
    printf("\n Enter 0 for no node. Enter data of node : ");
    scanf(" %c", &datac);
    if (datac == '0')
    {
        free(ptrc);
        return NULL;
    }
    ptrc->datac = datac;
    printf("\n Enter left child of %c", datac);
    ptrc->lchildc = createc();
    printf("\n Enter right child of %c", datac);
    ptrc->rchildc = createc();
    return ptrc;
}
