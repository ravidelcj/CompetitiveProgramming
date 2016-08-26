//http://www.spoj.com/problems/PHONELST/
//using trie
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct node{

    int valid[10];
    node* next[10];

};


char str[10000];
node* addNode(int x = 0){

    node *temp = new node;
    for(int i=0;i<=9;i++){
        temp -> next[i] = NULL;
        temp->valid[i]=x;
    }

    return temp;

}

int main()
{

    int t;
    scanf("%d",&t);
    while(t--){

        int n;
        scanf("%d",&n);


        int check = 0 ;

        node *trie=NULL,*ptr=NULL;

        trie = addNode();
        for(int i=0;i<n;i++){

            cin>>str;
            int l = strlen(str);
            ptr=trie;

            for(int j=0;j<l;j++){

                //cout<<j<<endl;
                if(ptr->next[str[j]-'0']==NULL){
                    ptr->next[str[j]-'0']=addNode();

                }
                ptr=ptr->next[str[j]-'0'];

                if(ptr->valid[str[j]-'0'] == 1){
                    check = 1;
                    //cout<<j<<endl;
                }
                if(j==l-1)
                {
                       ptr->valid[str[j]-'0']=1;
                       for(int i=0;i<=9;i++){
                            if(ptr->next[i]!=NULL)
                            {
                                check = 1;
                                break;
                            }
                       }
                }


        }


      }
         if(check)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
