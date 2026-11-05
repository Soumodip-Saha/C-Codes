/*This code shows a circular queue.
  Deleted spaces can be reused.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
void insert_cqueue(void);
void delete_cqueue(void);
void display_cqueue(void);
struct cqueue
{
    int arr[MAX];
    int front, rear;
} cq;
int main()
{
    cq.front = cq.rear = -1;
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
            exit(0);
        default:
            printf("\n Invalid choice ");
        }
    }
}
void insert_cqueue(void)
{
    int data;
    if ((cq.front == 0 && cq.rear == MAX - 1) || (cq.front == cq.rear + 1))
    {
        printf("\n Queue is full. Cannot insert new element. ");
        return;
    }
    printf("\n Enter the data to be inserted into the queue: ");
    scanf("%d", &data);
    if (cq.front == -1)
    {
        cq.front = 0;
        cq.rear = 0;
    }
    else if (cq.rear == MAX - 1)
        cq.rear = 0;
    else
        cq.rear++;
    cq.arr[cq.rear] = data;
    printf("\n Element %d inserted into the queue. ", data);
}
void delete_cqueue(void)
{
    if (cq.front == -1)
    {
        printf("\n Queue is empty. Cannot delete element. ");
        return;
    }
    printf("\n Element %d deleted from the queue. ", cq.arr[cq.front]);
    if (cq.front == cq.rear)
    {
        cq.front = -1;
        cq.rear = -1;
    }
    else if (cq.front == MAX - 1)
    {
        cq.front = 0;
    }
    else
    {
        cq.front++;
    }
}
void display_cqueue(void)
{
    int i;
    if (cq.front == -1)
    {
        printf("\n Queue is empty. ");
        return;
    }
    printf("\n Queue elements: ");
    if (cq.front <= cq.rear)
    {
        for (i = cq.front; i <= cq.rear; i++)
            printf("%d ", cq.arr[i]);
    }
    else
    {
        for (i = cq.front; i < MAX; i++)
            printf("%d ", cq.arr[i]);
        for (i = 0; i <= cq.rear; i++)
            printf("%d ", cq.arr[i]);
    }
}
