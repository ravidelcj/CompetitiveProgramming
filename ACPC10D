//http://www.spoj.com/problems/ACPC10D/

#include<cstdio>

long long dp1[100004],dp2[100004],dp3[100004];
long long arr[100004][4];


inline long long min(long a,long b)
{
    if(a<b)
        return a;
    else
        return b;
}
inline long long min(long long a,long long b,long long c)
{
    if(a<b)
    {
        return min(a,c);
    }
    else
    {
        return min(b,c);
    }
}
int main()
{
    int n,t=0;
    scanf("%d",&n);
    while(n!=0)
    {
        t++;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=2;j++)
            {
                scanf("%lld",&arr[i][j]);
            }
        }
        //dp1[0]=arr[n-1][1];
        dp2[0]=arr[0][1];
        dp3[0]=arr[0][2]+dp2[0];


        dp1[1]=dp2[0]+arr[1][0];
        dp2[1]=dp2[0]+arr[1][1];
        dp3[1]=dp2[0]+arr[1][2];

        dp2[1]=min(dp2[1],dp1[1]+arr[1][1],dp3[0]+arr[1][1]);
        dp3[1]=min(dp3[1],dp2[1]+arr[1][2]);
        dp3[1]=min(dp3[1],dp3[0]+arr[1][2]);

        int k,i;
        for(i=2,k=2;i<=n-2;i++,k++)
        {

            for(int j=0;j<=2;j++)
            {
                if(j==0)
                    dp1[k]=arr[i][j]+min(dp1[k-1],dp2[k-1]);
                else if(j==1)
                    dp2[k]=arr[i][j]+min(dp1[k-1],dp2[k-1],min(dp2[k-1],dp1[k],dp3[k-1]));
                else
                    dp3[k]=arr[i][j]+min(dp2[k-1],dp3[k-1],dp2[k]);
            }

        }
        if(n>2){
        dp1[k]=arr[n-1][0]+min(dp1[k-1],dp2[k-1]);
        long long ans=arr[n-1][1]+min(dp1[k-1],dp2[k-1],min(dp3[k-1],dp1[k]));
        printf("%d. %lld\n",t,ans);
        }
        else
        {
            printf("%d. %lld\n",t,dp2[1]);
        }
        scanf("%d",&n);
    }
}
