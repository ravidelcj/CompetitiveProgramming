//http://www.spoj.com/problems/IITKWPCB/

#include<iostream>

int main()
{
    long long n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        if(n<=6)
            printf("1\n");
        else
        {
                n-=6;
               long long x=3+((n/4)*2) + (n%4==3?1:0) +  (n%4==0?-2:0);
                printf("%lld\n",x);

        }
    }
    return 0;
}
