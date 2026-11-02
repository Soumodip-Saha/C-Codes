/*This code shows a double ended queue.
  Deleted spaces can be reused.
  Operation can be performed on both ends.*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 6
void insert_deque_rear(void);
void insert_deque_front(void);
void delete_deque_rear(void);
void delete_deque_front(void);
void display_deque(void);
struct deque
{
    int arr[MAX];
    int front, rear;
} dq;
int main()
{
    dq.front = dq.rear = -1;
    for (;;)
    {
        int choice;
        printf("\n Choose 1 to insert an element into the queue at rear");
        printf("\n Choose 2 to insert an element into the queue at front");
        printf("\n Choose 3 to delete element from queue at rear");
        printf("\n Choose 4 to delete element from queue at front");
        printf("\n Choose 5 to display the queue");
        printf("\n Choose 6 to exit the program");
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
            printf("\n Terminated");
            exit(0);
        default:
            printf("\n Invalid choice ");
        }
    }
}
void insert_deque_rear(void)
{
    int data;
    if ((dq.front == 0 && dq.rear == MAX - 1) || (dq.front == dq.rear + 1))
    {
        printf("\n Queue is full. Cannot insert new element. ");
        return;
    }
    printf("\n Enter the data to be inserted into the queue: ");
    scanf("%d", &data);
    if (dq.front == -1)
    {
        dq.front = 0;
        dq.rear = 0;
    }
    else if (dq.rear == MAX - 1)
    {
        dq.rear = 0;
    }
    else
    {
        dq.rear++;
    }
    dq.arr[dq.rear] = data;
    printf("\n Element %d inserted into the queue. ", dq.arr[dq.rear]);
}
void insert_deque_front(void)
{
    int data;
    if ((dq.front == 0 && dq.rear == MAX - 1) || (dq.front == dq.rear + 1))
    {
        printf("\n Queue is full. Cannot insert new element. ");
        return;
    }
    printf("\n Enter the data to be inserted into the queue: ");
    scanf("%d", &data);
    if (dq.front == -1)
    {
        dq.front = 0;
        dq.rear = 0;
    }
    else if (dq.front == 0)
    {
        dq.front = MAX - 1;
    }
    else
    {
        dq.front--;
    }
    dq.arr[dq.front] = data;
    printf("\n Element %d inserted into the queue. ", dq.arr[dq.front]);
}
void delete_deque_rear(void)
{
    if (dq.front == -1)
    {
        printf("\n Queue is empty. Cannot delete element. ");
        return;
    }
    printf("\n Element %d deleted from the queue. ", dq.arr[dq.rear]);
    if (dq.front == dq.rear)
    {
        dq.front = -1;
        dq.rear = -1;
    }
    else if (dq.rear == 0)
    {
        dq.rear = MAX - 1;
    }
    else
    {
        dq.rear--;
    }
}
void delete_deque_front(void)
{
    if (dq.front == -1)
    {
        printf("\n Queue is empty. Cannot delete element. ");
        return;
    }
    printf("\n Element %d deleted from the queue. ", dq.arr[dq.front]);
    if (dq.front == dq.rear)
    {
        dq.front = -1;
        dq.rear = -1;
    }
    else if (dq.front == MAX - 1)
    {
        dq.front = 0;
    }
    else
    {
        dq.front++;
    }
}
void display_deque(void)
{
    int i;
    if (dq.front == -1)
    {
        printf("\n Queue is empty. ");
        return;
    }
    printf("\n Queue elements: ");
    if (dq.front <= dq.rear)
    {
        for (i = dq.front; i <= dq.rear; i++)
            printf("%d ", dq.arr[i]);
    }
    else
    {
        for (i = dq.front; i < MAX; i++)
            printf("%d ", dq.arr[i]);
        for (i = 0; i <= dq.rear; i++)
            printf("%d ", dq.arr[i]);
    }
}
