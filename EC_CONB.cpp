//http://www.spoj.com/problems/EC_CONB/
#include<cstdio>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        if(n%2!=0)
            printf("%d\n",n);
        else
        {
            int ans=0;
            while(n)
            {
                ans=ans+(n&1);
                ans<<=1;
                n>>=1;
            }
            ans>>=1;
            printf("%d\n",ans);

        }
    }
    return 0;
}
