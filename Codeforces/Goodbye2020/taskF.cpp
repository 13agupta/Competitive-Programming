#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int64_t MOD = int64_t(1e9) + 7;
const int mxN=int(5e5) + 1;
int n,m;
struct DSU {
    int parent[mxN],size[mxN];
} dsu;

void build() {
    for(int i=0; i<=m; i++) {
        dsu.parent[i] = i;
        dsu.size[i] = 1;
    }
}

int find_set(int u) {
    if(dsu.parent[u]==u)
        return u;
    return dsu.parent[u]=find_set(dsu.parent[u]);
}

void merge_sets(int u,int v) {
    u = find_set(u);
    v = find_set(v);
    if(u==v) return;
    if(dsu.size[u]<dsu.size[v])
        swap(u,v);
    dsu.parent[u] = v;
    dsu.size[v] += dsu.size[u];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    build();
    vector<int> res;
    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        if(k==2) {
            int u,v;
            cin >> u >> v;
            u--; v--;
            if(find_set(u)!=find_set(v)) {
                merge_sets(u,v);
                res.push_back(i);
            }
        }
        else {
            int u;
            cin >> u;
            u--;
            if(find_set(u)!=find_set(m)) {
                merge_sets(u,m);
                res.push_back(i);
            }
        }
    }
    int szRes = sz(res);
    int64_t ans = 1;
    while(szRes--)
        ans = (ans<<1) % MOD;
    cout << ans << " " << sz(res) << "\n";
    for(int i=0; i<sz(res); i++)
        cout << res[i]+1 << " ";
    cout << "\n";

    return 0;
}
