// example of finding a closest element to any given element in given range
// it can also be used to find kth smallest element in given range
// size of merge_sort_tree can be reduced if we make one tree for a level instead of different trees

#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector<ll> merge_sort_tree[500001];
ll arr[100001];
void build_tree( ll cur , ll l , ll r )
{
    if( l==r )
    {
        merge_sort_tree[cur].push_back( arr[ l ] );
        return ;
    }
    int mid = l+(r-l)/2;
    build_tree(2*cur, l , mid );
    build_tree(2*cur+1 , mid+1 , r );
    merge( merge_sort_tree[2*cur].begin(),merge_sort_tree[2*cur].end()  ,
           merge_sort_tree[2*cur+1].begin(),merge_sort_tree[2*cur+1].end(),
           back_inserter(merge_sort_tree[cur]) );
}
ll query( ll cur, ll strt, ll end, ll l, ll r, ll k)
{

    if( strt > r || l > end )
    {
        return -10000000000000000;
    }
    if( l<=strt && end<=r )
    {
        ll sec=-10000000000000000;
        ll x=lower_bound(merge_sort_tree[cur].begin(),merge_sort_tree[cur].end(),k)-merge_sort_tree[cur].begin();
        if(x==0)
            return merge_sort_tree[cur][x];
        if(x<merge_sort_tree[cur].size()){
            if(abs(merge_sort_tree[cur][x-1]-k)>abs(merge_sort_tree[cur][x]-k))
                sec=merge_sort_tree[cur][x];
            else
                sec=merge_sort_tree[cur][x-1];
        }else{
            sec=merge_sort_tree[cur][x-1];
        }
        return sec;
    }
    int mid=strt+(end-strt)/2;
    ll x=query(2*cur,strt,mid,l,r,k),y=query(2*cur+1,mid+1,end,l,r,k);;
    if(abs(x-k)<abs(y-k))
        return x;
    else
        return y;
}
int main(){

    bhaag_bhaag_dkbose;
    ll n,q; cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        arr[i]=1000000000-arr[i];
    }
    build_tree(1,1,n);

    while(q--){
        ll l,r,k;
        cin>>l>>r>>k;
        cout<<1000000000-query(1,1,n,l,r,k)<<endl;
    }

    return 0;
}