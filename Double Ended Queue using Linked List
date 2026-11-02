/* This code shows a double ended queue implemented using a Doubly Linked List.
   Memory is allocated dynamically, so there is no fixed maximum size.
   Operations can be performed on both ends. */
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
void insert_deque_rear(void);
void insert_deque_front(void);
void delete_deque_rear(void);
void delete_deque_front(void);
void display_deque(void);
int main()
{
    for (;;)
    {
        int choice;
        printf("\n --- Deque Menu ---");
        printf("\n 1. Insert an element at rear");
        printf("\n 2. Insert an element at front");
        printf("\n 3. Delete an element from rear");
        printf("\n 4. Delete an element from front");
        printf("\n 5. Display the queue");
        printf("\n 6. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_deque_rear();
            break;
        case 2:
            insert_deque_front();
            break;
        case 3:
            delete_deque_rear();
            break;
        case 4:
            delete_deque_front();
            break;
        case 5:
            display_deque();
            break;
        case 6:
            printf("\n Terminated\n");
            exit(0);
        default:
            printf("\n Invalid choice. Please try again.");
        }
    }
    return 0;
}
void insert_deque_rear(void)
{
    int data;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\n Memory allocation failed. Queue is full.");
        return;
    }
    printf("\n Enter the data to be inserted at rear: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    if (front == NULL)
    {
        newNode->prev = NULL;
        front = rear = newNode;
    }
    else
    {
        newNode->prev = rear;
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n Element %d inserted at the rear.", rear->data);
}
void insert_deque_front(void)
{
    int data;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\n Memory allocation failed. Queue is full.");
        return;
    }
    printf("\n Enter the data to be inserted at front: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->prev = NULL;
    if (front == NULL)
    {
        newNode->next = NULL;
        front = rear = newNode;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
    }
    printf("\n Element %d inserted at the front.", front->data);
}
void delete_deque_rear(void)
{
    if (rear == NULL)
    {
        printf("\n Queue is empty. Cannot delete element.");
        return;
    }
    struct Node *temp = rear;
    printf("\n Element %d deleted from the rear.", temp->data);
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        rear = rear->prev;
        rear->next = NULL;
    }
    free(temp);
}
void delete_deque_front(void)
{
    if (front == NULL)
    {
        printf("\n Queue is empty. Cannot delete element.");
        return;
    }
    struct Node *temp = front;
    printf("\n Element %d deleted from the front.", temp->data);
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        front->prev = NULL;
    }
    free(temp);
}
void display_deque(void)
{
    if (front == NULL)
    {
        printf("\n Queue is empty.");
        return;
    }
    struct Node *temp = front;
    printf("\n Queue elements (Front to Rear): ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
