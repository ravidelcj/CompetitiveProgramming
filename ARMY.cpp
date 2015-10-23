//http://www.spoj.com/problems/ARMY/

#include<cstdio>

#define M 1000000

int E[M],O[M];

int main()
{
    int t;
    scanf("%d",&t);
    char ch[100];
    while(t--)
    {
        int largeE=-1,largeO=-1;
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&E[i]);
            if(largeE<E[i])
                largeE=E[i];
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d",&O[i]);
            if(largeO<O[i])
                largeO=O[i];
        }
        if(largeE<largeO)
            printf("MechaGodzilla\n");
        else
            printf("Godzilla\n");

    }
    return 0;
}
