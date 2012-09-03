#include <stdio.h>
#include <stdlib.h>


int Discrete(n,m)
{
    int *x;
    int *v;
    int *y;
    int i,j;
    int result;
    x =(int*) malloc(n * sizeof(int));
    v =(int*) malloc(m * sizeof(int));
    y =(int*) malloc((m+n-2) * sizeof(int));
    printf("begin to read:\n");
    
    for(i=0;i<n;i++)
    {
        printf("please input the %dth number of the array x:\n",i+1);
        scanf("%d",&x[i]);
    }
    printf("x: \n");
    for(i=0;i<n;i++)
    {
        printf("%d",x[i]);
    }
    for(i=0;i<m;i++)
    {
        printf("please input the %dth number of the array v:\n",i+1);
        scanf("%d",&v[i]);
    }
    printf("v: \n");
    for(i=0;i<m;i++)
    {
        printf("%d",v[i]);
    }
    for(i=0;i<=(m+n-2);i++)
    {
        result = 0;
        for(j=0;j<=i;j++)
        {
            result += x[j]*v[i-j];
            y[i] = result;
        }
        printf("y[%d] = %d ;\n",i,y[i]);
    }
    free(x);
    free(v);
    free(y);
    return 0;
}

int main()
{
    int m,n,choice,N,result;
    printf("Please input the number of the list x: \n");
    scanf("%d",&n);
    printf("Please input the number of the list v: \n");
    scanf("%d",&m);
    printf("which do you want to calculate? 1->Discrete 2->aa \n");
    scanf("%d",&choice);
    if(choice == 1)
    {
        Discrete(n,m);
    }
   /* else if(choice == 2)
    {
        please input
    }*/
    return 0;
}

