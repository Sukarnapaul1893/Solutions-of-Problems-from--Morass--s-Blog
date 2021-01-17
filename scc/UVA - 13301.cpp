#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n,m;
vector<int>adj[100005];
vector<int>adjb[100005];    //back-edge adjacency list

int vis[100005];
int visb[100005];           //for back-edge

void input();

//Disjoint Set Union
int p[100005]; //initially p[i] = i;
int Find(int x)
{
    if(p[x] == x) return x;
    return p[x] = Find(p[x]);
}
void Union(int a, int b)
{
    p[Find(b)] = Find(a); // Making the parent of a and b same
}

vector<pair<int,int> >q;

void PrepareAdjacencyList(){
    for(int i=0;i<q.size();i++){
        int u = q[i].first;
        int v = q[i].second;
        int pu = Find(u);
        int pv = Find(v);
        if(pu!=pv){
            adj[pu].pb(pv);
            adjb[pv].pb(pu);
        }
    }
}

void initializer(){
    for(int i=0;i<=n;i++)p[i] = i;
}

vector<int>topsort;

// Simply finds the topological sort of a graph
void TopsortDfs(int v){
    vis[v]++;

    for(int i=0;i<adj[v].size();i++){
        int u = adj[v][i];
        if(vis[u]==0)TopsortDfs(u);
    }

    topsort.pb(v);
}

// DFS fucntion of the reverse-edge graph
void BackEdgeDfs(int v){
    visb[v]++;

    for(int i=0;i<adjb[v].size();i++){
        int u = adjb[v][i];
        if(visb[u]==0)BackEdgeDfs(u);
    }
}

int scc;      // The number of strongly connected components

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
    PrepareAdjacencyList();
    for(int i=1;i<=n;i++){
        if(vis[i]==0 and Find(i)==i)TopsortDfs(i);
    }

    reverse(topsort.begin(),topsort.end());
    CountScc();

    if(scc==1)cout<<"YES"<<"\n";
    else      cout<<"NO"<<"\n";
}



void Clear(){
    for(int i=0;i<=n;i++){
        adj[i].clear();
        adjb[i].clear();
        vis[i]=0;
        visb[i]=0;
        p[i] = i;
    }
    topsort.clear();
    scc = 0;
    q.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    while(cin>>n>>m){
        input();
        solve();
        Clear();
    }
}

void input(){
    initializer();

    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        if(k==1){
            int u,v;
            cin>>u>>v;
            q.pb({u,v});
        }
        else{
            int f ;
            for(int j=0;j<k;j++){
                int x;
                cin>>x;
                if(j==0){
                    f = x;  continue;
                }
                Union(x,f);
            }
        }
    }
}
