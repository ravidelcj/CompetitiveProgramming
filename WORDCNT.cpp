//http://www.spoj.com/problems/WORDCNT/
#include<bits/stdc++.h>

using namespace std;
int dp[1009];
int main(){

    ios_base::sync_with_stdio(false);
    int t;
    scanf("%d",&t);
    while(t--){
        string str;

        getline(cin, str);

        stringstream ss(str);
        int maxim=1;
        string buff;
        int k=1,i=1;
        while(ss>>buff){
            dp[i]=buff.length();

            if(i!=1&&dp[i]!=dp[i-1]){
                maxim=max(maxim,i-k);
                k=i;
            }

            i++;
        }
        maxim=max(maxim,i-k);
        cout<<maxim<<endl;
    }
    return 0;
}
