#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int mxN = int(3e5) + 5;
int n,m;
vector<int> adj[mxN];
int vis[mxN];
vector<int> order;

void dfs(int u) {
    if(vis[u]) return;
    order.push_back(u);
    vis[u] = 1;
    for(auto &v : adj[u])
        dfs(v);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        order.clear();
        for(int i=0; i<n; i++) {
            adj[i].clear();
            vis[i] = 0;
        }
        for(int i=0; i<m; i++) {
            int u,v;
            cin >> u >> v;
            u--; v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0);
        set<int> res;
        for(int i=0; i<n; i++) {
            if(!vis[i]) {
                cout << "NO\n";
                goto end;
            }
        }
        for(auto &e : order) {
            res.insert(e);
            for(auto &v : adj[e]) {
                if(res.find(v)!=res.end()) {
                    res.erase(e);
                    break;
                }
            }
        }
        cout << "YES\n";
        cout << sz(res) << "\n";
        for(auto &val : res)
            cout << val+1 << " ";
        cout << "\n";
        end:;
    }

    return 0;
}
