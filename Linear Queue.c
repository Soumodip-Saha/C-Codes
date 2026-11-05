/*This program shows the various
  functions of a queue.
  DISADVANTAGE :
  Cannot use free space.
  In linear queue, the free space being created
  by deleting elements cannot be reutilised */
#include <stdio.h>
#include <stdlib.h>
#define MAX 8
void insert_queue();
void delete_queue();
void display_queue();
struct queue
{
    int arr[MAX];
    int front;
    int rear;
};
struct queue q;
int main()
{
    q.front = q.rear = -1;
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
            insert_queue();
            break;
        case 2:
            delete_queue();
            break;
        case 3:
            display_queue();
            break;
        case 4:
            exit(0);
        default:
            printf("\n Invalid choice ");
        }
    }
}
void insert_queue()
{
    int data;
    if (q.rear == MAX - 1)
    {
        printf("\n Queue is full. Cannot insert new element. ");
        return;
    }
    printf("\n Enter the data to be inserted into the queue: ");
    scanf("%d", &data);
    if (q.front == -1)
    {
        q.front = 0;
    }
    q.rear++;
    q.arr[q.rear] = data;
    printf("\n Element %d inserted into the queue. ", data);
}
void delete_queue()
{
    if (q.front == -1 || q.front == q.rear + 1)
    {
        printf("\n Queue is Empty. Cannot delete any element !");
        return;
    }
    printf("\n %d element deleted from the queue", q.arr[q.front]);
    q.front++;
}
void display_queue()
{
    if (q.front == -1 || q.front > q.rear)
    {
        printf("\n Queue is empty. ");
        return;
    }
    printf("\n Queue elements: ");
    for (int i = q.front; i <= q.rear; i++)
    {
        printf("%d ", q.arr[i]);
    }
}
