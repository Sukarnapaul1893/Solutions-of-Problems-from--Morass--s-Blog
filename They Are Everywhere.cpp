#include<bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    string s;
    cin>>s;
    int ans[n];
    memset(ans,0,sizeof ans);
    int start=0;
    set<char>st,st2;
    for(int i=0;i<n;i++){
        st.insert(s[i]);
    }
    int total = st.size();
    map<char,int>mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
        st2.insert(s[i]);
        if(st2.size()==total){

            for(int j=start;j<=i;j++){
                if(mp[s[j]]-1==0){
                    start=j;
                    break;
                }
                mp[s[j]]--;

            }

            ans[i]=i-start+1;
        }


    }
    int mx=10000000;
    for(int i=0;i<n;i++){
        //cout<<ans[i]<<endl;
        if(ans[i]==0)continue;
        mx = min(ans[i],mx);
    }
    cout<<mx;
}
