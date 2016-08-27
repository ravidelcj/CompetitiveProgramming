//http://www.spoj.com/problems/SQRBR/


#include<iostream>
#include<cstdio>

using namespace std;

int dp[100][100];

int arr[100],length;

void init(int n){

    for(int i=0;i<=2*n;i++)
        arr[i]=0;



    for(int i=0;i<=2*n;i++){

        for(int j=0;j<=2*n;j++)
            dp[i][j]=0;

    }


}


int calc(int sum, int n){



    if(sum<0)
        return 0;

      if(dp[sum][n]!=0)
       return dp[sum][n];
    if(arr[length-n+1]!=0){

        if(n==1){
            if(sum+1==0)
                return 1;
            else
                return 0;
        }
        dp[sum][n]= calc(sum+1,n-1);

        return dp[sum][n];
    }

    if(n==1)
    {
        if(sum+1==0)
            return 1;

        if(sum-1==0)
            return 1;


        return 0;

    }
    int x= calc(sum+1,n-1);
    int y = calc(sum-1,n-1);
  //  cout<<x<<" "<<y<<endl;
    dp[sum][n]=x+y;
    //cout<<dp[sum][n]<<endl;
    return dp[sum][n];



}

int main(){

    int t;
    scanf("%d",&t);

    while(t--){

        int n,k;
        scanf("%d%d",&n,&k);


        init(n);

        for(int i=1;i<=k;i++){
            int x;
            scanf("%d",&x);
            arr[x] = 1;
        }
        n=2*n;
        length = n;
        int ans = arr[1]==1?calc(1,n-1):calc(0,n);
        printf("%d\n",ans);
    }

    return 0;
}
