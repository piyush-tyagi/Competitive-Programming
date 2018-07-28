#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main(){
    bhaag_bhaag_dkbose;
    ll n;
    cin>>n;
    ll arr[n];
    ll ans=0;
    ll flg=0,count=0,count0=0;
    for(ll i(0);i<n;i++){
        cin>>arr[i];

        if(arr[i]>0)
        {
            flg=1;
        }
        if(arr[i]==0)
            count0++;
        if(arr[i]>=0)
        {
            ans+=arr[i];
            count++;
        }

    }

    if(flg==0){
        ans=*max_element(arr,arr+n);
        if(ans==0)
        {
            count=count0;
        }
        else
            count=1;
    }
    cout<<ans<<" "<<count;

    return 0;
}