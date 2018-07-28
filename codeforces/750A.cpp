#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,k;
    cin>>n>>k;
    ll time_left=240-k;
    ll ans=0;
    ll deduct=5,i=1;
    while(i<=n){

        if(time_left-deduct>=0){
            ans++;
            time_left-=deduct;
            i++;
            deduct=5*i;
        } else break;

    }
    cout<<ans;

    return 0;
}