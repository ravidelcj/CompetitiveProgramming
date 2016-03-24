//http://www.spoj.com/problems/GNYR09F/
#include<iostream>

long long dp[109][109];


void precompute()
{
    dp[0][0]=1;
    dp[1][0]=2;
    dp[2][0]=3;
    dp[2][1]=1;
    for(int i=3;i<=100;i++)
    {
        dp[i][i-1]=1;
        dp[i][i-2]=2;
    }
    for(int i=3;i<=100;i++)
        dp[i][0]=dp[i-1][0]+dp[i-2][0];


    for(int i=4;i<=100;i++)
    {
        for(int j=1;j<=i-3;j++)
            dp[i][j]=dp[i-1][j]+dp[i-2][j]+dp[i-1][j-1]-dp[i-2][j-1];
    }
}
int main()
{
    precompute();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,n,k;
        scanf("%d%d%d",&x,&n,&k);
        printf("%d %lld\n",x,dp[n][k]);
    }
    return 0;
}
