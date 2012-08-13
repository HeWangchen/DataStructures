#include <stdio.h>
typedef int ElementType;
int main()
{
    int array[10];
    int i;
    int n;
    int result;
    for(i = 0; i < 10 ; i++)
    {
        printf("please input the %dth number of the array :\n",i+1);
        scanf("%d",&array[i]);
    }
    printf("please input the number you want to find:\n");
    scanf("%d",&n);
    result = BinarySearch(array,n,10);
    if(result >= 0)
    {
        printf("find success,it is array[%d].\n",result);
    }
    else
    {
        printf("find failed! Now exit~\n");
    }
    return 0;
}

int BinarySearch( const ElementType A[],ElementType X, ElementType N)
{
    int Low, Mid, High;

    Low = 0;
    High = N - 1;
    while( Low <= High)
    {
        Mid = (Low + High ) / 2;
        if( A[ Mid ] < X)
        {
            Low = Mid + 1;
        }
        else
        {
            if( A[ Mid ] > X)
            {
                High = Mid - 1;
            }
            else
            {
                return Mid;
            }
        }
    }
    return  -1;
}
