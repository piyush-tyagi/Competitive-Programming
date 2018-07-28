#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool checkvowel(char ch){
    if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')
        return true;
    return false;
}
int main(){

    string s;
    cin>>s;
    if(s.length()==1 and !checkvowel(s[0]) and s[0]!='n')
    {
        cout<<"NO";
        return 0;
    }
    if(!checkvowel(s[s.length()-1]) and s[s.length()-1]!='n')
    {
        cout<<"NO";
        return 0;
    }
    for(ll i=1;i<s.length();i++){
        if(!checkvowel(s[i-1]))
        {
            if(s[i-1]!='n' and !checkvowel(s[i]))
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}