#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

int n,m;
vector<int>adj[2003];
vector<int>adjb[2003];

int vis[2003];
int visb[2003];

vector<int>topsort;

void TopsortDfs(int v){
    vis[v]++;

    for(int i=0;i<adj[v].size();i++){
        int u = adj[v][i];
        if(vis[u]==0)TopsortDfs(u);
    }

    topsort.pb(v);
}

void BackEdgeDfs(int v){
    visb[v]++;

    for(int i=0;i<adjb[v].size();i++){
        int u = adjb[v][i];
        if(visb[u]==0)BackEdgeDfs(u);
    }
}

int scc;

void CountScc(){
    for(int i=0;i<topsort.size();i++){
        int u = topsort[i];
        if(visb[u] == 0){
            BackEdgeDfs(u);     scc++;
        }
    }
}


void input();

void solve(){
    for(int i=1;i<=n;i++){
        if(vis[i]==0)TopsortDfs(i);
    }

    reverse(topsort.begin(),topsort.end());
    CountScc();

    if(scc==1)cout<<1<<"\n";
    else      cout<<0<<"\n";
}

void Clear(){
    scc=0;
    for(int i=0;i<=n;i++){
        adj[i].clear();
        adjb[i].clear();
        vis[i] = 0;
        visb[i] = 0;
    }
    topsort.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin>>n>>m){
        if(n==0 and m==0)exit(0);
        input();
        solve();
        Clear();
    }
}

void input(){
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        int p;
        cin>>p;

        if(p==1){
            adj[u].pb(v);
            adjb[v].pb(u);
        }
        else{
            adj[u].pb(v);
            adj[v].pb(u);

            adjb[u].pb(v);
            adjb[v].pb(u);
        }
    }
}
