//http://www.spoj.com/problems/POUR1/
#include<cstdio>
#include<algorithm>

using namespace std;
int c;


int calc(int a,int b)
{
    int x=0,y=0;
    int count=0;
    while(1)
    {
        //printf("enter\n");
        if(x==c||y==c)
            break;

        if(x==0)
            x=a;
        else if(y==b)
            y=0;
        else
        {
            int temp=b-y;
            if(temp>x)
            {
                y+=x;
                x=0;
            }
            else{
            x=x-temp;
            y=y+temp;
            }
        }
        count++;
    }
    return count;
}
int gcd(int a,int b)
{
    if(a==0)
        return b;
    else
        return gcd(b%a,a);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d%d",&a,&b,&c);
        int g=gcd(a,b);
        if(c%g!=0||c>a&&c>b)
            printf("-1\n");
        else
        {
            int x=min(calc(a,b),calc(b,a));
            printf("%d\n",x);
        }
    }
    return 0;
}
