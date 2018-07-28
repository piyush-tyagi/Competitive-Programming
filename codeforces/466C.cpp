#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ll n;
    cin>>n;
    ll arr[n];
    ll prefix_sum[n];
    ll pos1[n];
    ll pos2[n];
    for(ll i(0);i<n;i++){
        prefix_sum[i]=pos1[i]=pos2[i]=0;
    }

    ll ans=0;

    for ( ll i(0); i< n;i++){
        cin>>arr[i];
        if(i==0)
            prefix_sum[i]=arr[i];
        else
            prefix_sum[i]=prefix_sum[i-1]+arr[i];

    }
    if(n<3 or prefix_sum[n-1]%3!=0){
        cout<<"0";
        return 0;
    }

    ll sum1=prefix_sum[n-1]/3;
    ll sum2=2*(prefix_sum[n-1]/3);

    for ( ll i(0); i< n;i++){
        if(prefix_sum[i]==sum1)
            pos1[i]=1;
        if(prefix_sum[i]==sum2)
        {
            pos2[i]=1;
        }

    }

    ll count0=0;
    if(sum1==0){
        for ( ll i(0); i< n;i++){
            if(pos1[i]!=0){
                count0++;
            }
        }
        count0--;
        cout<<count0*(count0-1)/2;
        return 0;
    }else{
        for(ll i(n-2);i>=0;i--){
            pos2[i]+=pos2[i+1];
        }
        for(ll i(0);i<n;i++){
            if(pos1[i]!=0){
                ans+=pos2[i];
            }
        }

    }
    cout<<ans;


    return 0;
}