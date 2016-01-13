//http://www.spoj.com/problems/RPLC/
#include<iostream>
#include<algorithm>

using namespace std;

long long arr[1000009];

int main()
{
    int t;
    scanf("%d",&t);

    for(int k=1;k<=t;k++)
    {
        long long ans=0;
        int n;
        scanf("%d",&n);
        arr[0]=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&arr[i]);
                if((arr[i]+arr[i-1])<1)
                {

                    ans+=abs(arr[i]+arr[i-1])+1;
                    arr[i]=1;
                }
                else
                {
                    arr[i]+=arr[i-1];
                }
        }
        printf("Scenario #%d: %lld\n",k,ans?ans:1);
    }
    return 0;

}
