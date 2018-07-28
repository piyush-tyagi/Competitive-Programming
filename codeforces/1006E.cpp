#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector<ll> sequence;
ll pos[200001];
ll siz[200001];
ll vis[200001];
vector<ll> graph[200001];
ll coun=0;
void dfs(ll x){
    vis[x]=1;
    pos[x]=coun;
    coun++;
    sequence.push_back(x);
    for(ll i=0;i<graph[x].size();i++){
        if(!vis[graph[x][i]]){
            dfs(graph[x][i]);
            siz[x]+=siz[graph[x][i]];
        }
    }
}
int main(){

    bhaag_bhaag_dkbose;
    for(ll i=0;i<200001;i++)
        siz[i]=1;
    ll n,q; cin>>n>>q;

    for(ll i=2;i<=n;i++){
        ll x; cin>>x;
        graph[x].push_back(i);
    }
    for(ll i=1;i<=n;i++)
    {
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(1);
    while(q--){
        ll u,k;
        cin>>u>>k;
        if(k>siz[u])
            cout<<-1<<endl;
        else cout<<sequence[pos[u]+k-1]<<endl;
    }


    return 0;
}
