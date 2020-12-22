#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int mxN=2e5+5;
vector<int> adj[mxN];
int res,cur;
int vis[mxN];
bool isCycle;

void dfs(int u,int p) {
    if(vis[u]) {
        isCycle=true;
        return;
    }
    cur++;
    vis[u]=1;
    for(auto &v : adj[u]) {
        if(v==p) continue;
        dfs(v,u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n,m;
        cin >> n >> m;
        vector<pair<int,int>> arr(n);
        set<pair<int,int>> se;
        for(int i=0; i<m; i++) {
            cin >> arr[i].first >> arr[i].second;
            se.insert(arr[i]);
        }
        for(int i=1; i<=n; i++)
            se.insert({i,i});
        map<pair<int,int>,int> comp;
        int cnt=0;
        for(auto &p : se)
            comp.insert({p,cnt++});
        for(int i=0; i<2*n; i++) {
            adj[i].clear();
            vis[i]=0;
        }
        for(int i=0; i<m; i++) {
            int f=comp[arr[i]];
            int col=comp[{arr[i].first,arr[i].first}];
            int row=comp[{arr[i].second,arr[i].second}];
            adj[f].push_back(col);
            adj[col].push_back(f);
            adj[f].push_back(row);
            adj[row].push_back(f);
        }
        res=0;
        for(int i=0; i<2*n; i++) {
            isCycle=false;
            cur=0;
            if(!vis[i]) {
                dfs(i,i);
                res+=cur/2;
                res+=(isCycle ? 1 : 0);
            }
        }
        cout << res << "\n";
    }

    return 0;
}
