#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void append(struct Node **head_ref, int new_data);
void bubbleSort(struct Node *head);
int binarySearch(struct Node *head, int target);
struct Node *getMiddle(struct Node *start, struct Node *last);
void printList(struct Node *head);
void freeList(struct Node *head);
int main()
{
    int n, target, result;
    struct Node *head = NULL;
    printf("\n Enter the number of elements: ");
    scanf("%d", &n);
    printf("\n Enter %d integers (in any order):", n);
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        append(&head, val);
    }
    bubbleSort(head);
    printf("\n The auto-arranged (sorted) linked list is: ");
    printList(head);
    printf("\n Enter the element to search for: ");
    scanf("%d", &target);
    result = binarySearch(head, target);
    if (result == -1)
    {
        printf("\n Element %d is not present in the list.", target);
    }
    else
    {
        printf("\n Element %d found at index %d.", target, result);
    }
    freeList(head);
    return 0;
}
void append(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}
void bubbleSort(struct Node *head)
{
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;
    if (head == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = head;
        while (ptr1->next != lptr)
        {
            if (ptr1->data > ptr1->next->data)
            {
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
struct Node *getMiddle(struct Node *start, struct Node *last)
{
    if (start == NULL)
        return NULL;
    struct Node *slow = start;
    struct Node *fast = start->next;
    while (fast != last)
    {
        fast = fast->next;
        if (fast != last)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}
int binarySearch(struct Node *head, int target)
{
    struct Node *start = head;
    struct Node *last = NULL;
    while (last == NULL || last != start)
    {
        struct Node *mid = getMiddle(start, last);
        if (mid == NULL)
            return -1;
        if (mid->data == target)
        {
            int index = 0;
            struct Node *temp = head;
            while (temp != mid)
            {
                index++;
                temp = temp->next;
            }
            return index;
        }
        else if (mid->data < target)
        {
            start = mid->next;
        }
        else
        {
            last = mid;
        }
    }
    return -1;
}
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void freeList(struct Node *head)
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
