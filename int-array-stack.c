#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_STACK_SIZE 50
typedef int Elem;
Elem stack[MAX_STACK_SIZE];
int top = -1;

int isEmpty()
{
    if (top == -1)
        return TRUE;
    else
        return FALSE;
}

int isFull()
{
    if (top == (MAX_STACK_SIZE-1))
        return TRUE;
    else
        return FALSE;
}

void push(Elem item)
{
    if (isFull())
    {
        fprintf(stderr, "Error: stack overflow\n");
        exit(1);
    }
    else
    {
        stack[++top] = item;
    }
}

Elem pop()
{
    if (isEmpty())
    {
        fprintf(stderr, "Error: stack empty\n");
        exit(1);
    }
    else
    {
        return stack[top--];
    }
}

Elem peek()
{
    if (isEmpty())
    {
        fprintf(stderr, "Error: stack empty\n");
        exit(1);
    }
    else
    {
        return stack[top];
    }
}

int main()
{
    push(4);
    push(5);
    push(6);
    printf("Pop! %d\n", pop());
    printf("Pop! %d\n", pop());
    printf("Pop! %d\n", pop());
    printf("The stack: %s\n", isEmpty()? "is empty":"is not empty");

    return 0;
}
