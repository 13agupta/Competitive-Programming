#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int n;
const int mxN = int(2e5) + 5;
vector<int> adj[mxN];
int64_t value[mxN];
int depth[mxN];

void dfs1(int u,int p) {
    depth[u] = depth[p] + 1;
    for(auto &v : adj[u]) {
        if(v==p) continue;
        dfs1(v,u);
    }
}

void dfs2(int u,int p,int64_t pval) {
    value[u] += pval;
    for(auto &v : adj[u]) {
        if(v==p) continue;
        dfs2(v,u,value[u]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<pair<int,int>> edges(n-1);
    for(int i=0; i<n-1; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--; edges[i].second--;
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
    depth[0] = -1;
    dfs1(0,0);
    int tt;
    cin >> tt;
    while(tt--) {
        int t,e,x;
        cin >> t >> e >> x;
        pair<int,int> edge = edges[e-1];
        if(t==2) swap(edge.first,edge.second);
        if(depth[edge.first]>depth[edge.second])
            value[edge.first] += x;
        else {
            value[0] += x;
            value[edge.second] -= x;
        }
    }
    dfs2(0,0,0);
    for(int i=0; i<n; i++)
        cout << value[i] << "\n";

    return 0;
}
