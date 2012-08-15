#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef struct Node
{
    int Element;
    PtrToNode Next;
};

int IsEmpty(Stack S);
Stack CreateStack();
void DispossStack(Stack S);
void MakeEmpty(Stack S);
void Push(int X,Stack S);
int Top(Stack S);
void Pop(Stack S);

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack()
{
    Stack S = (Stack)malloc(sizeof(struct Node));
    if(S == NULL)
    {
        printf("No enough memory!\n");
        return NULL;
    }
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void MakeEmpty(Stack S)
{
    if(S == NULL)
    {
        printf("Use CreateStack First!\n");
    }
    else 
    {
        while(!IsEmpty(S))
        {
            Pop(S);
        }
    }
}


void Push(int X,Stack S)
{
    PtrToNode Tmp;
    Tmp =(Stack)malloc(sizeof(struct Node));

    if(Tmp != NULL)
    {
        Tmp->Element = X;
        Tmp->Next = S->Next;
        S->Next = Tmp;
    }
    else 
    {
        printf("Out of space!\n");
    }
}
    
void Pop(Stack S)
{
    if(IsEmpty(S))
    {
        printf("The stack is Empty!");
    }
    else
    {
        PtrToNode Tmp = S->Next;
        S->Next = Tmp->Next;
        free (Tmp);
    }
}

int Top(Stack S)
{
    if(IsEmpty(S))
    {
        printf("The stack is empty!\n");
        return 0;
    }
    else
    {
        return S->Next->Element;
    }
}

int main(void)
{
    Stack S = CreateStack();
    int i;
    for(i = 0; i < 5 ; i++)
    {
        Push(i,S);
    }
    while(!IsEmpty(S))
    {
        printf("%d\n",Top(S));
        Pop(S);
    }
    return 0;
}
