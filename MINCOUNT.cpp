//http://www.spoj.com/problems/MINCOUNT/
#include<iostream>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long h;
        scanf("%lld",&h);
        long long res=(h*(h+1))/6.0;
        printf("%lld\n",res);
    }
    return 0;
}
