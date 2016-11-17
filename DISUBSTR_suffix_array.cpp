//http://www.spoj.com/problems/DISUBSTR/
//using nsuffix array
#include<bits/stdc++.h>

using namespace std;
int lcp[1009];

int calcLcp(string s1, string s2){
    int l = 0;
    while(l<s1.length()&&l<s2.length()&&s1[l]==s2[l])l++;
    return l;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        vector<string> v;
        for(int i=0;i<str.length();i++){
            v.push_back(str.substr(i,str.length()-i));
        }
        sort(v.begin(), v.end());
        int ans=v[0].length();
        for(int i=1;i<v.size();i++){
            lcp[i]=calcLcp(v[i], v[i-1]);
            ans+=(v[i].length()-lcp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}
