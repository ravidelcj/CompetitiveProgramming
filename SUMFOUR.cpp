//http://www.spoj.com/problems/SUMFOUR/
#include <bits/stdc++.h>

using namespace std;

int n,a[2509],b[2509],c[2509],d[2509];
int main(){

    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i =0 ;i<n;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    vector<int> first,second;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            first.push_back(a[i]+b[j]);
            second.push_back(-c[i]-d[j]);
        }
    }
    sort(second.begin(),second.end());
    sort(first.begin(),first.end());
    int ans=0;

    for(int i=0;i<first.size();i++){

        int l=lower_bound(second.begin(),second.end(),first[i])-second.begin();
        int h =upper_bound(second.begin(),second.end(),first[i])-second.begin();
        ans+=(h-l);
    }
    cout<<ans<<endl;
    return 0;
}
