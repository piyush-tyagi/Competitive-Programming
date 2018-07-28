#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ll n;
    ll m,a,b;
    cin>>n>>m>>a>>b;
    if(b/m >= a){
        cout<<a*n; return 0;
    }
    else{
        ll x;
        if(b < a*(n%m )  )
            x=b;
        else
            x=a*(n%m );

        cout<< ((n/m))*b+ x ;
    }
    return 0;
}