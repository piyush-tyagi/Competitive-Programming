#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll arr[100010];
ll check[100010];
int main(){

    bhaag_bhaag_dkbose;

    ll n; cin>>n;
    ll m; cin>>m;
    while(m--){
        ll l,r; cin>>l>>r;
        arr[l]++; arr[r+1]--;
    }
    for(ll i=1;i<=n+1;i++)
    {
        arr[i]+=arr[i-1];
    }
    for(ll i=1;i<=n;i++){
        check[arr[i]]++;
    }
    for(ll i=1;i<=100000;i++){
        check[i]+=check[i-1];
    }
    ll q;
    cin>> q;
    while(q--){
        ll x;
        cin>>x;
        cout<<check[100000]-check[x-1]<<endl;
    }

    return 0;
}