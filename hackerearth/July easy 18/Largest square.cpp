#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

void swap_num(ll &x,ll &y){
    ll temp=x;
    x=y;
    y=temp;
}
int main(){
    bhaag_bhaag_dkbose;
    ll n;
    cin>>n;
    map <ll , vector<pair< pair < ll,ll> , pair<ll ,ll> > > > graph;
    pair<ll,ll> cordinates [n];
    for(ll i(0);i<n;i++){
        ll x,y; cin>>x>>y;
        cordinates[i]={x,y};
    }
    unordered_map<pair<ll,ll > ,ll> check;
    for(ll i(0);i<n;i++){
        for ( ll j=0;j<n;j++){
            ll x1=cordinates[i].first;
            ll x2=cordinates[j].first;
            ll y1=cordinates[i].second;
            ll y2=cordinates[j].second;
            if(x1==x2 or y1==y2){
                if(x1>x2){
                    swap_num(y1,y2);
                    swap_num(x1,x2);
                }
                ll len;
                if(x1==x2)
                    len=(y1-y2);
                else
                    len=x1-x2;
                graph[len].push_back({{x1,y1},{x2,y2} });
                check[{x1,y1}]++;
                check[{x2,y2}]++;
            }
        }
    }
    ll ans=0;
    ll x,y;
    for (auto it=graph.rbegin();it!=graph.rend();it++){
        ll len=it->first;
        for( auto ti=graph[len].begin(); ti!=graph[len].end();ti++){

        }
    }


    return 0;
}