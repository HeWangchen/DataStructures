#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

struct Node
{
    ElementType Element;
    Position Next;
};

//创建链表
List CreateList();
//遍历
void TraverseList(List L);
//清空
List MakeEmpty(List L);
//判断
int IsEmpty(List L);
int IsLast(Position P,List L);

//常用操作
Position Find(ElementType X,List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X,List L);
void Insert(ElementType X,List L,Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
//返回当先位置的现一个位置
Position Advance(Position P);
//获取当前位置元素的值
ElementType Retrive(Position);

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position P,List L)
{
    return P->Next == NULL;
}

Position Find(ElementType X,List L)
{
    Position P = L->Next;
    while(P != NULL && P->Element != X);
    {
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X,List L)
{
    Position P,TmpCell;
    P = FindPrevious(X,L);
    if(!IsLast(P,L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell;
        free(TmpCell);
    }
}

Position FindPrevious(ElementType X,List L)
{
    Position P = L;
    while(P->Next != NULL && P->Next->Element != X)
    {
        P = P->Next;
    }
    return P;
}

void Insert(ElementType X,List L,Position P)
{
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL)
    {
        printf("Out of space!\n");
        return;
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void DeleteList(List L)
{
    Position P,Tmp;
    P = L->Next;
    while(P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

Position Header(List L)
{
    return L;
}

Position First(List L)
{
    return L->Next;
}

Position Advance(Position P)
{
    return P->Next;
}

ElementType Retrive(Position P)
{
    return P->Element;
}

List CreateList()
{
    int i;
    Position P,Tmp;
    List L = malloc(sizeof(struct Node));
    P = L;
    for(i = 0;i < 5 ;i++)
    {
        Tmp = malloc(sizeof(struct Node));
        Tmp->Element = i;
        P->Next = Tmp;
        P = Tmp;
    }
    P->Next = NULL;
    return L;
}

void TraverseList(List L)
{
    Position P;
    P = L->Next;
    while(P != NULL)
    {
        printf("%d\n",P->Element);
        P = P->Next;
    }
}

int main(void)
{
    List L = CreateList();

    Position P = Find(1,L);

    Insert(8,L,P);

    P = FindPrevious(8,L);

    TraverseList(L);

    return 0;
}
