//http://www.spoj.com/problems/NY10E/
#include<cstdio>

long long dp[65][10];
long long arr[65];
void precompute()
{
    arr[1]=0;
    for(int i=0;i<=9;i++)
    {
        dp[1][i]=1;
        arr[1]+=dp[1][i];
    }
    for(int i=2;i<=64;i++)
    {
        arr[i]=0;
        for(int j=0;j<=9;j++)
        {
            if(j==0)
                dp[i][j]=arr[i-1];
            else
                dp[i][j]=dp[i][j-1]-dp[i-1][j-1];

            arr[i]+=dp[i][j];
        }
    }

}
int main()
{
    precompute();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,n;
        scanf("%d%d",&x,&n);
        printf("%d %lld\n",x,arr[n]);
    }
    return 0;
}
