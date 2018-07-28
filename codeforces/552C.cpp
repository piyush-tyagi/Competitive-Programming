#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main(){

    bhaag_bhaag_dkbose;
    ll w,n;
    cin>>w>>n;
    while(n>0){
        if(n%w==0 or n%w==1)
        {
            n=n/w;
        }else if (n%w==w-1){
            n=(n+1)/w;
        }else{
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
    return 0;
}
