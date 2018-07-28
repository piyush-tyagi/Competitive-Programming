#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll mod=1000000007;
vector<ll>  check[100001];
ll vis[100001];
ll ans[100001];
int main(){

    bhaag_bhaag_dkbose;
    for(ll i=0;i<=100000;i++) {
        vector<ll> c(26);
        check[i]=c;
    }
    string s; ll n;
    cin>>s;
    cin>>n;
    for(ll i=1;i<=s.length();i++){
        ll index=i-1;
        vector<ll> c(26);
        check[i]=c;
        check[i][s[index]-'a']++;


    }
    for(ll i=1;i<=s.length();i++){
        for(ll j=0;j<26;j++){
            check[i][j]+=check[i-1][j];
        }
    }

    map< vector<ll> , ll> map1;
    for(ll i=0;i<n;i++) {
        string x; cin>>x;
        vector<ll> count(26);
        for(ll j=0;j<x.length();j++)
            count[x[j]-'a']++;
        map1[count]++;
    }


    vector<ll> graph[100001];
    for(ll i=1;i<=s.length();i++){
        for(ll j=i;j<=s.length();j++){
            vector<ll> c(26);
            for(ll k=0;k<26;k++) {
                c[k] = check[j][k] - check[i-1][k];
            }
            if(map1[c]!=0){
                graph[i].push_back(j+1);

            }
        }
    }
    ll dest = s.length()+1;
    queue<ll> q;
    ans[1]=1;
    q.push(1);
    while(!q.empty()){
        ll  start= q.front(); q.pop();

        for(ll i=0;i<graph[start].size();i++){
            if(vis[graph[start][i]]==0){
                q.push(graph[start][i]);
                vis[graph[start][i]]=1;
            }

            ans[graph[start][i]]=(ans[graph[start][i]]+ans[start])%mod;
        }

    }
    cout<<ans[dest];


    return 0;
}
