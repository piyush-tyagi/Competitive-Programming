#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll mod=1000000007;
ll power(ll x, ll y) {
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

    ll t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        if(k==1)
        {
            cout<<"1"<<endl;
        }
        else {
            ll ans = (k % mod * (power(k, n) - 1) % mod) % mod;
            ll inv = power(k - 1, mod - 2);
            ans = (ans * inv) % mod;
            cout << ans << endl;
        }
    }

    return 0;
}