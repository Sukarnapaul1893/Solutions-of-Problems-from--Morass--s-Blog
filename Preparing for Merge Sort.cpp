#pragma warning(disable:4786)
#pragma warning(disable:4996)
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include<ext/pb_ds/detail/standard_policies.hpp>
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define pli pair<long long , int>
#define pil pair<int ,long long>
#define pi acos(-1)
#define pb push_back
#define mkp make_pair
#define all(a) a.begin(), a.end()
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define MAX 300005
#define INF 0x3f3f3f3f
template <class T> inline T bigmod(T p,T e,T M){ll ret = 1LL;for(; e > 0LL; e >>= 1LL){if(e & 1LL) ret = (ret * p) % M;p = (p * p) % M;}return (T)ret;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}   // M is prime}

using namespace std;
using namespace __gnu_pbds;

typedef trie<string,null_type,trie_string_access_traits<>,pat_trie_tag,trie_prefix_search_node_update>pref_trie;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

ll mx[800040];
ll arr[200005];

int query(int at, int L, int R, int l, int r,ll v){
    if(r<L || R<l)return 0;

    if(L==R){
        return L;
    }
    int mid = (L+R)/2;
    if(mx[at*2]>v){
        int x = query(at*2,L,mid,l,r,v);
        if(x!=0){
            if(arr[x]>v)return x;
        }
    }
    int y = query(at*2+1,mid+1,R,l,r,v);
    return y;
}

void update(int at, int L, int R, int pos, ll u ){
    if(L==R){
        mx[at]=u;
        return ;
    }

    int mid = (L+R)/2;

    if(pos<=mid){
        update(at*2,L,mid,pos,u);
    }
    else{
        update(at*2+1,mid+1,R,pos,u);
    }

    mx[at] = max(mx[at*2],mx[at*2+1]);
}

void build(int at , int L, int R){

    if(L==R){
        mx[at]=arr[L];
        return;
    }
    int mid = (L+R)/2;
    build(at*2,L,mid);
    build(at*2+1,mid+1,R);

    mx[at] = max(mx[at*2],mx[at*2+1]);

}


int main(){
    int n;
    cin>>n;


    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    arr[n+1]=1000000000000;
    build(1,1,n+1);
    int ans = 0;

    ordered_set st;
    for(int i=1;i<=n;i++)st.insert(i);
    int i=1;

    for(;;){

        int idx=query(1,1,n+1,i+1,n+1,arr[i]);


        cout<<arr[i]<<" ";
        ans++;


        st.erase(i);

        if(st.size()==0)return 0;

        update(1,1,n+1,i,0);

        i = idx;
        if(idx==n+1){
            auto it= st.begin();
            i=(*it);
            cout<<"\n";
            continue;
        }
    }
}
