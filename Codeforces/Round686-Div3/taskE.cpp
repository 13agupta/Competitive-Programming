#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
vector<vector<int>> adj;
vector<int> trace,cycle,vis;

void dfs1(int u,int p=-1) {
    trace.push_back(u);
    vis[u]=2;
    for(auto v : adj[u]) {
        if(!vis[v])
            dfs1(v,u);
        else if(v!=p && vis[v]==2) {
            int x=sz(trace)-1;
            while(trace[x]!=v) x--;
            for(; x<sz(trace); x++)
                cycle[trace[x]]=1;
        }
    }
    vis[u]=1;
    trace.pop_back();
}

int dfs2(int u,int p=-1) {
    ll res=1;
    for(auto v : adj[u]) {
        if(v==p || cycle[v])
            continue;
        res+=dfs2(v,u);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vis.assign(n+1,0);
        trace.clear();
        cycle.assign(n+1,0);
        adj.assign(n+1,{});
        for(int i=0; i<n; i++) {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(1);
        ll tot=n*1LL*(n-1);
        for(int i=0; i<n; i++) {
            if(cycle[i]) {
                ll res=dfs2(i);
                tot-=res*1LL*(res-1)/2;
            }
        }
        cout << tot << "\n";
    }

    return 0;
}
