//http://www.spoj.com/problems/EBOXES/
#include<iostream>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,p,f;
        scanf("%d%d%d%d",&n,&k,&p,&f);
        f=f*k;
        k--;
        f=f-n;
        f=f/k;
        printf("%d\n",f);
    }
    return 0;

}
