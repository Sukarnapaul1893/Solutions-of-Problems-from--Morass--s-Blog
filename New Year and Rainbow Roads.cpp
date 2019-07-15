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




int main(){
    //IOS
    //freopen("output.txt","w",stdout);
    int n;
    cin>>n;

    ll pos[n];
    char color[n];
    int num_of_g = 0;
    multiset<ll>r,b,g;
    map<ll,char>mp;
    for(int i=0;i<n;i++){
        ll p;
        char c;
        cin>>p>>c;

        pos[i]=p;
        color[i]=c;
        mp[p]=c;
        if(c=='G'){
            num_of_g++;
            g.insert(p);
        }
        else if(c=='R'){
            r.insert(p);
        }
        else{
            b.insert(p);
        }
    }
    ll ans =0;
    ll prev;
    map<pair<ll,ll>,ll>gg,ggr,ggb;
    for(auto it=g.begin();it!=g.end();it++){
        if(it==g.begin()){
            prev = (*it);
            continue;
        }
        ans+=((*it)-prev);
        gg[{(*it),prev}]=((*it)-prev);
        prev=(*it);
    }

    if(num_of_g==0){
        for(auto it=r.begin();it!=r.end();it++){
            if(it==r.begin()){
                prev = (*it);
                continue;
            }
            ans+=((*it)-prev);
            prev=(*it);
        }
        for(auto it=b.begin();it!=b.end();it++){
            if(it==b.begin()){
                prev = (*it);
                continue;
            }
            ans+=((*it)-prev);
            prev=(*it);
        }

    }
    else{
        multiset<ll>st1,st2;
        vector<ll>vec;
        for(auto it=g.begin();it!=g.end();it++){
            st1.insert((*it));
            st2.insert((*it));
        }
        for(auto it=r.begin();it!=r.end();it++){
            st1.insert((*it));
        }
        for(auto it=b.begin();it!=b.end();it++){
            st2.insert((*it));
        }
        bool bl=true;
        ll tempans=0;

        for(auto it=st1.begin();it!=st1.end();it++){
            if(mp[(*it)]=='G' && bl==true){
                bl=false;
                if(vec.size()!=0)ans+=(*it)-vec[0];

                prev=(*it);
                vec.clear();
                vec.pb((*it));

                continue;
            }
            if(bl==false && mp[(*it)]=='G'){
                vec.pb((*it));
                //cout<<"ok";
                if(vec.size()==2){

                    prev=(*it);
                    vec.clear();
                    vec.pb((*it));
                    continue;
                }

                ll mx =-1;

                ll sum=0;
                for(int i=0;i<vec.size()-1;i++){
                    mx=max(mx,vec[i+1]-vec[i]);
                    sum+=vec[i+1]-vec[i];
                }

                ans+=sum-mx;
                ggr[{(*it),vec[0]}]=sum-mx;
                vec.clear();
                vec.pb((*it));
                prev=(*it);
            }
            else{
                vec.pb((*it));
                it++;
                if(it==st1.end()){
                    it--;
                    ans+=(*it)-prev;
                    break;
                }
                it--;
            }
        }
        //cout<<ans<<endl;
        vec.clear();
        bl=true;
        for(auto it=st2.begin();it!=st2.end();it++){
            if(mp[(*it)]=='G' && bl==true){
                bl=false;
                if(vec.size()!=0)ans+=(*it)-vec[0];

                prev=(*it);
                vec.clear();
                vec.pb((*it));

                continue;
            }
            if(bl==false && mp[(*it)]=='G'){
                vec.pb((*it));
                //cout<<"ok";
                if(vec.size()==2){

                    prev=(*it);
                    vec.clear();
                    vec.pb((*it));
                    continue;
                }

                ll mx =-1;

                ll sum =0;
                for(int i=0;i<vec.size()-1;i++){
                    mx=max(mx,vec[i+1]-vec[i]);
                    sum+=vec[i+1]-vec[i];
                }

                ans+=sum-mx;
                ggb[{(*it),vec[0]}]=sum-mx;
                if(ggr[{(*it),vec[0]}]!=0){
                    if((gg[{(*it),vec[0]}])<(ggr[{(*it),vec[0]}]+ggb[{(*it),vec[0]}])){
                        ans-=(ggr[{(*it),vec[0]}]+ggb[{(*it),vec[0]}]);
                        ans+=gg[{(*it),vec[0]}];
                    }
                }
                vec.clear();
                vec.pb((*it));
                prev=(*it);
            }
            else{
                vec.pb((*it));
                it++;
                if(it==st2.end()){
                    it--;
                    ans+=(*it)-prev;
                    break;
                }
                it--;
            }
        }
    }
    cout<<ans;
}
