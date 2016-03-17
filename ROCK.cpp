//http://www.spoj.com/problems/ROCK/

//EASY LEVEL MCM PROBLEM
#include<iostream>

using namespace std;
char str[209];

pair<int,int> dp[209][209];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        scanf("%s",str);
        for(int i=0;i<n;i++)
        {
            if(str[i]=='0')
            {
                dp[i][i].first=0;
                dp[i][i].second=0;
            }
            else
            {
                dp[i][i].first=1;
                dp[i][i].second=1;
            }
        }

        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int j=i+l-1;
                dp[i][j].first=0;
                dp[i][j].second=0;

                for(int k=i;k<=j;k++)
                {
                    int x=dp[i][k].first+dp[k+1][j].first;
                    int y=dp[i][k].second+dp[k+1][j].second;

                    int z=(l/2.0) + 1;
                    if(y>=z)
                        x=l;
                    if(x>dp[i][j].first)
                    {
                        dp[i][j].first=x;
                        dp[i][j].second=y;
                    }
                }
            }
        }
 
        printf("%d\n",dp[0][n-1]);

    }
    return 0;
}
