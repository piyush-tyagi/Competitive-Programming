#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;


int main(){
    bhaag_bhaag_dkbose;
    ll n; cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]%2==1)
            cout<<arr[i]<<" ";
        else cout<<arr[i]-1<<" ";
    }
    return 0;
}