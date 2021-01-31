#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int mxN = int(1e6) + 5;
vector<int> adj[mxN];
int vis[mxN],edges[mxN],deg[mxN];
int n,m,same;

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for(auto &v : adj[u])
        dfs(v);
}

int64_t choose2(int64_t c) {
    return (c * (c-1)) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
        if(u != v) {
            edges[u]++;
            edges[v]++;
        }
        else
            same++;
    }
    for(int i=0; i<n; i++) {
        if(deg[i] > 0) {
            dfs(i);
            break;
        }
    }
    for(int i=0; i<n; i++) {
        if(!vis[i] && deg[i] > 0) {
            cout << "0\n";
            return 0;
        }
    }
    int64_t res = 0;
    for(int i=0; i<n; i++)
        res += choose2(edges[i]);
    int start = m-1;
    while(same--) {
        res += start;
        start--;
    }
    cout << res << "\n";

    return 0;
}
