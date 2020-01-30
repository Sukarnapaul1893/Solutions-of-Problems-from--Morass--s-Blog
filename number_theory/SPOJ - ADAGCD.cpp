#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

int lp[10000001];
int total[10000001];
int C[10000001];
vector<int>prime;

void FindLowestPrimeFactor(){
    for(int i=2;i<=10000001;i++){
        if(lp[i]==0){
            lp[i]=i;
            prime.pb(i);
        }
        for(int j=0;j<prime.size();j++){
            if(lp[i]<prime[j])break;
            if(i*prime[j]>10000000)break;

            lp[i*prime[j]]=prime[j];
        }
    }
}

ll binpow(int a, int b){
    if(b==0)return 1LL;
    if(b&1)return (binpow(a,b-1)*a)%1000000007;
    ll mid = binpow(a,b/2);
    return (mid*mid)%1000000007;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    FindLowestPrimeFactor();
    int n;
    cin>>n;
    for(int i=0;i<10000001;i++)total[i]=1000000007;

    for(int i=0;i<n;i++){

        int m;
        cin>>m;
        set<int>st;
        map<int,int>cnt;
        for(int j=0;j<m;j++){
            int a;
            cin>>a;

            while(a>1){
                int d = lp[a];
                st.insert(d);
                while(a%d==0){
                    a/=d;
                    cnt[d]++;
                }
            }

        }
        for(auto it=st.begin();it!=st.end();it++){

            int cur = (*it);
            C[cur]++;
            total[cur] = min(total[cur],cnt[cur]);
        }
        st.clear();
        cnt.clear();
    }
    ll ans = 1;
    for(int i=2;i<10000001;i++){
        if(C[i]!=n)continue;
        ans *= binpow(i,total[i]);
        ans%=1000000007;
    }
    cout<<ans<<"\n";
}
