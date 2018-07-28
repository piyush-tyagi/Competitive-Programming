#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll check[101];
int main(){

    bhaag_bhaag_dkbose;

    ll n; cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++) cin>>arr[i];
    ll m; cin>>m;
    ll brr[m];

    for(ll i=0;i<m;i++) {
        cin>>brr[i];
        check[brr[i]]=1;
    }
    map<ll,ll> Map;
    for (ll i=0;i<m;i++){
        for(ll j=0;j<n;j++){
            if(brr[i]-arr[j]>0){
                Map[brr[i]-arr[j]]++;
            }
        }
    }
    for(auto it=Map.begin();it!=Map.end();it++){
        ll flg=0;
        for(ll i=0;i<n;i++){
            if(check[arr[i]+it->first] ==0 )
            {
                flg=1;
                break;
            }


        }
        if(flg==0)
            cout<<it->first<<" ";
    }

    return 0;
}