#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
int n,m;
const int mxN = int(1e5) + 5;
vector<int> adj[mxN];
int p[mxN],ind[mxN],tot[mxN],s[mxN],h[mxN];

void dfs1(int u,int par) {
    tot[u] = p[u];
    for(auto &v : adj[u]) {
        if(v == par) continue;
        dfs1(v,u);
        tot[u] += tot[v];
    }
}

bool dfs2(int u,int p) {
    if((tot[u] - ind[u]) < 0 || (tot[u] - ind[u]) % 2)
        return false;
    s[u] = (tot[u] - ind[u]) / 2;
    h[u] = tot[u] - s[u];
    for(auto &v : adj[u]) {
        if(v == p) continue;
        bool res = dfs2(v,u);
        if(!res) return false;
    }
    int hs[2]; hs[0] = hs[1] = 0;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        hs[0] += h[v];
        hs[1] += s[v];
    }
    if(hs[0] > h[u]) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        for(int i=0; i<n; i++)
            cin >> p[i];
        for(int i=0; i<n; i++)
            cin >> ind[i];
        for(int i=0; i<n; i++) {
            tot[i] = 0;
            adj[i].clear();
        }
        for(int i=0; i<n-1; i++) {
            int u,v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs1(0,0);
        cout << (dfs2(0,0) ? "YES" : "NO") << "\n";
    }

    return 0;
}
