//http://www.spoj.com/problems/ABCDEF/
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
vector<long long> arr1;
vector<long long> arr2;
long long arr[109];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
   // int p=0,q=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                arr1.push_back((arr[i]*arr[j])+arr[k]);
                if(arr[k]==0)
                    continue;
                arr2.push_back((arr[i]+arr[j])*arr[k]);
             //   printf("%lld %lld\n",arr[i],arr[j]);
            }
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());


    long long count=0;
    for(int i=0;i<arr1.size();i++)
    {
        int lo=lower_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();
        int hi=upper_bound(arr2.begin(),arr2.end(),arr1[i])-arr2.begin();
        count+=(hi-lo);
    }

    printf("%lld\n",count);
    return 0;
}
