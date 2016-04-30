//http://www.spoj.com/problems/BITMAP/
#include<iostream>
#include<queue>
#include<algorithm>
#include<limits>
#include<cstdio>
#include<string>
using namespace std;

string str[190];
int visit[190][190];
int n,m;
int movr[]={ 0,0,-1,1};
int movc[]={-1,1, 0,0};
int graph[190][190];
void init_visit()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
               visit[i][j]=0;
        }
    }
}

bool check(int x,int y)
{
    if(x<0||x>=n)
      return false;
    if(y<0||y>=m)
      return false;
    if(str[x][y]=='1')
        return false;

    return true;
}
void graph_calc(int i,int j)
{


    init_visit();
    queue<pair<int,int> > s;
    s.push(make_pair(i,j));

    visit[i][j]=1;
    graph[i][j]=0;

    while(!s.empty())
    {
        pair<int,int> p=s.front();
        s.pop();
        for(int i=0;i<4;i++)
        {
            int tempx=p.first;
            int tempy=p.second;
            int x,y;
            x=p.first+movr[i];
            y=p.second+movc[i];
            if(!check(x,y))
                continue;
            if(visit[x][y]!=1)
            {
                int temp;
                temp=graph[tempx][tempy]+1;
                if(temp<graph[x][y]){
                    graph[x][y]=temp;
                    s.push(make_pair(x,y));
                }
                visit[x][y]=1;

            }
        }
    }



}
void show()
{

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
               printf("%d ",graph[i][j]);
            printf("\n");
        }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {

       
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>str[i];

        }

        //INITITAIZATION

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                graph[i][j]=100000000;

        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='1')
                {
                    graph_calc(i,j);
            
                }
            }
        }
        show();
    }
    return 0;
}
