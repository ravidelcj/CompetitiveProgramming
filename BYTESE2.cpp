//http://www.spoj.com/problems/BYTESE2/
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>

using namespace std;
int cas[10000009];
int main()
{
    int t;
    scanf("%d",&t);
    set<int> e;
    while(t--)
    {
        int n;
        scanf("%d",&n);
        while(n--)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            e.insert(x);
            e.insert(y);
            cas[x]=1;
            cas[y]=-1;
        }
        long long res=-1,sum=0;
        for(set<int>::iterator it=e.begin();it!=e.end();it++)
        {
            sum+=cas[*it];
            if(res<sum)
                res=sum;

            cas[*it]=0;
        }
        printf("%lld\n",res);

    }
    return 0;
}
