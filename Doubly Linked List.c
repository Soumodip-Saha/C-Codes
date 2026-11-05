#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *previous;
    int data;
    struct node *next;
};
struct node *start = NULL;
void create(void);                     // inserts element at the end of an existing dll or creates a fresh if empty dll (append)
void insert_at_beginning_of_dll(void); // insertion before first node
void insert_at_beginning_of_node(void);
void insert_at_end_of_node(void);
void delete(void); // deletes element from the end of an existing dll
void delete_from_beginning_of_dll(void);
void delete_from_beginning_of_node(void); // not in assignment
void delete_from_end_of_node(void);       // not in assignment
void clear(void);                         // clears the entire dll (delete all)
void search(void);                        // not in assignment
void search_and_delete(void);
void sort(void); // sorts the dll in ascending order // not in assignment
void reverse(void);
void display(void);
int main()
{
    for (;;)
    {
        int choice;
        printf("\n Choose 1 to create a doubly linked list");
        printf("\n Choose 2 to insert element at the beginning of the doubly linked list");
        printf("\n Choose 3 to insert element at the beginning of a node of the doubly linked list");
        printf("\n Choose 4 to insert element at the end of a node of the doubly linked list");
        printf("\n Choose 5 to delete element from the end of the doubly linked list");
        printf("\n Choose 6 to delete element from the beginning of the doubly linked list");
        printf("\n Choose 7 to delete element from the beginning of a node");
        printf("\n Choose 8 to delete element from the end of a node");
        printf("\n Choose 9 to delete the doubly linked list");
        printf("\n Choose 10 to search an element in the doubly linked list");
        printf("\n Choose 11 to search and delete an element in the doubly linked list");
        printf("\n Choose 12 to sort the doubly linked list in ascending order");
        printf("\n Choose 13 to reverse the doubly linked list");
        printf("\n Choose 14 to display the doubly linked list");
        printf("\n Choose 0 to exit the program");
        printf("\n Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("\n Terminated \n");
            exit(0);
        case 1:
            create();
            break;
        case 2:
            insert_at_beginning_of_dll();
            break;
        case 3:
            insert_at_beginning_of_node();
            break;
        case 4:
            insert_at_end_of_node();
            break;
        case 5:
            delete();
            break;
        case 6:
            delete_from_beginning_of_dll();
            break;
        case 7:
            delete_from_beginning_of_node();
            break;
        case 8:
            delete_from_end_of_node();
            break;
        case 9:
            clear();
            break;
        case 10:
            search();
            break;
        case 11:
            search_and_delete();
            break;
        case 12:
            sort();
            break;
        case 13:
            reverse();
            break;
        case 14:
            display();
            break;
        default:
            printf("\n Invalid Choice ");
        }
    }
    return 0;
}
void create(void)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\n Memory Allocation Failed");
        return;
    }
    printf("\n Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (start == NULL)
    {
        new_node->previous = NULL;
        start = new_node;
    }
    else
    {
        struct node *ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->previous = ptr;
    }
    printf("\n Node inserted successfully.");
}
void insert_at_beginning_of_dll(void)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\n Memory Allocation Failed");
        return;
    }
    printf("\n Enter data: ");
    scanf("%d", &new_node->data);
    new_node->previous = NULL;
    new_node->next = start;
    if (start != NULL)
    {
        start->previous = new_node;
    }
    start = new_node;
    printf("\n Node inserted at the beginning.");
}
void insert_at_beginning_of_node(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    int val;
    printf("\n Enter the node data before which you want to insert: ");
    scanf("%d", &val);
    struct node *ptr = start;
    while (ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\n Node with data %d not found.", val);
        printf("\n Insertion not possible");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\n Memory Allocation Failed");
        return;
    }
    printf("\n Enter data for the new node: ");
    scanf("%d", &new_node->data);
    new_node->next = ptr;
    new_node->previous = ptr->previous;
    if (ptr->previous != NULL)
    {
        ptr->previous->next = new_node;
    }
    else
    {
        start = new_node;
    }
    ptr->previous = new_node;
    printf("\n Node inserted before %d.", val);
}
void insert_at_end_of_node(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    int val;
    printf("\n Enter the node data after which you want to insert: ");
    scanf("%d", &val);
    struct node *ptr = start;
    while (ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\n Node with data %d not found.", val);
        printf("\n Insertion not possible");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\n Memory Allocation Failed");
        return;
    }
    printf("\n Enter data for the new node: ");
    scanf("%d", &new_node->data);
    new_node->previous = ptr;
    new_node->next = ptr->next;
    if (ptr->next != NULL)
    {
        ptr->next->previous = new_node;
    }
    ptr->next = new_node;
    printf(" Node inserted after %d.\n", val);
}
void delete(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    struct node *ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr->previous != NULL)
    {
        ptr->previous->next = NULL;
    }
    else
    {
        start = NULL;
    }
    printf("\n Deleted node with data %d.", ptr->data);
    free(ptr);
}
void delete_from_beginning_of_dll(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    struct node *ptr = start;
    start = start->next;
    if (start != NULL)
    {
        start->previous = NULL;
    }
    printf("\n Deleted node with data %d from the beginning.", ptr->data);
    free(ptr);
}
void delete_from_beginning_of_node(void)
{
    if (start == NULL || start->next == NULL)
    {
        printf("\n List is empty or has only one node. Cannot delete before a node.");
        return;
    }
    int val;
    printf("\n Enter the node data before which you want to delete: ");
    scanf("%d", &val);
    struct node *ptr = start;
    while (ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\n Node with data %d not found.", val);
        printf("\n Deletion not possible");
        return;
    }
    if (ptr->previous == NULL)
    {
        printf("\n No node exists before %d to delete.", val);
        return;
    }
    struct node *temp = ptr->previous;
    if (temp->previous != NULL)
    {
        temp->previous->next = ptr;
    }
    else
    {
        start = ptr;
    }
    ptr->previous = temp->previous;
    printf("\n Deleted node with data %d.", temp->data);
    free(temp);
}
void delete_from_end_of_node(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    int val;
    printf("\n Enter the node data after which you want to delete: ");
    scanf("%d", &val);
    struct node *ptr = start;
    while (ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\n Node with data %d not found.", val);
        printf("\n Deletion not possible");
        return;
    }
    if (ptr->next == NULL)
    {
        printf("\n No node exists after %d to delete.", val);
        return;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->previous = ptr;
    }
    printf("\n Deleted node with data %d.", temp->data);
    free(temp);
}
void clear(void)
{
    if (start == NULL)
    {
        printf("\n List is already empty.");
        return;
    }
    struct node *ptr = start;
    while (ptr != NULL)
    {
        struct node *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    start = NULL;
    printf("\n Doubly linked list cleared successfully.");
}
void search(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    int val, pos = 1, found = 0;
    printf("\n Enter element to search: ");
    scanf("%d", &val);
    struct node *ptr = start;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            printf("\n Element %d found at position %d.", val, pos);
            found = 1;
        }
        ptr = ptr->next;
        pos++;
    }
    if (!found)
    {
        printf("\n Element %d not found in the list.", val);
    }
}
void search_and_delete(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    int val, found = 0;
    printf("\n Enter element to search and delete: ");
    scanf("%d", &val);
    struct node *ptr = start;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            found = 1;
            break;
        }
        ptr = ptr->next;
    }
    if (!found)
    {
        printf("\n Element %d not found in the list.", val);
        return;
    }
    if (ptr->previous != NULL)
    {
        ptr->previous->next = ptr->next;
    }
    else
    {
        start = ptr->next;
    }
    if (ptr->next != NULL)
    {
        ptr->next->previous = ptr->previous;
    }
    printf("\n Deleted node with data %d.", ptr->data);
    free(ptr);
}
void sort(void)
{
    if (start == NULL || start->next == NULL)
    {
        printf("\n List is empty or has only one node, no need to sort.");
        return;
    }
    struct node *ptr1, *ptr2;
    int temp;
    for (ptr1 = start; ptr1->next != NULL; ptr1 = ptr1->next)
    {
        for (ptr2 = ptr1->next; ptr2 != NULL; ptr2 = ptr2->next)
        {
            if (ptr1->data > ptr2->data)
            {
                temp = ptr1->data;
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
        }
    }
    printf("\n Doubly linked list sorted in ascending order.");
}
void display(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    struct node *ptr = start;
    printf("\n Doubly Linked List: NULL <--> ");
    while (ptr != NULL)
    {
        printf("%d <--> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
void reverse(void)
{
    if (start == NULL || start->next == NULL)
    {
        printf("\n List is empty or has only one node, no need to reverse.");
        return;
    }
    struct node *current = start;
    struct node *temp = NULL;
    while (current != NULL)
    {
        temp = current->previous;
        current->previous = current->next;
        current->next = temp;
        current = current->previous;
    }
    if (temp != NULL)
    {
        start = temp->previous;
    }
    printf("\n Doubly linked list reversed successfully.");
}
