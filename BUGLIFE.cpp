//http://www.spoj.com/problems/BUGLIFE/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

int visit[2009];
int flag;


void dfs(int a,vii v)
{

        stack<int> s;
        visit[a]=1;
        s.push(a);
        while(!s.empty())
        {
            int u=s.top();
            s.pop();
            for(vector<int>::iterator it=v[u].begin();it!=v[u].end();it++)
            {

                if(visit[*it]==0)
                {
                    visit[*it]=visit[u]==1?2:1;
                    s.push(*it);
                }
                else
                {
                    if(visit[*it]==visit[u])
                    {
                        flag=1;
                        break;
                    }
                }


            }
            if(flag==1)
                break;
        }

}


int main()
{
    int t;
    scanf("%d",&t);
    for(int l=1;l<=t;l++)
    {
        int n,e;
        scanf("%d%d",&n,&e);
        for(int i=1;i<=n+3;i++)
            visit[i]=0;

        vii v;
        v.resize(n+1);
        while(e--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }

        flag=0;
        for(int k=1;k<=n&&flag==0;k++)
        {
            if(visit[k]==0)
                dfs(k,v);
        }
        if(flag==1)
        {
            printf("Scenario #%d:\nSuspicious bugs found!\n",l);
        }
        else
        {
            printf("Scenario #%d:\nNo suspicious bugs found!\n",l);
        }
    }
    return 0;
}
