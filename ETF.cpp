//http://www.spoj.com/problems/ETF/
#include<cstdio>
#define M 1000009
int dp[M];

void precompute()
{
    for(int i=2;i<500009;i++)
    {
        for(int j=i,count=0;j<=M;j+=i,count++)
        {
            if(i!=j)
            dp[j]+=(count-dp[i]);
        }
    }
}

int main()
{
    precompute();
    int t;
    scanf("%d",&t);
    dp[1]=1;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n==1)
            printf("1\n");
        else{
                int temp=n;
        n--;
        n=n-dp[temp];
        printf("%d\n",n);
        }
    }
    return 0;

}
