#include <stdlib.h>
#include <stdio.h>

typedef struct ArrayNode *PtrToNode;

typedef struct ArrayNode
{
    int number;
    PtrToNode Next;
}ArrayNode;

void TraverseArrayNode(PtrToNode P)
{
    PtrToNode Tmp = P->Next;
    while(Tmp != NULL)
    {
        printf(" %d ",Tmp->number); 
        Tmp = Tmp->Next;
    }
}

void Rebuild(PtrToNode L)
{
    PtrToNode P,Tmp;
    P = L->Next;
    while(P != NULL)
    {
        Tmp = P->Next;
        free(P);
        P = Tmp;
    }
}

void RadixSort(int A[])
{
    int i,num,key1,key2,key3;
    PtrToNode array[10];
    PtrToNode A0,A1,A2,A3,A4,A5,A6,A7,A8,A9;
    for(i = 0; i<10;i++)
    {
        array[i] = (PtrToNode)malloc(sizeof(ArrayNode));
    }
    A0 = array[0];
    A1 = array[1];
    A2 = array[2];
    A3 = array[3];
    A4 = array[4];
    A5 = array[5];
    A6 = array[6];
    A7 = array[7];
    A8 = array[8];
    A9 = array[9];
    PtrToNode Tmp;
    printf("the first time sort:*****************\n");
    for(i = 0; i < 5;i++)
    {
        num = A[i]%10;
        switch(num)
        {
            case 0:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A0->Next = Tmp;
                A0 = A0->Next;
                break;
            }
            case 1:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A1->Next = Tmp;
                A1 = A1->Next;
                break; 
            }
            case 2:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A2->Next = Tmp;
                A2 = A2->Next;
                break; 
            }
            case 3:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A3->Next = Tmp;
                A3 = A3->Next;
                break; 
            }
            case 4:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A4->Next = Tmp;
                A4 = A4->Next;
                break; 
            }
            case 5:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A5->Next = Tmp;
                A5 = A5->Next;
                break; 
            }
            case 6:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A6->Next = Tmp;
                A6 = A6->Next;
                break; 
            }
            case 7:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A7->Next = Tmp;
                A7 = A7->Next;
                break; 
            }
            case 8:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A8->Next = Tmp;
                A8 = A8->Next;
                break; 
            }
            case 9:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A9->Next = Tmp;
                A9 = A9->Next;
                break; 
            }
            default:break;
        }
    }
    A0->Next = NULL;
    A1->Next = NULL;
    A2->Next = NULL;
    A3->Next = NULL;
    A4->Next = NULL;
    A5->Next = NULL;
    A6->Next = NULL;
    A7->Next = NULL;
    A8->Next = NULL;
    A9->Next = NULL;
    for(i=0;i<10;i++)
    {
        TraverseArrayNode(array[i]);
    }
    printf("\n");
    key1 = 0;
    for(i=0;i<10;i++)
    {
        Tmp = array[i]->Next;
        while(Tmp != NULL)
        {
            A[key1] = Tmp->number;
            key1++;
            Tmp = Tmp->Next;
        }
    }
    for(i=0;i<key1;i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\n");
    for(i=0;i<10;i++)
    {
        Rebuild(array[i]);
    }
    printf("the second time sort:*****************\n");
    for(i = 0; i<10;i++)
    {
        array[i] = (PtrToNode)malloc(sizeof(ArrayNode));
    }
    A0 = array[0];
    A1 = array[1];
    A2 = array[2];
    A3 = array[3];
    A4 = array[4];
    A5 = array[5];
    A6 = array[6];
    A7 = array[7];
    A8 = array[8];
    A9 = array[9];
    for(i = 0; i < 5;i++)
    {
        num = A[i]/10%10;
        switch(num)
        {
            case 0:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A0->Next = Tmp;
                A0 = A0->Next;
                break;
            }
            case 1:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A1->Next = Tmp;
                A1 = A1->Next;
                break; 
            }
            case 2:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A2->Next = Tmp;
                A2 = A2->Next;
                break; 
            }
            case 3:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A3->Next = Tmp;
                A3 = A3->Next;
                break; 
            }
            case 4:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A4->Next = Tmp;
                A4 = A4->Next;
                break; 
            }
            case 5:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A5->Next = Tmp;
                A5 = A5->Next;
                break; 
            }
            case 6:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A6->Next = Tmp;
                A6 = A6->Next;
                break; 
            }
            case 7:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A7->Next = Tmp;
                A7 = A7->Next;
                break; 
            }
            case 8:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A8->Next = Tmp;
                A8 = A8->Next;
                break; 
            }
            case 9:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A9->Next = Tmp;
                A9 = A9->Next;
                break; 
            }
            default:break;
        }
    }
    A0->Next = NULL;
    A1->Next = NULL;
    A2->Next = NULL;
    A3->Next = NULL;
    A4->Next = NULL;
    A5->Next = NULL;
    A6->Next = NULL;
    A7->Next = NULL;
    A8->Next = NULL;
    A9->Next = NULL;
    for(i=0;i<10;i++)
    {
        TraverseArrayNode(array[i]);
    }
    printf("\n");
    key2 = 0;
    for(i=0;i<10;i++)
    {
        Tmp = array[i]->Next;
        while(Tmp != NULL)
        {
            A[key2] = Tmp->number;
            key2++;
            Tmp = Tmp->Next;
        }
    }
    for(i=0;i<key2;i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\n");
    for(i=0;i<10;i++)
    {
        Rebuild(array[i]);
    }
    
    printf("after the final time sort:*****************\n");
    
    for(i = 0; i<10;i++)
    {
        array[i] = (PtrToNode)malloc(sizeof(ArrayNode));
    }
    A0 = array[0];
    A1 = array[1];
    A2 = array[2];
    A3 = array[3];
    A4 = array[4];
    A5 = array[5];
    A6 = array[6];
    A7 = array[7];
    A8 = array[8];
    A9 = array[9];
    for(i = 0; i < 5;i++)
    {
        num = A[i]/100%10;
        switch(num)
        {
            case 0:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A0->Next = Tmp;
                A0 = A0->Next;
                break;
            }
            case 1:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A1->Next = Tmp;
                A1 = A1->Next;
                break; 
            }
            case 2:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A2->Next = Tmp;
                A2 = A2->Next;
                break; 
            }
            case 3:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A3->Next = Tmp;
                A3 = A3->Next;
                break; 
            }
            case 4:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A4->Next = Tmp;
                A4 = A4->Next;
                break; 
            }
            case 5:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A5->Next = Tmp;
                A5 = A5->Next;
                break; 
            }
            case 6:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A6->Next = Tmp;
                A6 = A6->Next;
                break; 
            }
            case 7:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A7->Next = Tmp;
                A7 = A7->Next;
                break; 
            }
            case 8:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A8->Next = Tmp;
                A8 = A8->Next;
                break; 
            }
            case 9:
            {
                Tmp = (PtrToNode)malloc(sizeof(struct ArrayNode));
                Tmp->number = A[i];
                A9->Next = Tmp;
                A9 = A9->Next;
                break; 
            }
            default:break;
        }
    }
    A0->Next = NULL;
    A1->Next = NULL;
    A2->Next = NULL;
    A3->Next = NULL;
    A4->Next = NULL;
    A5->Next = NULL;
    A6->Next = NULL;
    A7->Next = NULL;
    A8->Next = NULL;
    A9->Next = NULL;
    for(i=0;i<10;i++)
    {
        TraverseArrayNode(array[i]);
    }
    printf("\n");
    key3 = 0;
    for(i=0;i<10;i++)
    {
        Tmp = array[i]->Next;
        while(Tmp != NULL)
        {
            A[key3] = Tmp->number;
            key3++;
            Tmp = Tmp->Next;
        }
    }
    for(i=0;i<key3;i++)
    {
        printf(" %d ",A[i]);
    }
    printf("\n");
    for(i=0;i<10;i++)
    {
        Rebuild(array[i]);
    }
    
}

int main()
{
     int number[5] = {211,123,10,1,34};
     RadixSort(number);
     return 0;
}
