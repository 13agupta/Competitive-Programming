#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int n,m;
const int mxN = int(2e5) + 5;
vector<pair<int,int64_t>> adj[mxN<<3];
int64_t dist[mxN<<3];
int vis[mxN<<3];
const int64_t INF = int64_t(1e17) + 5;

void dijkstra(int u) {
    priority_queue<pair<int64_t,int>,vector<pair<int64_t,int>>,greater<pair<int64_t,int>>> pq;
    pq.push({0,u});
    dist[u] = 0;
    while(!pq.empty()) {
        pair<int64_t,int> cur = pq.top(); pq.pop();
        if(cur.first > dist[cur.second]) continue;
        for(auto &pv : adj[cur.second]) {
            if(dist[pv.first] > dist[cur.second] + pv.second) {
                dist[pv.first] = dist[cur.second] + pv.second;
                pq.emplace(dist[pv.first],pv.first);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<8*n; i++)
        dist[i] = INF;
    for(int i=0; i<m; i++) {
        int u,v;
        int64_t w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].emplace_back(v,w);
        adj[v].emplace_back(u,w);
        adj[u].emplace_back(n + v,0);
        adj[v].emplace_back(n + u,0);
        adj[u].emplace_back(3*n + v,2*w);
        adj[v].emplace_back(3*n + u,2*w);
        adj[3*n + u].emplace_back(4*n + v,0);
        adj[3*n + v].emplace_back(4*n + u,0);
        adj[n + u].emplace_back(2*n + v,2*w);
        adj[n + v].emplace_back(2*n + u,2*w);
        adj[n + u].emplace_back(n + v,w);
        adj[n + v].emplace_back(n + u,w);
        adj[2*n + u].emplace_back(2*n + v,w);
        adj[2*n + v].emplace_back(2*n + u,w);
        adj[3*n + u].emplace_back(3*n + v,w);
        adj[3*n + v].emplace_back(3*n + u,w);
        adj[4*n + u].emplace_back(4*n + v,w);
        adj[4*n + v].emplace_back(4*n + u,w);
    }
    dijkstra(0);
    for(int i=1; i<n; i++)
        cout << min({dist[i],dist[2*n+i],dist[4*n+i]}) << " ";
    cout << "\n";

    return 0;
}
