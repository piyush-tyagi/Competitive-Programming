#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;


int main(){
    bhaag_bhaag_dkbose;
    string s;
    cin>>s;
    ll count1=0;
    ll count0=0;
    string ans="";
    ll flg=0;
    ll index=-1;
    for(ll i=0;i<s.length();i++){
        if(s[i]=='1')
            count1++;
        if(s[i]=='0' and flg==0)
            count0++;
        if(s[i]=='2' and flg==0){
            flg=1;
            index=i;
        }

    }
    for(ll i=0;i<count0;i++)
        ans+="0";
    for(ll i=0;i<count1;i++)
        ans+="1";
    if(flg==1)
        ans+="2";
    if(flg==1) {
        index++;
        while (index < s.length()) {
            count0 = 0;
            while (s[index] != '2' and index < s.length()) {
                if (s[index] == '0') count0++;
                index++;
            }
            for (ll i = 0; i < count0; i++)
                ans += "0";
            if (index < s.length() and s[index] == '2')
                ans += "2";
            index++;
        }
    }
    cout<<ans;
    return 0;
}