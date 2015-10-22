//http://www.spoj.com/problems/ZSUM/
#include<cstdio>
#define M 10000007


long long calc(long long a,long long b)
{

    long long c=1;
    while(b)
    {
        if(b&1)
        {
            c=(c*a)%M;
        }
        b>>=1;
        a=(a*a)%M;
    }
    return c;

}
int main()
{
    long long n,k,a,b,c;
     scanf("%lld%lld",&n,&k);
    while(n!=0)
    {

        long long ans1=calc(n-1,k);
        long long ans2=calc(n-1,n-1);
        long long ans3=calc(n,n);
        long long ans4=calc(n,k);
        ans1=2*(ans1+ans2)+ans3+ans4;
        ans1%=M;
        printf("%lld\n",ans1);
         scanf("%lld%lld",&n,&k);
    }
    return 0;
}
