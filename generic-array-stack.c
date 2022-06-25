#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_STACK_SIZE 50

typedef int Elem;
typedef struct {
    Elem stack[MAX_STACK_SIZE];
    int top;
} StackType;

void init(StackType *s)
{
    s->top = -1;
}

int isEmpty(StackType *s)
{
    if (s->top == -1)
        return TRUE;
    else
        return FALSE;
}

int isFull(StackType *s)
{
    if (s->top == (MAX_STACK_SIZE-1))
        return TRUE;
    else
        return FALSE;
}

void push(StackType *s, Elem item)
{
    if (isFull(s))
    {
        fprintf(stderr, "Error: stack overflow\n");
        exit(1);
    }
    else
    {
        s->stack[++(s->top)] = item;
        fprintf(stdout, "Msg: item pushed successfully!\n");
    }
}

Elem pop(StackType *s)
{
    if (isEmpty(s))
    {
        fprintf(stderr, "Error: stack empty\n");
        exit(1);
    }
    else
    {
        fprintf(stdout, "Msg: item being popped!\n");
        return s->stack[(s->top)--];
    }
}

Elem peek(StackType *s)
{
    if (isEmpty(s))
    {
        fprintf(stderr, "Error: stack empty\n");
        exit(1);
    }
    else
    {
        return s->stack[s->top];
    }
}

int main()
{
    StackType s;

    init(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("The stack: %s\n", isEmpty(&s)? "is empty":"is not empty");

    return 0;
}
