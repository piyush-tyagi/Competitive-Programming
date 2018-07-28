#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main(){

    bhaag_bhaag_dkbose;
    ll t; cin>>t;

    while(t--){
        ll n; cin>>n;
        ll x;
        cin>>x;
        for(ll i=1;i<=n-1;i++){
            ll y;
            cin>>y;
            x=__gcd(x,y);
        }
        if(x==1)
            cout<<"YES"<<endl;
        else cout <<"NO"<<endl;

    }
    return 0;
}