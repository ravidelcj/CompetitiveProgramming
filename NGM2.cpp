//PRINCIPLE OF INCLUSION AND EXCLUSION
//www.spoj.com/problems/NGM2
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef int in;
ll arr[20];
in n,k;

template< class T > T gcd(const T a, const T b) { return (b ? gcd<T>(b, a%b) : a); }
template< class T > T lcm(const T a, const T b) { return (a / gcd<T>(a, b) * b); }

in numberOfElement(int a){

    ll prod = 1,g;
    for(int i = 0;i<k;i++){
        if(a&(1<<i)){
            prod = lcm(prod,arr[i]);
        }
    }
    in counter = n/prod;
    return counter;

}

in countBit(in n)
{
     in counter = 0;
    while (n)
    {
      n &= (n-1) ;
      counter++;
    }
    return counter;
}

in solve(){

    in x = 1<<k;
    in ans=n;
    for(in i=1;i<x;i++){
        in noBit = countBit(i);

        if(noBit&1){
            ans -= numberOfElement(i);
        }else{
            ans += numberOfElement(i);
        }

    }
    return ans;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>k;
    int flag=1;
    for(int i=0;i<k;i++){
        cin>>arr[i];
        if(arr[i]==1){
            flag=0;
        }
    }
    if(!flag){
        cout<<"0\n";
        return 0;
    }
    in x = solve();
    cout<<x;
    return 0;
}
