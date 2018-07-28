#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main(){

    bhaag_bhaag_dkbose;
    ll t; cin>>t;

    while(t--){
        string m,n;
        cin>>n>>m;
        ll r1=0,r2=0;
        for(ll i=0;i<n.length();i++){
            r1=(r1+(n[i]-'0'))%3;
        }
        for(ll i=0;i<m.length();i++){
            r2=(r2+(m[i]-'0'))%3;
        }
        cout<<(r1*r2)%3<<endl;
    }
    return 0;
}