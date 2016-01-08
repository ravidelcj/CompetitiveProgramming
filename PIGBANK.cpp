//http://www.spoj.com/problems/PIGBANK/
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int p[50009],w[10009];
int weight,n;
int dp[100000];


void solve()
{
    for(int i=1;i<=weight+2;i++)
        dp[i]=INT_MAX;

    for(int i=1;i<=weight;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(w[j]==i)
                dp[i]=min(dp[i],p[j]);
            else if(i>w[j]&&dp[i-w[j]]!=INT_MAX)
            {
                dp[i]=min(dp[i],p[j]+dp[i-w[j]]);
            }
        }
    }
    if(dp[weight]==INT_MAX)
        printf("This is impossible.\n");
    else
        printf("The minimum amount of money in the piggy-bank is %d.\n",dp[weight]);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int e,f;
        scanf("%d%d",&e,&f);
        weight=f-e;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i],&w[i]);
        }
        solve();
    }
    return 0;
}
