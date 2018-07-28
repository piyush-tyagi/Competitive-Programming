#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

ll pre[200001];
ll suf[200001];
int main(){
    bhaag_bhaag_dkbose;
    ll n;
    cin>>n;
    ll arr[n+1];
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    for(ll i=1;i<=n;i++)
         pre[i]+=pre[i-1];
    for(ll i=n;i>=1;i--)
        suf[i]+=suf[i+1];
    ll ans=-1;
    for(ll i=n;i>=1;i--){
        ll search=suf[i];
        ll index=lower_bound(pre,pre+n,search)-pre;
        if(index>=i)
            break;
        if(index<=n)
        {
            ans=suf[i];
        }
    }
    if(ans==-1)
        cout<<"0";
    else cout<<ans;


    return 0;
}