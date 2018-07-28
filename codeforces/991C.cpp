#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll vasya=0, petya=0;
bool check(ll it,ll n){
    vasya=0,petya=0;
    while(n>0){
        if(n<=it)
        {
            vasya+=n;

            break;
        }else{
            vasya+=it;
            n-=it;

            petya+=(n/10);
            n-=n/10;
        }

    }

    return vasya>=petya;
}

int main(){
    ll n;
    cin>>n;
    ll end=n,start=1;
    ll ans=n%2==0?n/2:n/2+1;

    while(start<=end){
        ll mid=(start+end)/2;
        if(mid==0)
            break;
        if (check(mid,n)){
            ans=min(ans,mid);
            end=mid-1;
        }else{
            start=mid+1;
        }
    }
    cout <<ans;
    return 0;
}