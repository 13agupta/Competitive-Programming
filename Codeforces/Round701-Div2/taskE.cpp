#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int mxN = int(2e5) + 5;
int64_t depth[mxN],arr[mxN],parent[mxN];
vector<int> adj[mxN],levels[mxN];
int n;
int64_t dp[mxN];
const int64_t INF = int64_t(1e15);

void dfs(int u,int p) {
    parent[u] = p;
    depth[u] = depth[p] + 1;
    levels[depth[u]].push_back(u);
    for(auto &v : adj[u]) {
        if(v == p) continue;
        dfs(v,u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n;
        for(int i=0; i<n; i++) {
            dp[i] = 0;
            adj[i].clear();
            levels[i].clear();
        }
        for(int i=1; i<n; i++) {
            int v;
            cin >> v; v--;
            adj[i].push_back(v);
            adj[v].push_back(i);
        }
        for(int i=1; i<n; i++)
            cin >> arr[i];
        arr[0] = 0;
        depth[0] = -1;
        dfs(0,0);
        for(int i=1; sz(levels[i]); i++) {
            vector<int64_t> less,greater;
            int64_t mnE = INF;
            int64_t mxE = -INF;
            for(auto node : levels[i]) {
                mnE = min(mnE,arr[node]);
                mxE = max(mxE,arr[node]);
                less.push_back(dp[parent[node]] - arr[node]);
                greater.push_back(dp[parent[node]] + arr[node]);
            }
            int64_t mx = *max_element(greater.begin(),greater.end());
            int64_t mn = *max_element(less.begin(),less.end());
            for(auto node : levels[i])
                dp[node] = max({dp[node], mx - arr[node], mn + arr[node], dp[parent[node]] + arr[node] - mnE, dp[parent[node]] + mxE - arr[node]});
        }
        cout << *max_element(dp,dp + n) << "\n";
    }

    return 0;
}
