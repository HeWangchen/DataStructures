void Delete(ElementType X,List L);
{
    Position P,TmpCell;

    P = FindPrevious(X,L);

    if(! IsLast(P,L))
    {
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}
