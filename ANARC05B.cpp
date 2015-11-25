//http://www.spoj.com/problems/ANARC05B/
#include<cstdio>
#include<algorithm>

using namespace std;
#define M 10009

long long arr1[M],arr2[M];
int n1,n2;


void calc()
{
    long long sum1=0,sum2=0,total=0;


    int i=0,j=0;

    while(i<n1&&j<n2)
    {
        if(arr1[i]>arr2[j])
        {
            sum2+=arr2[j];
            j++;
        }
        else if(arr1[i]<arr2[j])
        {
            sum1+=arr1[i];
            i++;
        }
        else
        {
            sum1+=arr1[i];
            sum2+=arr2[j];
            total+=max(sum1,sum2);
            sum1=0;sum2=0;
            i++;
            j++;
        }
    }

    while(i<n1)
    {
        sum1+=arr1[i++];
    }
    while(j<n2)
    {
        sum2+=arr2[j++];
    }

    total+=max(sum1,sum2);

    printf("%lld\n",total);


}
int main()
{
    scanf("%d",&n1);
    while(n1!=0){

    for(int i=0;i<n1;i++)
    {
            scanf("%lld",&arr1[i]);

    }
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
        scanf("%lld",&arr2[i]);

    calc();
    scanf("%d",&n1);
    }
    return 0;
}
