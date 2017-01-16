#include<bits/stdc++.h>

using namespace std;
int visit[100005];

void init(int n){

    for(int i = 0; i <= n; i++){
        visit[i]=0;
    }

}

void dfs(int s, vector<int> adjList[]){

    stack<int> st;
    st.push(s);
    while(!st.empty()){
        int x = st.top();
        st.pop();
        visit[x]=1;
        for(int i=0;i<adjList[x].size();i++){
            if(visit[adjList[x][i]]==0){
                st.push(adjList[x][i]);
            }
        }
    }

}
int main(){

    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        init(n);
        vector<int> adjList[n+9];
        int e;
        cin>>e;
        for(int i=0;i<e;i++){
            int x,y;
            cin>>x>>y;
            adjList[x].push_back(y);
            adjList[y].push_back(x);
        }
        int counter=0;
        for(int i=0;i<n;i++){
            if(visit[i]==0){
              //  cout<<i<<endl;
                counter++;
                dfs(i, adjList);
            }
        }
        cout<<counter<<endl;
    }
    return 0;
}
