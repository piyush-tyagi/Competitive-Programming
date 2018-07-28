#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll no_of_shops;
    cin>>no_of_shops;
    ll shops[no_of_shops];
    for ( ll i(0);i<no_of_shops;i++)
        cin>>shops[i];
    sort(shops,shops+no_of_shops);
    ll no_of_coins;
    cin>>no_of_coins;
    ll coins[no_of_coins];
    for(ll i (0);i<no_of_coins;i++)
    {
        cin>>coins[i];
        cout<<upper_bound(shops,shops+no_of_shops,coins[i])-shops<<endl;

    }
    return 0;
}