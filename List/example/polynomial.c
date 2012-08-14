#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *PtrToNode;

typedef struct PolyNode
{
    int Coeff;
    int Exponent;
    PtrToNode Next;
}PolyNode;

typedef PtrToNode Polynomial;

void AddPolynomial (Polynomial P,Polynomial Q,Polynomial Sum)
{
    Polynomial PIndex,QIndex,SumIndex;
    PIndex = P->Next;
    QIndex = Q->Next;
    SumIndex = Sum;

    while(!(PIndex == NULL && QIndex == NULL))
    {
        if(PIndex == NULL)
        {
            SumIndex->Next = QIndex;
            QIndex = QIndex->Next;
            SumIndex = SumIndex->Next;
        }
        else if(QIndex == NULL)
        {
            SumIndex->Next = PIndex;
            PIndex = PIndex->Next;
            SumIndex = SumIndex->Next;
        }
        else
        {
            if(PIndex->Exponent > QIndex->Exponent)
            {
                SumIndex->Next = PIndex;
                PIndex = PIndex->Next;
                SumIndex = SumIndex->Next;

                continue;
            }
            if(PIndex->Exponent == QIndex->Exponent)
            {
                Polynomial PP = malloc(sizeof(struct PolyNode));
                PP->Exponent = PIndex->Exponent;
                PP->Coeff = PIndex->Coeff + QIndex->Coeff;
                SumIndex->Next = PP;
                PIndex = PIndex->Next;
                QIndex = QIndex->Next;
                SumIndex = SumIndex->Next;
                continue;
            }            
            if(PIndex->Exponent < QIndex->Exponent)
            {
                SumIndex->Next = QIndex;
                QIndex = QIndex->Next;
                SumIndex = SumIndex->Next;
                continue;
            }
        }
    }
    SumIndex->Next = NULL;
}


void TraversePolynomial(Polynomial P)
{
    Polynomial Tmp = P->Next;
    while(Tmp != NULL)
    {
        printf("Coeff is %d and Exponet is %d\n",Tmp->Coeff,Tmp->Exponent);
        Tmp = Tmp->Next;
    }
}


int main(void)
{
    Polynomial Poly1,Poly2,Poly3,Poly11,Poly22;
    int i,j;
    Poly1 = malloc(sizeof(struct PolyNode));
    Poly2 = malloc(sizeof(struct PolyNode));
    Poly3 = malloc(sizeof(struct PolyNode));
    Poly11 = Poly1;
    Poly22 = Poly2;

    for(i = 5; i >= 1;i--)
    {
        Polynomial Tmp = malloc(sizeof(struct PolyNode));
        Tmp->Coeff = i;
        Tmp->Exponent = i;
        Poly11->Next = Tmp;
        Poly11= Poly11->Next;
    }
    Poly11->Next = NULL;
    for(j = 11 ; j >= 3 ;j--)
    {
        Polynomial Tmp = malloc(sizeof(struct PolyNode));
        Tmp->Coeff = j;
        Tmp->Exponent = j;
        Poly22->Next = Tmp;
        Poly22= Poly22->Next;
    }
    Poly22->Next = NULL;
    TraversePolynomial(Poly1);
    printf("*********************************************\n");
    TraversePolynomial(Poly2);
    AddPolynomial(Poly1,Poly2,Poly3);
    printf("*********************************************\n");
    TraversePolynomial(Poly3);
    return 0;
}
