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

char Top(Stack S)
{
    if(IsEmpty(S))
    {
        fprintf(stderr,"The Stack is Empty!\n");
        return NULL;
    }
    else
    {
        return S->Next->Element;
    }

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

void Push(ElementType X, Stack S)
{
    PtrToNode Tmp;
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

void balance(char *ch,Stack S)
{
    ElementType c;
    MakeEmpty(S);
    while((c=*ch) != "\0")
    {
        printf("%c\n",c);
        switch(c)
        {
            case '(':
            case '[':
            case '{':
                Push(c,S);
                break;
            case ')':
                if(IsEmpty(S))
                {
                    fprintf(stderr,"The symbols not balande!\n");
                    return;
                }
                else
                {
                    if(Top(S) == '(')
                    {
                        Pop(S);
                    }
                    else
                    {
                        fprintf(stderr,"The symbols not balance!\n");
                        return;
                    }
                }
                break;
            case ']':
                if(IsEmpty(S))
                {
                    fprintf(stderr,"The symbols not balande!\n");
                    return;
                }
                else
                {
                    if(Top(S) == '[')
                    {
                        Pop(S);
                    }
                    else
                    {
                        fprintf(stderr,"The symbols not balance!\n");
                        return;
                    }
                }
                break;
            case '}':
                if(IsEmpty(S))
                {
                    fprintf(stderr,"The symbols not balande!\n");
                    return;
                }
                else
                {
                    if(Top(S) == '{')
                    {
                        Pop(S);
                    }
                    else
                    {
                        fprintf(stderr,"The symbols not balance!\n");
                        return;
                    }
                }
                break;
            default:
                break;
        }
        ch++;
    }
    if(IsEmpty(S))
    {
        fprintf(stdout,"The symbols balance!\n");
    }
    else
    {
        fprintf(stderr,"Thde symbols not balace!\n");
    }
}

int main()
{
    char ch[]="(a+b){[d]c*d}{";
    Stack S = CreateStack();
    balance(ch,S);
    return 0;
}
