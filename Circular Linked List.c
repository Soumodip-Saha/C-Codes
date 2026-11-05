#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
// Global head pointer
struct Node *head = NULL;
// Function Prototypes
void append(void);
void insert_at_beginning_of_cll(void);
void insert_at_beginning_of_node(void);
void insert_at_end_of_node(void);
void delete_from_end_of_cll(void);
void delete_from_beginning_of_cll(void);
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
        printf("\n--- Circular Linked List Menu ---");
        printf("\n Choose 1 to append on a circular linked list");
        printf("\n Choose 2 to insert element at the beginning of the circular linked list");
        printf("\n Choose 3 to insert element at the beginning (before) of a node");
        printf("\n Choose 4 to insert element at the end (after) of a node");
        printf("\n Choose 5 to delete element from the end of the circular linked list");
        printf("\n Choose 6 to delete element from the beginning of the circular linked list");
        printf("\n Choose 7 to delete element from the beginning (before) of a node");
        printf("\n Choose 8 to delete element from the end (after) of a node");
        printf("\n Choose 9 to delete the circular linked list");
        printf("\n Choose 10 to search an element in the circular linked list");
        printf("\n Choose 11 to search and delete an element in the circular linked list");
        printf("\n Choose 12 to sort the circular linked list in ascending order");
        printf("\n Choose 13 to reverse the circular linked list");
        printf("\n Choose 14 to display the circular linked list");
        printf("\n Choose 0 to exit the program");
        printf("\n Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("\n Terminated \n");
            exit(0);
        case 1:
            append();
            break;
        case 2:
            insert_at_beginning_of_cll();
            break;
        case 3:
            insert_at_beginning_of_node();
            break;
        case 4:
            insert_at_end_of_node();
            break;
        case 5:
            delete_from_end_of_cll();
            break;
        case 6:
            delete_from_beginning_of_cll();
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
// 1. Append at the end of the CLL
void append(void)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to append: ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Node appended successfully.\n");
}
// 2. Insert at the beginning of the CLL
void insert_at_beginning_of_cll(void)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter data to insert at beginning: ");
    scanf("%d", &newNode->data);

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != head)
            temp = temp->next;
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Node inserted at beginning successfully.\n");
}
// 3. Insert before a specific node
void insert_at_beginning_of_node(void)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    int val;
    printf("Enter the node value before which you want to insert: ");
    scanf("%d", &val);
    if (head->data == val)
    {
        insert_at_beginning_of_cll();
        return;
    }
    struct Node *temp = head;
    while (temp->next != head && temp->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next->data == val)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter data to insert: ");
        scanf("%d", &newNode->data);
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted successfully.\n");
    }
    else
    {
        printf("Node with value %d not found.\n", val);
    }
}
// 4. Insert after a specific node
void insert_at_end_of_node(void)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    int val;
    printf("Enter the node value after which you want to insert: ");
    scanf("%d", &val);
    struct Node *temp = head;
    do
    {
        if (temp->data == val)
        {
            struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
            printf("Enter data to insert: ");
            scanf("%d", &newNode->data);
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node inserted successfully.\n");
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node with value %d not found.\n", val);
}
// 5. Delete from the end of the CLL
void delete_from_end_of_cll(void)
{
    if (head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp = head, *prev = NULL;
        while (temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
    }
    printf("Last node deleted successfully.\n");
}
// 6. Delete from the beginning of the CLL
void delete_from_beginning_of_cll(void)
{
    if (head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        struct Node *temp = head, *last = head;
        while (last->next != head)
            last = last->next;
        head = head->next;
        last->next = head;
        free(temp);
    }
    printf("First node deleted successfully.\n");
}
// 7. Delete node before a specific node
void delete_from_beginning_of_node(void)
{
    if (head == NULL || head->next == head)
    {
        printf("Not enough nodes to perform this operation.\n");
        return;
    }
    int val;
    printf("Enter the node value before which you want to delete: ");
    scanf("%d", &val);

    if (head->next->data == val)
    {
        delete_from_beginning_of_cll();
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != head && temp->next->next->data != val)
    {
        temp = temp->next;
    }
    if (temp->next->next->data == val)
    {
        struct Node *toDelete = temp->next;
        temp->next = toDelete->next;
        free(toDelete);
        printf("Node deleted successfully.\n");
    }
    else
    {
        printf("Node with value %d not found, or it is the head node.\n", val);
    }
}
// 8. Delete node after a specific node
void delete_from_end_of_node(void)
{
    if (head == NULL || head->next == head)
    {
        printf("Not enough nodes to perform this operation.\n");
        return;
    }
    int val;
    printf("Enter the node value after which you want to delete: ");
    scanf("%d", &val);
    struct Node *temp = head;
    do
    {
        if (temp->data == val)
        {
            struct Node *toDelete = temp->next;
            if (toDelete == head)
            {
                delete_from_beginning_of_cll();
            }
            else
            {
                temp->next = toDelete->next;
                free(toDelete);
            }
            printf("Node deleted successfully.\n");
            return;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node with value %d not found.\n", val);
}
// 9. Clear the entire list
void clear(void)
{
    if (head == NULL)
    {
        printf("List is already empty.\n");
        return;
    }
    struct Node *temp = head->next, *nextNode;
    while (temp != head)
    {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }
    free(head);
    head = NULL;
    printf("List cleared completely.\n");
}
// 10. Search for an element
void search(void)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    int val, pos = 1;
    printf("Enter element to search: ");
    scanf("%d", &val);
    struct Node *temp = head;
    do
    {
        if (temp->data == val)
        {
            printf("Element %d found at position %d.\n", val, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element not found in the list.\n");
}
// 11. Search and delete a specific element
void search_and_delete(void)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    int val;
    printf("Enter element to delete: ");
    scanf("%d", &val);
    if (head->data == val)
    {
        delete_from_beginning_of_cll();
        return;
    }
    struct Node *temp = head, *prev = NULL;
    do
    {
        if (temp->data == val)
        {
            prev->next = temp->next;
            free(temp);
            printf("Element %d deleted successfully.\n", val);
            return;
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
    printf("Element not found.\n");
}
// 12. Sort the circular linked list (Bubble Sort)
void sort(void)
{
    if (head == NULL || head->next == head)
    {
        return;
    }
    struct Node *current, *index;
    int temp_data;
    current = head;
    do
    {
        index = current->next;
        while (index != head)
        {
            if (current->data > index->data)
            {
                temp_data = current->data;
                current->data = index->data;
                index->data = temp_data;
            }
            index = index->next;
        }
        current = current->next;
    } while (current->next != head);
    printf("List sorted successfully.\n");
}
// 13. Reverse the circular linked list
void reverse(void)
{
    if (head == NULL || head->next == head)
    {
        return;
    }
    struct Node *prev = NULL, *current = head, *next = NULL, *last = head;
    // Find the last node
    while (last->next != head)
    {
        last = last->next;
    }
    prev = last; // Previous of head will be the last node
    do
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != head);
    head = prev; // Update head
    printf("List reversed successfully.\n");
}
// 14. Display the circular linked list
void display(void)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node *temp = head;
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD: %d)\n", head->data);
}
