void DeleteList(List L)
{
    Position P , Tmp;
    P = L->Next;
    L->Next = NULL;

    while(P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}
