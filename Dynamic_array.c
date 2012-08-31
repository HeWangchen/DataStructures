#include <stdio.h>
#include <stdlib.h>


int test(N)
{
    int *x;
    int *y;
    int i;
    int result = 0;
    x =(int*) malloc(N * sizeof(int));
    y =(int*) malloc(N * sizeof(int));
    printf("begin to read:\n");
    for(i=0;i<N;i++)
    {
        printf("please input the %dth number of the array:\n",i+1);
        scanf("%d",&x[i]);
    }
    for(i=0;i<N;i++)
    {
        y[i]=x[i];
    }
    for(i=0;i<N;i++)
    {
        result += x[i]*y[N-i-1];
    }
    return result;
    free(x);
    free(y);
}

int main()
{
    int N,result;
    printf("Please input the number of the array: \n");
    scanf("%d",&N);
    result = test(N);
    printf("answer: %d\n",result);
    return 0;
}

