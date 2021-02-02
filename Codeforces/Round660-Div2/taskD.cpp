#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int mxN = int(2e5) + 5;
vector<int> adj[mxN];
int64_t arr[mxN],vis[mxN];
vector<int> order;
int n;

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for(auto &v : adj[u])
        dfs(v);
    order.push_back(u);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    for(int i=0; i<n; i++) {
        int e; cin >> e;
        if(e != -1)
            adj[i].push_back(e - 1);
    }
    for(int i=0; i<n; i++) {
        if(!vis[i]) dfs(i);
    }
    reverse(order.begin(),order.end());
    vector<int> res[2];
    for(auto &u : order) {
        if(arr[u] < 0) {
            res[1].push_back(u);
            continue;
        }
        if(!adj[u].empty()) {
            int v = adj[u][0];
            arr[v] += arr[u];
        }
        res[0].push_back(u);
    }
    reverse(res[1].begin(),res[1].end());
    int64_t tot = 0;
    for(auto u : res[0])
        tot += arr[u];
    for(auto u : res[1])
        tot += arr[u];
    cout << tot << "\n";
    for(auto u : res[0])
        cout << u+1 << " ";
    for(auto u : res[1])
        cout << u+1 << " ";
    cout << "\n";

    return 0;
}
