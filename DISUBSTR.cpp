//http://www.spoj.com/problems/DISUBSTR/

#include<iostream>
#include<cstdio>
#include<ctype.h>
#include<cstring>
using namespace std;

char str[1009];

struct node{

    node *next[26];

};

long long countSub;

node* addNode(){

    countSub++;
    node *temp = new node;
    for(int i=0;i<=26;i++)
        temp->next[i]=NULL;

    return temp;

}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){

        cin>>str;

        int l = strlen(str);
        node *trie= NULL,*ptr=NULL;

        countSub = 0;
        trie = addNode();
        countSub--;
        int flag = 0;
        int i=0;
        while(i<l){
            ptr = trie;
            for(int j = i; j<l ; j++){
                if(ptr->next[str[j]-'A'] == NULL){
                ptr ->next[str[j]-'A'] = addNode();
                }
                ptr=ptr->next[str[j]-'A'];
            }
            i++;

        }

        printf("%lld\n",countSub);
    }
    return 0;
}
