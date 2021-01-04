#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int mxN = int(2e5) + 5;
const int INF = int(1e8);
vector<int> adj[mxN],aadj[mxN<<1];
int dist[mxN],adist[mxN<<1];
int vis[mxN],avis[mxN<<1];
int n,m;

void bfs1(int u) {
    deque<int> q;
    q.push_back(u);
    dist[u] = 0;
    vis[u] = 1;
    int curdist = 0;
    while(!q.empty()) {
        deque<int> tq;
        curdist++;
        for(int i=0; i<sz(q); i++) {
            for(auto &v : adj[q[i]]) {
                if(vis[v]) continue;
                tq.push_back(v);
                vis[v] = 1;
                dist[v] = curdist;
            }
        }
        q = tq;
    }
}

void dfs2(int u) {
    if(avis[u]) return;
    if(u>=n) {
        adist[u] = dist[u-n];
        return;
    }
    adist[u] = dist[u];
    avis[u] = 1;
    for(auto &v : aadj[u]) {
        dfs2(v);
        adist[u] = min(adist[u],adist[v]);
    }
}    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        for(int i=0; i<n; i++) {
            adj[i].clear();
            dist[i] = INF;
            vis[i] = 0;
        }
        vector<pair<int,int>> edges(m);
        for(int i=0; i<m; i++) {
            cin >> edges[i].first >> edges[i].second;
            edges[i].first--; edges[i].second--;
            adj[edges[i].first].push_back(edges[i].second);
        }
        dist[0] = -1;
        bfs1(0);
        for(int i=0; i<2*n; i++) {
            aadj[i].clear();
            adist[i] = INF;
            avis[i] = 0;
        }
        for(auto &edge : edges) {
            if(dist[edge.first]>=dist[edge.second])
                aadj[edge.first].push_back(edge.second+n);
            else
                aadj[edge.first].push_back(edge.second);
        }
        adist[0] = 0;
        dfs2(0);
        for(int i=0; i<n; i++)
            cout << adist[i] << " ";
        cout << "\n";
    }

    return 0;
}
