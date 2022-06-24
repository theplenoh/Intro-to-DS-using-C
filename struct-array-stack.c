#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_STACK_SIZE 50
#define MAX_STRING 50

typedef struct
{
    int studentNo;
    char studentName[MAX_STRING];
    char homeAddr[MAX_STRING];
} Elem;
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
        fprintf(stdout, "Msg: item pushed successfully!\n");
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
        fprintf(stdout, "Msg: item being popped!\n");
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
    Elem rec1, rec2;

    rec1.studentNo = 20053001;
    strcpy(rec1.studentName, "Hong, Gil-dong");
    strcpy(rec1.homeAddr, "Jamsil, Seoul");

    push(rec1);

    rec2 = pop();
    printf("Student No.: %d\n", rec2.studentNo);
    printf("Student name: %s\n", rec2.studentName);
    printf("Home address: %s\n", rec2.homeAddr);

    return 0;
}
