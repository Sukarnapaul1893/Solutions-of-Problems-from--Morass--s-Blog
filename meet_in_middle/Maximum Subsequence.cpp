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
    ll m;
    cin>>n>>m;
    vector<ll>vec1,vec2;
    if(n==1){
        ll a;
        cin>>a;
        cout<<a%m<<"\n";
        return 0;
    }
    for(int i=0;i<n/2;i++){
        ll a;
        cin>>a;
        vec1.pb(a%m);
    }
    for(int i=n/2;i<n;i++){
        ll a;
        cin>>a;
        vec2.pb(a%m);
    }

    vector<ll >sum1,sum2;
    sum1.pb(0LL);
    sum2.pb(0LL);
    for(int i=0;i<vec1.size();i++){

        int sz = sum1.size();
        for(int j=0;j<sz;j++){
            sum1.pb((sum1[j]+vec1[i])%m);
        }

    }
    for(int i=0;i<vec2.size();i++){

        int sz= sum2.size();
        for(int j=0;j<sz;j++){

            sum2.pb((sum2[j]+vec2[i])%m);
        }

    }
    sort(sum1.begin(),sum1.end());
    sort(sum2.begin(),sum2.end());

    ll ans = 0;
    for(int i=0;i<sum1.size();i++){
        int cur = (m-1)-sum1[i];
        int x = lower_bound(sum2.begin(),sum2.end(),cur)-sum2.begin();
        int x2 = upper_bound(sum2.begin(),sum2.end(),cur)-sum2.begin();
        ans = max((sum2[x-1]+sum1[i])%m,ans);
        ans = max((sum2[x2-1]+sum1[i])%m,ans);
        ans = max((sum2[sum2.size()-1]+sum1[i])%m,ans);


    }
    cout<<ans<<"\n";
}
