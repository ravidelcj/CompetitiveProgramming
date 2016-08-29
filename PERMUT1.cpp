//http://www.spoj.com/problems/PERMUT1/

#include<iostream>
#include<cstdio>

using namespace std;


long long dp[100][15];

void precompute()
{

    for(int i=1;i<=12;i++)
    {
         dp[0][i]=1;
         dp[1][i]=i-1;
    }
    int m,l;
    for(int i=2;i<=100;i++){
        for(int j=1;j<=12;j++){
            m=i;
            l=0;
            while(m>=0&&l<j){
                dp[i][j]+=dp[m][j-1];
                l++;
                m--;
            }
        }
    }

}


int main(){

    precompute();
    int t;
    scanf("%d",&t);
    while(t--){

        int n,k;
        scanf("%d%d",&n,&k);
        printf("%lld\n",dp[k][n]);

    }
    return 0;
}
