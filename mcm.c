#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<stdlib.h>
int **t;
int **s;

void printTable(int n, int **t) {
    printf("Matrix of minimum multiplications:\n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i > j)
                printf("   -   ");
            else
                printf("%6d ", t[i][j]);
        }
        printf("\n");
    }
}

void printparenthesis(int i,int j)
{
    if(i==j)
    {  
        printf("A%d",i);
        return;
    }
    printf("(");
    printparenthesis(i,s[i][j]);
    printparenthesis(s[i][j]+1,j);
    printf(")");        
}
int solve(int arr[],int i,int j)
{
    int min= INT_MAX;
        if(i>=j)
            return 0;
        if(t[i][j]!=-1)
            return t[i][j];
        else 
            for(int k=i;k<=j-1;k++)
                {
                    int temp_ans=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
                    if(temp_ans<min)
                        {
                            min=temp_ans;
                            s[i][j]=k;
                        }   
                }
                t[i][j]=min;
                return min;

}

int main()
{
    int n;
    printf("number of matrices");
    scanf("%d",&n);
    int arr[n+1];
    printf("enter elements for %d matrices",n);
    for(int i=0;i<n+1;i++)
        {
            scanf("%d",&arr[i]);
        }

    t=malloc((n+1)*sizeof(int*));
    s=malloc((n+1)*sizeof(int*));
    for(int i=0;i<n+1;i++)
    {
        t[i]=malloc((n+1)*sizeof(int));
        s[i]=malloc((n+1)*sizeof(int));
        for(int j=0;j<n+1;j++)
        {
            t[i][j]=-1;
            s[i][j]=0;
        }
    }
    
    int result=solve(arr,1,n);
    printf("\nminimum no. of multiplications:%d\n",result);

    printf("optimal parenthesization");
    printparenthesis(1,n);
    printf("\n");
    printTable(n+1,t);
    for(int i=0;i<n+1;i++)
        {
            free(t[i]);
            free(s[i]);
        }   
    free(t);
    free(s);
}