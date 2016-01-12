//http://www.spoj.com/problems/COMDIV/
#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int l=__gcd(a,b);
        if(l==1)
            printf("1\n");
        else
        {
            int count=0;
            int i;
            for(i=1;i*i<=l;i++)
            {
                if(l%i==0)
                    count+=2;
            }
            i--;
            if(i*i==l)
                count--;
            printf("%d\n",count);
        }
    }
    return 0;
}
