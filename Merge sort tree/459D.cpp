// used the concept number of elements less than
// prefix_count(i) in range i+1 to n in merge sort tree
// merge sort tree made on suffix_count
// prefix_count(i) is number of times arr[i] occurs in 1 to i
// suffix_count(i) is number of times arr[i] occurs in  i to n
// ***********  1st solution
#include<bits/stdc++.h>
#define ll long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll n;
ll  pre_count[1000001],suf_count[1000001];
ll arr[1000001];
vector<ll> merge_sort_tree[5000001];
void build_tree( ll cur , ll l , ll r )
{
    if( l==r )
    {
        merge_sort_tree[cur].push_back( suf_count[ l ] );
        return ;
    }
    ll mid = l+(r-l)/2;
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
        return 0;
    }
    if( l<=strt && end<=r )
    {
        ll x=lower_bound(merge_sort_tree[cur].begin(),merge_sort_tree[cur].end(),k)-merge_sort_tree[cur].begin();
        return x;
    }
    int mid=strt+(end-strt)/2;
    ll p= query(2*cur,strt,mid,l,r,k)+query(2*cur+1,mid+1,end,l,r,k);
    return p;
}
int main(){

    bhaag_bhaag_dkbose;
    cin>>n;
    unordered_map<ll,ll> un1,un2;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        un1[arr[i]]++;
        pre_count[i]=un1[arr[i]];
    }
    for(ll i=n;i>=1;i--){
        un2[arr[i]]++;
        suf_count[i]=un2[arr[i]];
    }

    long long  ans=0;
    build_tree(1,1,n);
    for(ll i=1;i<=n-1;i++){
        long long  x=query(1,1,n,i+1,n,pre_count[i]);
        ans+=x;
    }
    cout<<ans<<endl;
    return 0;
};

//********************* 2nd solution using BIT
// here bit is made from right to left on the suffix_count
//then from left to right  current element is deleted (bcoz i+1 to n needed)
// and number of elements less than the count of current elements
// in bit are added in answer.
#include<bits/stdc++.h>
#define ll long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll n;
ll arr[1000001];
long long  bit[1000000+10];
void build(ll i,ll val){
    for(;i<=1000010;i+=(i&-i)){
        bit[i]+=val;
    }
}
ll query(ll i){
    long long  ans=0;
    for(;i>0;i-=(i&-i)){
        ans+=bit[i];
    }
    return ans;
}
int main(){

    bhaag_bhaag_dkbose;
    cin>>n;
    unordered_map<ll,ll> un1,un2;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(ll i=n;i>=1;i--){
        un1[arr[i]]++;
        build(un1[arr[i]],1);
    }
    long long ans=0;
    for(ll i=1;i<=n-1;i++){
        build(un1[arr[i]],-1);
        un1[arr[i]]--;
        un2[arr[i]]++;
        ans+=query(un2[arr[i]]-1);
    }

    cout<<ans<<endl;
    return 0;
};
