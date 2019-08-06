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
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;




int main(){
    IOS
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;
    ll arr[n],pre[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);

    for(int i=n-1;i>=0;i--){
        if(i==n-1){
            pre[i]=arr[i];
            continue;
        }
        else{
            pre[i]=arr[i]+pre[i+1];
        }
    }
    ll ans;
    ll prev=0;
    for(int i=0;i<n;i++){
        if(i==0){
            ans=(pre[i]-arr[i]*(n-i))+prev;

        }
        else{
            ans=min(ans,pre[i]-arr[i]*(n-i)+prev);
        }
        prev+=arr[i];
    }
    cout<<ans;
}
