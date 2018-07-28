#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ll n;
    cin>>n;
    pair<ll,ll> arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i].first;
        cin>>arr[i].second;
    }
    ll check;
    check=max(arr[0].first,arr[0].second);
    for(ll i=1;i<n;i++)
    {
        ll maxi=max(arr[i].first,arr[i].second);
        ll mini=min(arr[i].first,arr[i].second);
        if(maxi<=check)
        {
            check=maxi;
        }
        else if(mini<=check){
            check=mini;
        }
        else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}