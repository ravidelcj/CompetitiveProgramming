//http://www.spoj.com/problems/TWENDS/
#include<cstdio>
#define M 1009


int arr[M];


int dp[M][M];



int calc(int i,int j)
{
    if(i>j-1)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==j-1)
    {

        dp[i][j]=arr[i]>=arr[j]?arr[i]:arr[j];
        return dp[i][j];
    }
    int first,second;
    if(arr[i+1]>=arr[j])
    {
        first=arr[i]+calc(i+2,j);
    }
    else
    {
        first=arr[i]+calc(i+1,j-1);
    }


    if(arr[i]>=arr[j-1])
    {
        second=arr[j]+calc(i+1,j-1);

    }
    else
    {
        second=arr[j]+calc(i,j-2);
    }
    dp[i][j]=first>=second?first:second;
    return dp[i][j];
}
int main()
{

    int n;
    scanf("%d",&n);
    int count=0;
    while(n!=0){
            count++;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    dp[i][j]=-1;

            }
            int calcSum=0;
            for(int i=0;i<n;i++)
           {
                     scanf("%d",&arr[i]);
                     calcSum+=arr[i];
           }


            int k=calc(0,n-1);
            int p=calcSum-k;
            printf("In game %d, the greedy strategy might lose by as many as %d points.\n",count,k-p);
            scanf("%d",&n);
    }
    return 0;
}
