Position FindPrevious(ElementType X,List L)
{
    Position P;

    P = L;
    while( P->Next != NULL && P->Next->Element != X)
    {
        P = P->Next;
    }

    return P;
}
