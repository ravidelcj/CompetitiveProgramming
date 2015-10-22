//http://www.spoj.com/problems/KGSS/
#include<cstdio>
#include<iostream>
using namespace std;
#define M 500009
long long arr[M];
long long y;

long long maximum(long long a,long long b)
{
    if(a>b)
        return a;
    else
        return b;
}
struct node
{
    long long val,ma;
}tree[M];


void build(int s,int e,int index)
{
    if(s>e)
        return ;
    if(s==e)
    {
        tree[index].val=arr[s];
        tree[index].ma=arr[s];
        return ;
    }

    int mid=(s+e)/2;

    build(s,mid,2*index+1);
    build(mid+1,e,2*index+2);
    tree[index].val=maximum(maximum(tree[2*index+1].ma+tree[2*index+2].ma,tree[2*index+1].val),tree[2*index+2].val);
    tree[index].ma=maximum(tree[2*index+1].ma,tree[2*index+2].ma);
}

void update(int s,int e ,int index,int i)
{
    if(s>e||s>i||e<i)
    {
        return;
    }

    if(s==e&&s==i)
    {
       // cout<<"Changed\n";
        tree[index].val=tree[index].ma=y;
        arr[s]=y;
        return ;
    }
   // cout<<"update2\n";
    int mid=(s+e)/2;
    update(s,mid,2*index+1,i);
    update(mid+1,e,2*index+2,i);

     tree[index].val=maximum(maximum(tree[2*index+1].ma+tree[2*index+2].ma,tree[2*index+1].val),tree[2*index+2].val);
    tree[index].ma=maximum(tree[2*index+1].ma,tree[2*index+2].ma);
}
node temp;
node query(int s,int e,int qs,int qe,int index)
{
    //printf("inside\n");

    if(s>e||s>qe||e<qs)
        return temp;

    if(s>=qs&&e<=qe)
        return tree[index];

    int mid=(s+e)/2;
    node res;
     node x=query(s,mid,qs,qe,2*index+1);
     node y=query(mid+1,e,qs,qe,2*index+2);
    res.val=maximum(maximum(x.ma+y.ma,x.val),y.val);
    res.ma=maximum(x.ma,y.ma);
    return res;
}
int main()
{
    temp.ma=0;
    temp.val=0;
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    build(0,n-1,0);

    int q;
    scanf("%d",&q);
    while(q--)
    {
        //printf("1\n");
        char ch;
        long long x;
       cin>>ch>>x>>y;
        fflush(stdin);
       // printf("%c %d %d ",ch,x,y);
        if(ch=='Q')
        {
          //  printf("Inside");
            node res=query(0,n-1,x-1,y-1,0);
            printf("%lld\n",res.val);
        }
        else
        {//printf("2\n");
            int i;
            update(0,n-1,0,x-1);
        //    for(int i=0;i<n;i++)
          //      cout<<arr[i]<<" ";
        }
    }
    return 0;
}
