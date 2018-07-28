//segment tree
#include<bits/stdc++.h>
#define ll long long
#define bhaag_bhaag_dkbose ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
ll arr[1<<17+1];
ll seg_tree[2*((1<<17)+1)+1];
ll build_tree(ll node, ll strt, ll end,ll level){
    if(strt==end){
        seg_tree[node]=arr[strt];
        return seg_tree[node];
    }
    ll mid=(strt+end)/2;
    ll left_child= build_tree(2*node,strt,mid,level+1);
    ll right_child= build_tree(2*node+1,mid+1,end,level+1);
    if(level%2==0){
        return seg_tree[node]=left_child | right_child;
    }else{
        return seg_tree[node]=left_child ^ right_child;
    }

}
void update(ll node, ll strt,ll end,ll index,ll value,ll level){
    if(strt==end){
        seg_tree[node]=arr[index]=value;
    }
    else{
        ll mid=(strt+end)/2;
        if(index>=strt and index<=mid)
            update(2*node,strt,mid,index,value,level+1);
        else
            update(2*node+1,mid+1,end,index,value,level+1);
        if(level%2==0){
            seg_tree[node]=seg_tree[2*node] | seg_tree[2*node+1];
        }else{
            seg_tree[node]=seg_tree[2*node] ^ seg_tree[2*node+1];
        }

    }


}
int main(){

    bhaag_bhaag_dkbose;
    ll n,q; cin>>n>>q;
    for(ll i=1;i<=(1<<n);i++) cin>>arr[i];
    ll level;
    if(n%2==0) level=1;
    else level=0;
    build_tree(1,1,1<<n,level);
    while(q--){
        ll index,value; cin>>index>>value;
        update(1,1,1<<n,index,value,level);
        cout<<seg_tree[1]<<endl;

    }

    return 0;
}