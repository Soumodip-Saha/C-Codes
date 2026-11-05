#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int data;
    struct stack *next; // Self refereential structure
} s;
struct stack *stack_top = NULL;
void push(void);
void pop(void);
void peek(void);
void display(void);
int main()
{
    for (;;)
    {
        int choice;
        printf("\n Choose 1 to push element on the stack");
        printf("\n Choose 2 to pop element from the stack");
        printf("\n Choose 3 to peek element from the stack");
        printf("\n Choose 4 to display the stack");
        printf("\n Choose 5 to exit the program");
        printf("\n Enter choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("\n Terminated \n");
            exit(0);
        default:
            printf("\n Invalid Choice ");
        }
    }
}
void push()
{
    int data;
    struct stack *ptr;
    ptr = (struct stack *)malloc(sizeof(struct stack));
    if (ptr == NULL)
    {
        printf("\n Memory Allocation Failed");
        return;
    }
    printf("\n Enter the data to be pushed on the stack : ");
    scanf("%d", &data);
    ptr->data = data;
    ptr->next = stack_top;
    stack_top = ptr;
    printf("\n Push Successfull");
    /*Line 59 and 60 can be written as :
    if(stack_top == NULL)
     {
      ptr->next = NULL;
      stack_top =ptr;
     }
    else
     {
      ptr->next = stack_top;
      stack_top = ptr;
     }
      */
}
void pop()
{
    struct stack *ptr;
    if (stack_top == NULL)
    {
        printf("\n Stack is empty. ");
        return;
    }
    ptr = stack_top;
    stack_top = ptr->next;
    printf("\n Element %d popped from the stack", ptr->data);
    free(ptr);
}
void peek()
{
    if (stack_top == NULL)
    {
        printf("\n Stack is empty. ");
        return;
    }
    printf("\n Element %d is at the top of the stack", stack_top->data);
}
void display()
{
    struct stack *ptr;
    if (stack_top == NULL)
    {
        printf("\n Stack is empty. ");
        return;
    }
    ptr = stack_top;
    printf("\n Stack elements are : ");
    printf("\n Stack Top -> ");
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
