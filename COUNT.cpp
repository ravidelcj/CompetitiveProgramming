//www.spoj.com/problems/COUNT
//dp
#include <bits/stdc++.h>

using namespace std;
#define OFF ios::sync_with_stdio(false)
#define M 1988
int dp[5009][5009];

void preprocess(){

   for(int i=1; i<=5000;i++){
        dp[i][0]=0;
        dp[0][i]=1;
   }
    dp[0][0]=0;
   for(int i=1;i<=5000;i++){
        for(int j=1;j<=5000;j++){

            if(i==j){
                dp[i][j]=dp[i][j-1]+1;
            }else if(i<j){
                 dp[i][j]=dp[i][j-1];
            }else{
                dp[i][j]=dp[i][j-1]+dp[i-j][j];
            }
            dp[i][j]%=M;

        }
   }

}

int main() {
    OFF;
    preprocess();
    int n,k;
    cin>>n>>k;
    while(n!=0){

        cout<<(M+dp[n][k] - dp[n][k-1])%M<<endl;
        cin>>n>>k;
    }
	return 0;
}

