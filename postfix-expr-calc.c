#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_STK_SZ 100

typedef char Elem;
typedef struct {
    Elem stack[MAX_STK_SZ];
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
    if (s->top == (MAX_STK_SZ - 1))
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
        fprintf(stdout, "Msg: item pushed succesfully!\n");
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

int eval(char exp[])
{
    int op1, op2, value;
    int i=0;
    int len = strlen(exp);

    char ch;
    StackType s;
    init(&s);

    for (i=0; i<len; i++)
    {
        ch = exp[i];
        if ( ch != '+' && ch != '-' && ch != '*' && ch != '/' )
        {
            value = ch - '0';
            push(&s, value);
        }
        else
        {
            op2 = pop(&s);
            op1 = pop(&s);

            switch (ch)
            {
                case '+': push(&s, op1+op2); break;
                case '-': push(&s, op1-op2); break;
                case '*': push(&s, op1*op2); break;
                case '/': push(&s, op1/op2); break;
            }
        }
    }
    return pop(&s);
}

int main()
{
    int result;

    printf("후위표기식은 82/3-32*+\n");
    result = eval("82/3-32*+");
    printf("결과값은 %d\n", result);
}
