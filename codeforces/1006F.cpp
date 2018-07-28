#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll grid[21][21];
ll n,m,k;
ll ans=0,oneway,otherway;
map<ll,ll> count1[21][21];
void dfs_oneway(ll i,ll j,ll xorr,ll len){
    xorr^=grid[i][j];
    if(len==oneway) {
        count1[i][j][xorr]++;
        return;
    }

    if(i+1<n ){
        dfs_oneway(i+1,j,xorr,len+1);
    }
    if(j+1<m){
        dfs_oneway(i,j+1,xorr,len+1);
    }
}
void dfs_otherway(ll i,ll j,ll xorr,ll len){

    if(len==otherway){
        if(count1[i][j][xorr^k])
            ans+=count1[i][j][xorr^k];
        return ;
    }
    if(i-1>=0 ){
        dfs_otherway(i-1,j,xorr^grid[i][j],len+1);
    }
    if(j-1>=0){
        dfs_otherway(i,j-1,xorr^grid[i][j],len+1);
    }
}
int main(){

    bhaag_bhaag_dkbose;
    cin>>n>>m>>k;

    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            cin>>grid[i][j];

        }
    }
    oneway=(n+m-2)/2;
    otherway=n+m -2 - oneway;
    dfs_oneway(0,0,0,0);

    dfs_otherway(n-1,m-1,0,0);

    cout<<ans<<endl;


    return 0;
}
