#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int mxN=2e5+5;
vector<int> adj[mxN];
int n,k;
ll tot_subtree[mxN],count_subtree[mxN][5];
ll res;

int sub(int a,int b) {
    return ((a-b)%k + k)%k;
}

void dfs(int u,int p,int depth) {
    count_subtree[u][depth%k]=tot_subtree[u]=1;
    for(auto v : adj[u]) {
        if(v==p) continue;
        dfs(v,u,depth+1);
        for(int i=0; i<k; i++) {
            for(int j=0; j<k; j++) {
                int dist=sub(i+j,2*depth);
                int need=sub(k,dist);
                res+=need*count_subtree[u][i]*count_subtree[v][j];
            }
        }
        for(int i=0; i<k; i++)
            count_subtree[u][i]+=count_subtree[v][i];
        tot_subtree[u]+=tot_subtree[v];
    }
    res+=tot_subtree[u]*(n-tot_subtree[u]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i=0; i<n-1; i++) {
        int u,v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,0,0);
    assert(res%k==0);
    cout << res/k;

    return 0;
}
