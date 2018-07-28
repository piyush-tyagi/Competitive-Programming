#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;


int main(){
    bhaag_bhaag_dkbose;
    ll n,m;
    cin>>n>>m;
    ll cost[n],bill[m];
    for(ll i(0);i<n;i++) cin>>cost[i];
    for(ll i(0);i<m;i++) cin>>bill[i];

    ll i=0,j=0;
    ll ans=0;
    while(i<n and j<m){
        if(cost[i]<=bill[j]){
            ans++;
            i++; j++;
        }else i++;
    }
    cout<<ans;
    return 0;
}