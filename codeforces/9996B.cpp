#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
 ll n; ll arr[1000008]; 
 cin>>n;
 for(ll i=0;i<n;i++)
  cin>>arr[i];
  ll ans=1e9;
  ll index=0;
  for(ll i=0;i<n;i++){
                    
                   arr[i]-=i;
                   if(ans>(arr[i]+n-1)/n) 
                   {
                      ans=  (arr[i]+n-1)/n;   index=i+1;                                         
                   }
                   
  }
  
  cout<<index;
 
 return 0;                                                  
}