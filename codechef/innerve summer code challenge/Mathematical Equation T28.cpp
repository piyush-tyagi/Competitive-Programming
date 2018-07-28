#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll mod=1000000009;
ll inverse_modulo(ll x, ll y) {
    ll res = 1;
    while (y > 0) {

        if (y & 1)
            res =  (res * x)%mod;
        y = y >> 1;
        x = (x * x)%mod;

    }
    return res;
}

int main(){

    bhaag_bhaag_dkbose;
    ll n,q;
    cin>>n>>q;
    unordered_map<ll,ll> unorderedMap;
    while(n--){
        ll a,b; cin>>a>>b;
        ll x=4*a*b+2*max(a,b);
        unorderedMap[x]++;
    }
    while(q--){
        ll k; cin>>k;
        ll check=k*(k+1);

        ll sum=unorderedMap[check];
        if(sum==0)
            cout<<"-1"<<endl;
        else cout<<inverse_modulo(sum,mod-2)<<endl;

    }


    return 0;
}