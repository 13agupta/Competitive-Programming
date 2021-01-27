#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int mxN = int(1e5) + 5;
int vis[mxN][2],preorder[mxN][2],lowlink[mxN];
pair<int,int> bp[mxN][2];
vector<int> leaves;
int n,m,timer;
vector<int> adj[mxN];
const int INF = int(1e9);

void dfs(int u,int d,int p) {
    if(vis[u][d]) return;
    vis[u][d] = 1;
    if(!preorder[u][0])
        preorder[u][0] = preorder[u][1] = lowlink[u] = ++timer;
    bp[u][d] = {p,1-d};
    for(auto v : adj[u]) {
        if(!vis[v][1 - d] && !vis[v][d]) {
            dfs(v,1 - d,u);
            lowlink[u] = min(lowlink[u],lowlink[v]);
        }
        else {
            dfs(v,1 - d,u);
            lowlink[u] = min(lowlink[u],preorder[v][1]);
        }
    }
    preorder[u][1] = INF;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        int c;
        cin >> c;
        for(int j=0; j<c; j++) {
            int v;
            cin >> v;
            v--;
            adj[i].push_back(v);
        }
        if(c == 0)
            leaves.push_back(i);
    }
    int start;
    cin >> start;
    start--;
    dfs(start,0,-1);
    for(auto leaf : leaves) {
        if(vis[leaf][1]) {
            cout << "Win\n";
            vector<int> path;
            path.push_back(leaf);
            pair<int,int> cur = bp[leaf][1];
            while(cur.first != -1) {
                path.push_back(cur.first);
                cur = bp[cur.first][cur.second];
            }
            reverse(path.begin(),path.end());
            for(auto node : path)
                cout << node + 1 << " ";
            cout << "\n";
            goto end;
        }
    }
    for(int i=0; i<n; i++) {
        if(lowlink[i] < preorder[i][0]) {
            cout << "Draw\n";
            goto end;
        }
    }
    cout << "Lose\n";
    end:;

    return 0;
}
