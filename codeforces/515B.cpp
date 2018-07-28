#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll happy_boy[100],happy_girl[100];
int main(){

    bhaag_bhaag_dkbose;
    ll boys,girls;
    cin>>boys>>girls;
    ll b,g;
    cin>>b;
    for(ll i=0;i<b;i++){
        ll x; cin>>x;
        happy_boy[x]++;
    }
    cin>>g;
    for(ll i=0;i<g;i++){
        ll x; cin>>x;
        happy_girl[x]++;
    }
    map<pair<ll,ll> , ll > unorderedMap;
    ll day=0;
    ll i=1;
    while(true){
        ll flg=0;
        while(day<min(boys,girls)*i) {
            if(unorderedMap[{day%boys,day%girls}])
            {
                cout<<"No";
                return 0;
            }
            if (happy_boy[day % boys] or happy_girl[day % girls]) {
                happy_boy[day % boys] = happy_girl[day % girls] = 1;
                unorderedMap[{day%boys,day%girls}]=0;
            }else{
                flg=1;
                unorderedMap[{day%boys,day%girls}]++;
            }

            day++;
        }
        if(flg==0)
        {
            cout<<"Yes";
            return 0;
        }
        i++;
    }
    cout<<"YES";
    return 0;
}
