//http://www.spoj.com/problems/HISTOGRA/
#include<bits/stdc++.h>

using namespace std;

long long arr[100009];

int main(){


    int n;
    scanf("%d",&n);
    while(n!=0){

        for(int i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        stack<long long> st;
        long long ans=arr[0];
        st.push(0);
        int i;
        for(i=1;i<n;i++){

            if(arr[st.top()]<=arr[i]){
                st.push(i);
            }else{
                while(!st.empty()&&arr[st.top()]>arr[i]){

                        int x=st.top();
                        st.pop();
                        if(!st.empty()){

                            long long p=(i-st.top()-1)*arr[x];
                            ans=max(ans,p);

                        }else{
                            long long p=i*arr[x];
                            ans=max(ans,p);
                        }
                }
                st.push(i);
            }
        }
        while(!st.empty()){

                        int x=st.top();
                        st.pop();
                        if(!st.empty()){

                            long long p=(i-st.top()-1)*arr[x];
                            ans=max(ans,p);

                        }else{
                            long long p=i*arr[x];
                            ans=max(ans,p);
                        }
                }

        printf("%lld\n",ans);

        scanf("%d",&n);

    }
    return 0;
}
