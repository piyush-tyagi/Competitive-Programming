#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
set<ll> zinda;
vector<ll> get_the_vector(ll l,ll r){
    vector<ll> v;
    set<ll>::iterator it=zinda.lower_bound(l);
    while(it!=zinda.end()){
        if(*it<=r){
            v.push_back(*it);
            it++;
        }else break;

    }
    return  v;
}
int main(){

    bhaag_bhaag_dkbose;
    ll n,m;
    cin>>n>>m;

    for(ll i=1;i<=n;i++)
        zinda.insert(i);
    ll ans[n+1]; memset(ans,0,sizeof ans);
    while(m--){
        ll l,r,x; cin>>l>>r>>x;
        vector<ll> v=get_the_vector(l,r);

        for(ll i=0;i<v.size();i++){
            if(v[i]!=x){
                ans[v[i]]=x;
                zinda.erase(v[i]);
            }
        }

    }
    for(ll i=1;i<=n;i++)
        cout<<ans[i]<<" ";

    return 0;
}