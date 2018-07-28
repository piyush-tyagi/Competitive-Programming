#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll primes[110];
void generate_primes(){
    primes[0]=primes[1]=1;
    for (ll i=2;i<=10;i++){
        if(!primes[i]){
            for(ll j=2*i;j<=101;j+=i){
                primes[j]=1;
            }
        }
    }
}

int main(){

    bhaag_bhaag_dkbose;
    ll t; cin>>t;
    generate_primes();
    ll ans=100000;
    while(t--){
        ll n;
        cin>>n;
        ll flg=0;
        ans=10000000;
        for(ll i=0;i<n;i++){
            ll x; cin>>x;
            if(primes[x]==0){
                ans=min(ans,x);
            }
            if(x==1)
                flg=1;
        }
        if(flg==0)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}