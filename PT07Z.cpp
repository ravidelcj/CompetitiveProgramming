//http://www.spoj.com/problems/PT07Z/
#include<cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    int x,res=0;
    while(n--)
    {
        scanf("%d",&x);
        res^=x;
    }
    printf("%d",res);
    return 0;
}
