//http://www.spoj.com/problems/SCPC11B/
#include<cstdio>
#include<algorithm>
#define M 200000
using namespace std;

int arr[M];
int main()
{
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);

        sort(arr,arr+n);
        int flag=0;
        for(int i=1;i<n;i++)
        {
            if((arr[i]-arr[i-1])>200)
            {
                flag=1;
                break;
            }
        if(i==(n-1))
        {

            if((2*(1422-arr[n-1]))>200)
                flag=1;
        }

        }
        if(flag==1)
            printf("IMPOSSIBLE\n");
        else
            printf("POSSIBLE\n");
        scanf("%d",&n);
    }
    return 0;
}
