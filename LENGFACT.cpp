//http://www.spoj.com/problems/LENGFACT/
#include<iostream>
#include<cmath>

using namespace std;

#define PI 3.1415926535

int main()
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long n;
        scanf("%lld",&n);
        if(n==0||n==1){
            printf("1\n");
            continue;
        }
        double ans=0;
        ans=log(2*PI*n)/2 + n*(log(n)-1);
        ans=ans/log(10);
        ans+=1;
        long long k=floor(ans);
        printf("%lld\n",k);
    }
    return 0;

}
