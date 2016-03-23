//http://www.spoj.com/problems/M3TILE/
#include<iostream>

long long t[100],f[100];

void precompute()
{
    t[0]=1;
    f[0]=0;
    for(int i=1;i<=31;i++)
    {
        t[i]=3*((i>=2)?t[i-2]:0)+2*((i>=3)?f[i-3]:0);
        f[i]=((i>=2)?f[i-2]:0) + t[i-1];
    }
}
int main()
{
    precompute();
    int n;
    scanf("%d",&n);
    while(n!=-1)
    {
        printf("%lld\n",t[n]);
        scanf("%d",&n);
    }
    return 0;
}
