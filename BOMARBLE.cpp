//http://www.spoj.com/problems/BOMARBLE/
#include<cstdio>


long long arr[1009];

void precompute()
{
    arr[1]=5;
    long long d=7;
    for(int i=2;i<=1000;i++)
    {
        arr[i]=arr[i-1]+d;
        d+=3;
    }

}
int main()
{
    precompute();
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        printf("%lld\n",arr[n]);
        scanf("%d",&n);
    }
    return 0;
}
