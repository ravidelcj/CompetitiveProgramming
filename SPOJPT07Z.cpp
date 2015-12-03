//http://www.spoj.com/problems/PT07Z/
#include<vector>
#include<cstdio>
#include<stack>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;
int visit[10009];
vii adjList;
int dist;
int dfs(int s)
{
    stack<int> st;
    st.push(s);
    int point;
    visit[s]=1;
    while(!st.empty())
    {
        int u=st.top();

    //    printf("%d\n",u);
        st.pop();
        int flag=0;
        for(int i=0;i<adjList[u].size();i++)
        {

            if(visit[adjList[u][i]]==0)
            {
                st.push(adjList[u][i]);
                visit[adjList[u][i]]=visit[u]+1;
                if(dist<visit[adjList[u][i]])
                {
                    dist=visit[adjList[u][i]];
                    point=adjList[u][i];
                }
            }
        }
    }
    return point;
}
void init(int n)
{
    for(int i=0;i<=n+10;i++)
        visit[i]=0;
}
int main()
{
    int n;
    scanf("%d",&n);
    adjList.resize(10009);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }
    init(n);
    int x=dfs(1);
   // printf("\n\n%d",x);
    dist=0;
    init(n);
    x=dfs(x);
    printf("%d\n",dist-1);
    return 0;

}
