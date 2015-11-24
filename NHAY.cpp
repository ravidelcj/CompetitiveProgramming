//http://www.spoj.com/problems/NHAY/
#include<iostream>
#include<cstring>
#define M 10000000
using namespace std;

int pat[M];
char ned[M],hay[M];
int n,m;
void pref()
{
    int k=-1;
    pat[0]=0;
    for(int i=1;i<m;i++)
    {
        while(k>-1&&ned[k+1]!=ned[i])
        {
            k=pat[k];
            if(k==0)
            {
                k=-1;
                break;
            }
        }

        if(ned[k+1]==ned[i])
            k=k+1;

        pat[i]=k+1;
    }
}


void check()
{

    int flag=0;
    int k=0;

    for(int i=0;i<n;i++)
    {


        while(k!=0&&ned[k]!=hay[i])
                k=pat[k-1];

        if(ned[k]==hay[i])
            k++;

        if(k==m)
        {
            printf("%d\n",i-m+1);
            k=pat[k-1];
            flag=1;
        }
    }
    if(flag==0)
        printf("\n\n");
    else
        printf("\n");


}
int main()
{
    while(scanf("%d",&m)!=EOF)
    {
        scanf("%s%s",ned,hay);
        pref();

        n=strlen(hay);
        check();
    }
    return 0;

}
