//http://www.spoj.com/problems/LABYR1/
#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

typedef pair<int,int> pii;
int c,r;
char str[1009][1009];
int visit[1009][1009];
int diffr[4],diffc[4];
pii maxim;
int maxDist;
void init()
{
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
            visit[i][j]=0;
    }
}
bool valid(pii a)
{

      return (a.first>=0&&a.first<r&&a.second>=0&&a.second<c);
}
void dfs(pii a)
{
    stack<pii> s;
    s.push(a);
    visit[a.first][a.second]=1;
   // int j=0;
    while(!s.empty())
    {
        pii t=s.top();
        s.pop();

        for(int i=0;i<=3;i++)
        {
            int x=t.first+diffr[i];
            int y=t.second+diffc[i];
            pii q=make_pair(x,y);
            if(!valid(q))
                continue;
            if(str[x][y]=='.'&&!visit[x][y])
            {
                    s.push(q);
                    visit[x][y]=visit[t.first][t.second]+1;
                    if(maxDist<visit[x][y])
                    {
                        maxDist=visit[x][y];
                        maxim=q;

                    }
            }

        }
    }
}
int main()
{
    diffr[0]=diffc[2]=0;
    diffr[1]=diffc[3]=0;
    diffr[2]=diffc[0]=-1;
    diffr[3]=diffc[1]=1;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        maxDist=0;
//        dist=-1;
        scanf("%d%d",&c,&r);
        for(int i=0;i<r;i++)
        {
            scanf("%s",str[i]);
        }

        init();

        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(str[i][j]=='.'&&visit[i][j]==0)
                {
                    pii a=make_pair(i,j);
                    dfs(a);
                }
            }
        }
        dfs(make_pair(1,1));

        init();
        maxDist=0;
        dfs(maxim);
        printf("Maximum rope length is %d.\n",maxDist-1<0?0:maxDist-1);

    }
    return 0;
}
