//http://www.spoj.com/problems/SILVER/

#include<iostream>

int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        int count=0;
        while(n>1)
        {
            count++;
            n=n/2;
        }
        printf("%d\n",count);
        scanf("%d",&n);
    }
    return 0;
}
