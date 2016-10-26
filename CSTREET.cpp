//http://www.spoj.com/problems/CSTREET/
#include<bits/stdc++.h>

using namespace std;
typedef pair<int, pair<int,int> > pr;
int visit[1009];

void init(int n){
    for(int i=1;i<=n;i++){
        visit[i]=i;
    }
}
int uFind(int n){
    if(visit[n]!=n){
        return uFind(visit[n]);
    }
    return n;
}

void uUnion(int x,int y){
    int a = uFind(x);
    int b = uFind(y);
    visit[b]=a;
}


int main(){

    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int p,n,m;
        cin>>p>>n>>m;
        init(n);
        int a,b,c;
        vector<pr> v;
        while(m--){
            cin>>a>>b>>c;
            v.push_back(make_pair(c, make_pair(a,b)));
        }
        sort(v.begin(), v.end());
        long long ans=0;
        for(int i=0;i<v.size();i++){

            int x = v[i].second.first;
            int y = v[i].second.second;

            if(uFind(x)!=uFind(y)){
                ans+=v[i].first;
                uUnion(x,y);
            }
        }
        cout<<ans*p<<endl;
    }
    return 0;
}
