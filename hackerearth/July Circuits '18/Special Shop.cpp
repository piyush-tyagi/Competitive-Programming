#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main(){

    bhaag_bhaag_dkbose;

    ll t; cin>>t;
    while(t--){
        ll ans=1000000000000000000;
        ll n,a,b;
        cin>>n>>a>>b;
        double x = (double)(b*n)/(double)(a+b);
        ll x1 = floor(x);
        ll x2=ceil((x));
        ans=min(ans,a*(x1*x1)+b*(n-x1)*(n-x1));
        ans=min(ans,a*x2*x2+b*(n-x2)*(n-x2));
        x = (double)(a*n)/(double)(a+b);
        x1 = floor(x);
        x2=ceil((x));
        ans=min(ans,a*(x1*x1)+b*(n-x1)*(n-x1));
        ans=min(ans,a*x2*x2+b*(n-x2)*(n-x2));
        cout<<ans<<endl;
    }

    return 0;
}