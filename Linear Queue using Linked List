#include <stdio.h>
#include <stdlib.h>
void insert_queue();
void delete_queue();
void display_queue();
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
        printf("\n --- Queue Menu ---");
        printf("\n 1. Insert an element into the queue");
        printf("\n 2. Delete element from queue");
        printf("\n 3. Display the queue");
        printf("\n 4. Exit the program");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert_queue();
            break;
        case 2:
            delete_queue();
            break;
        case 3:
            display_queue();
            break;
        case 4:
            printf("\n Terminated\n");
            exit(0);
        default:
            printf("\n Invalid choice. Please try again.");
        }
    }
    return 0;
}
void insert_queue()
{
    int data;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("\n Memory allocation failed. Queue is full.");
        return;
    }
    printf("\n Enter the data to be inserted into the queue: ");
    scanf("%d", &data);
    newNode->data = data;
    newNode->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("\n Element %d inserted into the queue. ", data);
}
void delete_queue()
{
    struct Node *temp;
    if (front == NULL)
    {
        printf("\n Queue is Empty. Cannot delete any element!");
        return;
    }
    temp = front;
    printf("\n Element %d deleted from the queue.", front->data);
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    free(temp);
}
void display_queue()
{
    struct Node *temp = front;

    if (front == NULL)
    {
        printf("\n Queue is empty. ");
        return;
    }
    printf("\n Queue elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
