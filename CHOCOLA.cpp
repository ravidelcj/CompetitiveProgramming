//http://www.spoj.com/problems/CHOCOLA/

#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool compare(const int &i,const int &j){

    return i>j;

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int m,n;
        scanf("%d%d",&m,&n);
        vector<long long > v1,v2;
        long long x;
        for(int i=0;i<m-1;i++){
            scanf("%lld",&x);
            v1.push_back(x);
        }
        for(int i=0;i<n-1;i++){

            scanf("%lld",&x);
            v2.push_back(x);
        }

        long long r=1,c=1;
        sort(v1.begin(),v1.end(),compare);
        sort(v2.begin(),v2.end(),compare);

        int i=0,j=0;
        long long ans=0;
        while(i<=m-2&&j<=n-2){
        //cout<<"asd\n";
            if(v1[i]>=v2[j]){
                ans=ans+(v1[i]*r);
                i++;
                c++;
            }else{
                ans=ans+(v2[j]*c);
                j++;
                r++;
            }
        }

        while(i<=m-2){
            ans=ans+(v1[i]*r);
            i++;
        }

        while(j<=n-2){
            ans=ans+(v2[j]*c);
            j++;
        }

        printf("%lld\n",ans);
    }
    return 0;
}
