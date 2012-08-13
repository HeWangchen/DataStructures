/* 
 * File:   main.c
 * Author: hewangchen
 *
 * Created on 2012年8月13日, 下午6:11
 */

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i,j;
    int array[4];
    int MaxSum1,MaxSum2,MaxSum3,MaxSum4;
    for(i=0;i<4;i++)
    {
       printf("please input the %d if the 4 long array:\n",i+1);
       scanf("%d",&array[i]);
    }
    
    MaxSum1 = MaxSubsequenceSum1(array,4);
    printf("Max sum1: %d \n",MaxSum1);

    MaxSum2 = MaxSubsequenceSum2(array,4);
    printf("Max sum2: %d \n",MaxSum2);

    MaxSum3 = MaxSubsequenceSum3(array,4);
    printf("Max sum3: %d \n",MaxSum3);

    MaxSum4 = MaxSubsequenceSum4(array,4);
    printf("Max sum4: %d \n",MaxSum4);

    return 0;
}

int MaxSubsequenceSum1(const int A[],int N)
{
    int ThisSum,MaxSum1,i,j,k;

    MaxSum1 = 0;
    for(i = 0; i < N ; i++)
    {
        for(j = i; j < N ;j++)
        {
            ThisSum = 0;
            for(k = i; k <= j ;k++)
            {
                ThisSum += A[k];
            }
            if(ThisSum > MaxSum1)
            {
                MaxSum1 = ThisSum;
            }
        }
    }
    return MaxSum1;
}


int MaxSubsequenceSum2(const int A[],int N)
{
    int ThisSum,MaxSum2,i,j;

    MaxSum2 = 0;
    for(i = 0; i < N ;i++)
    {
        ThisSum = 0;
        for(j = i; j < N ; j++)
        {
            ThisSum += A[j];
            if(ThisSum > MaxSum2)
            {
                MaxSum2 = ThisSum;     
            }
        }
    }
    return MaxSum2;
}


static int MaxSubSum(const int A[],int Left,int Right)
{
    int MaxLeftSum,MaxRightSum;
    int MaxLeftBorderSum,MaxRightBorderSum;
    int LeftBorderSum,RightBorderSum;
    int Center,i;

    if(Left == Right)
    {
        if(A[Left] > 0)
        {
            return A[Left];
        }
        else 
        {
            return 0;
        }
    }

    Center = (Left + Right) / 2;
    MaxLeftSum = MaxSubSum(A,Left,Center);
    MaxRightSum = MaxSubSum(A,Center + 1,Right);
    
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;

    for(i = Center;i >= Left;i--)
    {
        LeftBorderSum += A[i];
        if(LeftBorderSum > MaxLeftBorderSum)
        {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }

    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for(i = Center + 1;i <=Right ;i++)
    {
        RightBorderSum += A[i];
        if(RightBorderSum > MaxRightBorderSum)
        {
            MaxRightBorderSum = RightBorderSum;
        }
    }

    return Max3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum + MaxRightBorderSum);

}

int Max3(int a,int b,int c)
{
    if(a > b)
    {
        if(a > c)
        {
            return a;
        }
        else
        {
            return c;
        }
    }
    else
    {
        if(b > c)
        {
            return b;
        }
        else
        {
            return c;
        }
    }
}

int MaxSubsequenceSum3(const int A[],int N)
{
     return MaxSubSum(A,0,N-1);
}

int MaxSubsequenceSum4(const int A[],int N)
{
    int ThisSum,MaxSum4,j;

    ThisSum = MaxSum4 = 0;
    for(j = 0;j < N ;j++)
    {
        ThisSum += A[j];

        if(ThisSum > MaxSum4)
        {
            MaxSum4 = ThisSum;
        }
        else if(ThisSum < 0)
        {
            ThisSum = 0;
        }
    }
    return MaxSum4;
}

