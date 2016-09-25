//http://www.spoj.com/problems/MVSTARS/

#include<iostream>
#include<cstdio>

using namespace std;
int visit[1009];
int main(){

    int n,e;
    scanf("%d%d",&n,&e);
    while(e--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(visit[x]!=0){
            visit[x]--;
        }
        visit[y]++;
    }
    int flag=0;
    for(int i=0;i<n;i++){
        if(visit[i]==n-1){
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
