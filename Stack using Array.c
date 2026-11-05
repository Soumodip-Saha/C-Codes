/*Write a program in C to implement a stack using an array*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 6
struct stack
{
    int arr[MAX];
    int stack_top;
};
void push(struct stack *);
void pop(struct stack *);
void peek(struct stack *);
void display(struct stack *);
int main(void)
{
    struct stack s;
    int choice;
    s.stack_top = -1;
    while (1)
    {
        printf("\n\n** Menu driven stack.");
        printf("\nPress 1 for push()");
        printf("\nPress 2 for pop()");
        printf("\nPress 3 for peek()");
        printf("\nPress 4 for display()");
        printf("\nPress 5 for exit()");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&s);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            peek(&s);
            break;
        case 4:
            display(&s);
            break;
        case 5:
            exit(0);
        default:
            printf("\n Invalid Input");
        }
    }
    return 0;
}
void push(struct stack *stack_ptr)
{
    int data;
    if (stack_ptr->stack_top == MAX - 1)
    {
        printf("\n Stack is full");
        return;
    }
    stack_ptr->stack_top++;
    printf("\n Enter the value to be pushed on stack: ");
    scanf("%d", &data);
    stack_ptr->arr[stack_ptr->stack_top] = data;
    printf("\n The %d data is pushed on stack successfully", data);
}
void pop(struct stack *stack_ptr)
{
    if (stack_ptr->stack_top == -1)
    {
        printf("\n Stack is empty");
        return;
    }
    printf("\n %d popped from the stack", stack_ptr->arr[stack_ptr->stack_top]);
    stack_ptr->stack_top--;
}
void peek(struct stack *stack_ptr)
{
    if (stack_ptr->stack_top == -1)
    {
        printf("\n Stack is empty");
        return;
    }
    printf("\n %d peeked from the stack", stack_ptr->arr[stack_ptr->stack_top]);
}
void display(struct stack *stack_ptr)
{
    if (stack_ptr->stack_top == -1)
    {
        printf("\n Stack is empty");
        return;
    }
    printf("\n Elements in the stack are: ");
    for (int i = 0; i <= stack_ptr->stack_top; i++)
    {
        printf("%d ", stack_ptr->arr[i]);
    }
}
