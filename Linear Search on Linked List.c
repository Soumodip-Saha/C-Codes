#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void append(struct Node **head_ref, int);
int main()
{
    int n, target;
    int index = -1;
    int currentIndex = 0;
    struct Node *head = NULL;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        append(&head, val);
    }
    printf("Enter the element to search for: ");
    scanf("%d", &target);
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == target)
        {
            index = currentIndex;
            break;
        }
        current = current->next;
        currentIndex++;
    }
    if (index != -1)
    {
        printf("Element %d found at index %d.\n", target, index);
    }
    else
    {
        printf("Element %d is not present in the linked list.\n", target);
    }
    current = head;
    while (current != NULL)
    {
        struct Node *temp = current->next;
        free(current);
        current = temp;
    }

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
