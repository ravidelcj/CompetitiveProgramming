//http://www.spoj.com/problems/CRSCNTRY/
#include<iostream>
#include<algorithm>
using namespace std;


int dp[2009][2009];

int ag[2009],tom[2009];

int solve(int n,int k)
{
    for(int i=0;i<=n;i++)
        dp[i][0]=0;
    for(int i=0;i<=k;i++)
        dp[0][i]=0;


    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(tom[j-1]==ag[i-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][k];
}
int main()
{
    int d;
    scanf("%d",&d);
    while(d--)
    {
        int n=0,k=0;
        int maxim=0;
        while(scanf("%d",&ag[n]))
        {
            n++;
            if(ag[n-1]==0)
            {
                n--;
                break;
            }
        }
        while(scanf("%d",&tom[k]))
        {
            if(tom[0]==0)
                break;
            k++;
            while(scanf("%d",&tom[k]))
            {
                k++;
                if(tom[k-1]==0)
                {
                    k--;
                    break;
                }
            }

            int t=solve(n,k);
           // cout<<"lcs= "<<t;
            if(maxim<t)
                maxim=t;
            k=0;

        }
        printf("%d\n",maxim);
    }
    return 0;
}
