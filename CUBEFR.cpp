http://www.spoj.com/problems/CUBEFR/
#include<cstdio>
#define M 1000000

int arr[M];


void precompute()
{

    long long k=2;
    arr[1]=1;
    for(long long i=2;i<=M;i++)
    {

        if(i*i*i<=M)
        {
            long long p=i*i*i;
            arr[p]=-1;
            for(long long j=1;p*j<=M;j++)
                arr[p*j]=-1;
        }
        if(arr[i]==0)
        {
           arr[i]=k++;
        }

    }
}
int main()
{
    precompute();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        if(arr[n]!=-1)
        printf("Case %d: %d\n",i,arr[n]);
        else
            printf("Case %d: Not Cube Free\n",i);
    }
    return 0;
}
