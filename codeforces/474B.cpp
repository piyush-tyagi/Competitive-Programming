#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll no_of_worms;
    cin>>no_of_worms;
    ll worms[no_of_worms+1];

    worms[0]=0;
    for(ll i(1);i<=no_of_worms;i++)
    {
        cin>>worms[i];
        worms[i]+=worms[i-1];
    }
    ll no_of_labels;
    cin>>no_of_labels;
    ll labels[no_of_labels];
    for(ll i(0);i<no_of_labels;i++) {
        cin >> labels[i];
        cout<<lower_bound(worms+1,worms+no_of_worms,labels[i])-worms<<endl;
    }

    return 0;
}