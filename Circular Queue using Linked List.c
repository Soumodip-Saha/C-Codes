/* This code shows a circular queue implemented using a Circular Linked List.
   Memory is dynamically allocated, removing the fixed size limitation. */
#include <stdio.h>
#include <stdlib.h>
void insert_cqueue(void);
void delete_cqueue(void);
void display_cqueue(void);
struct Node
{
    int data;
    struct Node *next;
};
struct Node *front = NULL;
struct Node *rear = NULL;
int main()
{
    for (;;)
    {
        int choice;
        printf("\n Choose 1 to insert an element into the queue");
        printf("\n Choose 2 to delete element from queue");
        printf("\n Choose 3 to display the queue");
        printf("\n Choose 4 to exit the program");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_cqueue();
            break;
        case 2:
            delete_cqueue();
            break;
        case 3:
            display_cqueue();
            break;
        case 4:
            printf("\n Terminated\n");
            exit(0);
        default:
            printf("\n Invalid choice ");
        }
    }
    return 0;
}
void insert_cqueue(void)
{
    int data;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\n Memory allocation failed. Cannot insert element. ");
        return;
    }
    printf("\n Enter the data to be inserted into the queue: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
        newNode->next = front;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    printf("\n Element %d inserted into the queue. ", data);
}
void delete_cqueue(void)
{
    if (front == NULL)
    {
        printf("\n Queue is empty. Cannot delete element. ");
        return;
    }
    struct Node *temp = front;
    printf("\n Element %d deleted from the queue. ", temp->data);
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }
    free(temp);
}
void display_cqueue(void)
{
    if (front == NULL)
    {
        printf("\n Queue is empty. ");
        return;
    }
    struct Node *temp = front;
    printf("\n Queue elements: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);
    printf("%d (front)\n", temp->data);
}
