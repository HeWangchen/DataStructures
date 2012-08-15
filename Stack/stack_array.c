#include <stdio.h>
#include <stdlib.h>
#define MIN_STACK_SIZE 5

typedef struct StackRecord *Stack;

struct StackRecord
{
    int Capacity;
    int Top;
    int *Array;
};

int IsEmpty(Stack S);

int IsFull(Stack S);

Stack CreateStack(int MaxElements);

void DisposeStack(Stack S);

void MakeEmpty(Stack S);

void Push(int X,Stack S);

int Top(Stack S);

void Pop(Stack S);

int PopAndTop(Stack S);

int IsEmpty(Stack S)
{
    return S->Top == 0;
}

int IsFull(Stack S)
{
    return S->Top == S->Capacity;
}

void MakeEmpty(Stack S)
{
    S->Top = 0;
}

Stack CreateStack(int MaxElements)
{
    if(MaxElements < MIN_STACK_SIZE)
    {
        fprintf(stderr,"Can't create a Stack less than %d elements\n",MIN_STACK_SIZE);
        exit(1);
    }
    else
    {
        Stack S = malloc(sizeof(struct StackRecord));
        if(S == NULL)
        {
            fprintf(stderr,"Out of space!\n");
            exit(1);
        }
        S->Array = malloc(sizeof(int)*MaxElements);
        S->Capacity = MaxElements;
        MakeEmpty(S);
        return S;
    }
}

void DisposeStack(Stack S)
{
    if(S != NULL)
    {
        free(S->Array);
        free(S);
    }
}

void Push(int X,Stack S)
{
    if(IsFull(S))
    {
        fprintf(stderr,"The Stack Is Full!\n");
    }
    else
    {
        S->Array[S->Top++] = X;
    }
}

int Top(Stack S)
{
    if(!IsEmpty(S))
    {
        int tmp = S->Top - 1;
        return S->Array[tmp];
    }
    else
    {
        fprintf(stderr,"The Stack Is Empty!\n");
        exit(1);
    }
}

void Pop(Stack S)
{
    if(!IsEmpty(S))
    {
        --(S->Top);
    }
    else
    {
        fprintf(stderr ,"The Stack Is Empty!\n");
        exit(1);
    }
}

int main()
{
    Stack S = CreateStack(10);
    int i;
    for(i = 0; i < 10; i++)
    {
        Push(i,S);
    }
    while(!IsEmpty(S))
    {
        printf("%d ",Top(S));
        Pop(S);
    }
    printf("\n");
    return 0;
}

