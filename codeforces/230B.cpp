#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll make_table_of_primes[1000011];
vector<ll> square_of_prime;
bool make(){
    make_table_of_primes[1]=1;
    for(ll i(2);i<=1000;i++){
        if(!make_table_of_primes[i]){
            for(ll j(2*i);j<=1000000;j+=i){
                make_table_of_primes[j]=1;
            }
        }
    }
    for(ll i(2);i<=1000000;i++){
        if(!make_table_of_primes[i]){
            square_of_prime.push_back(i*i);
        }
    }
}
int main(){
    ll n;
    cin>>n;
    ll arr[n];
    make();
    for(ll i(0);i<n;i++)
    {
        cin>>arr[i];
    }
    for(ll i(0);i<n;i++){
        if(binary_search(square_of_prime.begin(),square_of_prime.end(),arr[i])){
            cout<<"YES"<<endl;
        }else cout<<"NO"<<endl;
    }


    return 0;
}