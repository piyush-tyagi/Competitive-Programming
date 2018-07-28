#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main(){
    string s1,s2;
    cin>>s1>>s2;
    stack<char> first,second;
    for(ll i=0;i<s1.length();i++)
        first.push(s1[i]);
    for(ll i=0;i<s2.length();i++)
        second.push(s2[i]);
    ll count=0;
    while(!first.empty() and !second.empty() and first.top()==second.top())
    {
        first.pop(); second.pop();
        count++;
    }
    cout<<s1.length()+s2.length()-2*count;

}
