#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
void create(void);
void insert_at_beginning_of_sll(void);
void insert_at_beginning_of_node(void);
void insert_at_end_of_node(void);
void delete(void);
void delete_from_beginning_of_sll(void);
void delete_from_beginning_of_node(void);
void delete_from_end_of_node(void);
void clear(void);
void search(void);
void search_and_delete(void);
void sort(void);
void reverse(void);
void display(void);
int main()
{
    for (;;)
    {
        int choice;
        printf("\n\n--- Singly Linked List Operations ---");
        printf("\n 1. Create a singly linked list (Append)");
        printf("\n 2. Insert element at the beginning");
        printf("\n 3. Insert element before a specific node");
        printf("\n 4. Insert element after a specific node");
        printf("\n 5. Delete element from the end");
        printf("\n 6. Delete element from the beginning");
        printf("\n 7. Delete element before a specific node");
        printf("\n 8. Delete element after a specific node");
        printf("\n 9. Delete the entire singly linked list");
        printf("\n 10. Search for an element");
        printf("\n 11. Search and delete an element");
        printf("\n 12. Sort the list in ascending order");
        printf("\n 13. Reverse the list");
        printf("\n 14. Display the list");
        printf("\n 0. Exit");
        printf("\n Enter choice: ");
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
            insert_at_beginning_of_sll();
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
            delete_from_beginning_of_sll();
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
    printf(" Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = NULL;
    if (start == NULL)
    {
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
    }
    printf("\n Node inserted successfully.");
}
void insert_at_beginning_of_sll(void)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\n Memory Allocation Failed");
        return;
    }
    printf(" Enter data: ");
    scanf("%d", &new_node->data);
    new_node->next = start;
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
    printf(" Enter the node data before which you want to insert: ");
    scanf("%d", &val);
    struct node *ptr = start;
    struct node *preptr = NULL;
    while (ptr != NULL && ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\n Node with data %d not found. Insertion not possible.", val);
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\n Memory Allocation Failed");
        return;
    }
    printf(" Enter data for the new node: ");
    scanf("%d", &new_node->data);
    if (preptr == NULL)
    {
        new_node->next = start;
        start = new_node;
    }
    else
    {
        preptr->next = new_node;
        new_node->next = ptr;
    }
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
    printf(" Enter the node data after which you want to insert: ");
    scanf("%d", &val);
    struct node *ptr = start;
    while (ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\n Node with data %d not found. Insertion not possible.", val);
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\n Memory Allocation Failed");
        return;
    }
    printf(" Enter data for the new node: ");
    scanf("%d", &new_node->data);
    new_node->next = ptr->next;
    ptr->next = new_node;
    printf("\n Node inserted after %d.", val);
}
void delete(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    struct node *ptr = start;
    struct node *preptr = NULL;
    if (ptr->next == NULL) // Only one node in the list
    {
        printf("\n Deleted node with data %d.", ptr->data);
        free(ptr);
        start = NULL;
        return;
    }
    while (ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    printf("\n Deleted node with data %d.", ptr->data);
    free(ptr);
}
void delete_from_beginning_of_sll(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    struct node *ptr = start;
    start = start->next;
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
    printf(" Enter the node data before which you want to delete: ");
    scanf("%d", &val);
    if (start->data == val)
    {
        printf("\n No node exists before %d to delete.", val);
        return;
    }
    struct node *ptr = start;
    struct node *preptr = NULL;
    struct node *prepreptr = NULL; // Tracks the node before preptr
    while (ptr != NULL && ptr->data != val)
    {
        prepreptr = preptr;
        preptr = ptr;
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\n Node with data %d not found.", val);
        return;
    }
    if (prepreptr == NULL) // Node to be deleted is the first node
    {
        start = start->next;
    }
    else
    {
        prepreptr->next = ptr;
    }
    printf("\n Deleted node with data %d.", preptr->data);
    free(preptr);
}
void delete_from_end_of_node(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    int val;
    printf(" Enter the node data after which you want to delete: ");
    scanf("%d", &val);
    struct node *ptr = start;
    while (ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        printf("\n Node with data %d not found.", val);
        return;
    }
    if (ptr->next == NULL)
    {
        printf("\n No node exists after %d to delete.", val);
        return;
    }
    struct node *temp = ptr->next;
    ptr->next = temp->next;
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
    printf("\n Singly linked list cleared successfully.");
}
void search(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    int val, pos = 1, found = 0;
    printf(" Enter element to search: ");
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
    printf(" Enter element to search and delete: ");
    scanf("%d", &val);
    struct node *ptr = start;
    struct node *preptr = NULL;
    while (ptr != NULL)
    {
        if (ptr->data == val)
        {
            found = 1;
            break;
        }
        preptr = ptr;
        ptr = ptr->next;
    }
    if (!found)
    {
        printf("\n Element %d not found in the list.", val);
        return;
    }
    if (preptr == NULL) // Node to delete is the first node
    {
        start = ptr->next;
    }
    else
    {
        preptr->next = ptr->next;
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
    printf("\n Singly linked list sorted in ascending order.");
}
void display(void)
{
    if (start == NULL)
    {
        printf("\n List is empty.");
        return;
    }
    struct node *ptr = start;
    printf("\n Singly Linked List: ");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
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
    struct node *prev = NULL;
    struct node *current = start;
    struct node *next = NULL;
    while (current != NULL)
    {
        next = current->next; // Store next node
        current->next = prev; // Reverse current node's pointer
        prev = current;       // Move pointers one position ahead
        current = next;
    }
    start = prev; // Update start to the new first node
    printf("\n Singly linked list reversed successfully.");
}
