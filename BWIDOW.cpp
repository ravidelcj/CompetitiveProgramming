#include<bits/stdc++.h>

using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;

        cin>>n;
        pair<int,int>  v[n+5];
        int maxim=-100,posMax=-1;
        for(int i=0;i<n;i++){
            cin>>v[i].first;
            cin>>v[i].second;
            if(v[i].first>maxim){
                maxim=v[i].first;
                posMax=i;
            }
        }
        int flag=0;
        for(int i=0;i<n;i++){
            if(i!=posMax){
                if(v[i].second>maxim){
                    cout<<"-1\n";
                    flag=1;
                    break;
                }
            }
        }
        if(!flag){
            cout<<posMax+1<<endl;
        }
    }
    return 0;
}
