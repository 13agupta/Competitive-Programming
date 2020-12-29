#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int n,k;
const int mxN=1e5+5;
vector<pair<int,int>> adj[mxN];
int dp[mxN][2];

void dfs(int u,int p,int cost) {
    dp[u][true]+=cost;
    dp[u][false]+=cost;
    vector<tuple<int,int,int>> children;
    for(auto &pvc : adj[u]) {
        int v=pvc.first,c=pvc.second;
        if(v==p) continue;
        dfs(v,u,c);
        children.emplace_back(dp[v][false],dp[v][true],v);
    }
    sort(children.begin(),children.end(),[](tuple<int,int,int> &a,tuple<int,int,int> &b) {
            if(get<1>(a)==get<1>(b)) 
                return get<0>(a)>get<0>(b);
            return get<1>(a)>get<1>(b);
        });
    int S=0;
    for(int i=0; i<min(sz(children),k-1); i++) {
        dp[u][true]+=get<1>(children[i]);
        S+=get<1>(children[i]);
    }
    for(int i=0; i<sz(children); i++) {
        int cur=get<2>(children[i]);
        if(i>=k-1)
            dp[u][false]=max(dp[u][false],cost+S+dp[cur][false]);
        else {
            int add=0;
            if(sz(children)>=k)
                add=get<1>(children[k-1]);
            dp[u][false]=max(dp[u][false],cost+S-dp[cur][true]+dp[cur][false]+add);
        }
    }
}    

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i=0; i<n-1; i++) {
        int u,v,c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }
    dfs(0,0,0);
    cout << dp[0][false];

    return 0;
}
