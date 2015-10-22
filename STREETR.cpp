//http://www.spoj.com/problems/STREETR/
#include<cstdio>
#define M 100009

int arr[M];

int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int n;
    scanf("%d",&n);
    int g=0;
    for(int i=0;i<n;i++)
    {
            scanf("%d",&arr[i]);
            if(i==1)
            {
                g=arr[i]-arr[i-1];

            }
            if(i>=2)
            {
                g=gcd(g,arr[i]-arr[i-1]);
            }
    }

    int n1=(arr[n-1]-arr[0]+g)/g;
    printf("%d\n",n1-n);
    return 0;
}
