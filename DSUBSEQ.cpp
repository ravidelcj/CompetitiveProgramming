//http://www.spoj.com/problems/DSUBSEQ/
#include<iostream>
#include<cstring>
#define M 1000000007
long long alpha[27],dp[100009];

char str[100009];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        for(int i=0;i<=26;i++)
            alpha[i]=-1;

        dp[-1]=1;
        scanf("%s",str);
        int l=strlen(str);
        for(int i=0;i<l;i++)
        {
            dp[i]=((dp[i-1]%M)*2)%M;
           // printf("%d\n",dp[i]);
            if(alpha[str[i]-'A']!=-1)
                dp[i]=(dp[i]-dp[alpha[str[i]-'A']-1]+M)%M;

            alpha[str[i]-'A']=i;

        }
        printf("%lld\n",dp[l-1]);
    }
    return 0;
}
