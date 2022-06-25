#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_STACK_SIZE 50

typedef char Elem;
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

int checkMatching(const char* input)
{
    char ch, openCh;
    int i;
    int n=strlen(input);

    StackType s;
    init(&s);

    for (i=0; i<n; i++)
    {
        ch = input[i];
        switch (ch)
        {
            case '(':
            case '{':
            case '[':
                push(&s, ch);
                break;
            case ')':
            case '}':
            case ']':
                if (isEmpty(&s))
                    return FALSE;
                else
                {
                    openCh = pop(&s);
                    if ((openCh == '(' && ch != ')') || (openCh == '[' && ch != ']') || (openCh == '{' && ch != '}'))
                        return FALSE;
                }
                break;
        }
    }
    if (!isEmpty(&s)) return FALSE;

    return TRUE;
}

int main()
{
    char expr[] = "{ A[(i+1)]=0; }";

    printf("Parenthesis match test: %s!\n", checkMatching(expr)? "pass":"fail");

    return 0;
}
