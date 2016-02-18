//http://www.spoj.com/problems/TSHOW1/
#include<iostream>
#include<cmath>

using namespace std;
int arr[100000];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long n;
        scanf("%lld",&n);
        long long k;
        k=n/2;
        k++;
        int bit=log2(k);
        long long temp=2*((1<<bit) -1);
        if(temp!=n)
        {
            n=n-temp-1;
            bit++;
        }
        else
        {
            n=n-(2*(1<<(bit-1))-1);
        }
        int g=0;
    //    printf("bit=%d n=%d\n",bit,n);
        while(bit--)
        {
            arr[g]=n&1;
            g++;
            n=n>>1;
        }
        for(int i=g-1;i>=0;i--)
        {
            if(arr[i]==0)
                printf("5");
            else
                printf("6");


        }
         printf("\n");
    }
    return 0;
}
