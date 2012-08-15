#include <stdio.h>
#include <stdlib.h>
#define ElementType char

typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef struct Node
{
    ElementType Element;
    PtrToNode Next;
};

int IsEmpty(Stack S);
Stack CreateStack();
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X,Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

int IsEmpty(Stack S)
{
    return S->Next == NULL;
}

Stack CreateStack()
{
    Stack S = (PtrToNode)malloc(sizeof(struct Node));
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
    while(!IsEmpty(S))
    {
        Pop(S);
    }
}

void Push(ElementType X,Stack S)
{
    PtrToNode  Tmp;
    Tmp = (PtrToNode)malloc(sizeof(struct Node));
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
    if(!IsEmpty(S))
    {
        PtrToNode Tmp = S->Next;
        S->Next = Tmp->Next;
        free(Tmp);
    }
    else
    {
        printf("The Stack is Empty!\n");
    }
}

ElementType Top(Stack S)
{
    if(IsEmpty (S))
    {
        printf("the stack is empty!\n");
        return 0;
    }
    else
    {
        return S->Next->Element;
    }
}

int GetPrecedence(char c,int flag)
{
    if(c=='+' || c=='-')
    {
        return 1;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='(' && flag==0)
    {
        return 0;
    }
    else if(c=='(' && flag==1)
    {
        return 3;
    }
    else
    {
        fprintf(stderr,"Input char is invalid!\n");
        return -1;
    }

}

int IsOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='(' || c==')')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char Output[50];

char* InfixToPostfix(char *ch,Stack S)
{
    int index = 0;
    char c;
    while((c=*ch) != '\0')
    {
    if (IsOperator(c) == 1)
    {
        Output[index ++] = c;
        ch++;
    }
    else
    {
        if(IsEmpty(S))
        {
            Push(c,S);
            ch++;
            continue;
        }
        else
        {
            if(c == ')')
            {
                while(!IsEmpty(S) && Top(S) != '(')
                {
                    Output[index++] = Top(S);
                    Pop(S);
                }
                Pop(S);
                ch++;
                continue;
            }
            else
            {
                int outPrecedence = GetPrecedence(c,1);
                while(!IsEmpty(S) && GetPrecedence(Top(S),0) >= outPrecedence)
                {
                    Output[index++] = Top(S);
                    Pop(S);
                }
                Push(c,S);
                ch++;
                continue;
            }
        }
    }
    }
    while(!IsEmpty(S))
    {
        Output[index++] = Top(S);
        Pop(S);
    }
    Output[index] = '\0';
    return Output;
}

int main()
{
    Stack S = CreateStack();
    char *charSequence = "1+2*3+(4*5+6)*7";
    char tmp;
    char *out = InfixToPostfix(charSequence,S);

    while((tmp=*out)!='\0')
    {
        printf("%c ",tmp);
        out++;
    }
    printf("\n");
    return 0;
}
