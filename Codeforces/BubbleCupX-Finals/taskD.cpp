#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int v,e,n,k;
const int mxV=605;
const int INF=1e9;
const int mxAns=1731311;
int dist[mxV][mxV];
int start[mxV];

void floyd_warshall() {
    for(int lvl=0; lvl<v; lvl++) {
        for(int i=0; i<v; i++) {
            for(int j=0; j<v; j++)
                dist[i][j]=min(dist[i][j],dist[i][lvl]+dist[lvl][j]);
        }
    }
}

int bfs(int s, int t, int n,vector<int>& parent,vector<vector<int>> &capacity,vector<vector<int>> &adj) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                    return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t,int n,vector<vector<int>> &capacity,vector<vector<int>> &adj) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while ((new_flow = bfs(s, t, n,parent,capacity,adj))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

bool chk(int bnd) {
    set<int> lhs;
    for(int i=0; i<v; i++)
        if(start[i]) lhs.insert(i);
    map<int,int> comp;
    int cur=v;
    for(auto &node : lhs)
        comp[node]=cur++;
    vector<vector<int>> capacity(mxV<<1,vector<int>(mxV<<1,0)),adj(mxV<<1,vector<int>());
    for(auto &node : lhs) {
        for(int j=0; j<v; j++) {
            if(dist[node][j]<=bnd) {
                capacity[comp[node]][j]=1;
                adj[comp[node]].push_back(j);
                adj[j].push_back(comp[node]);
            }
        }
    }
    int s=v+sz(lhs),t=v+sz(lhs)+1;
    for(auto &node : lhs) {
        capacity[s][comp[node]]=start[node];
        adj[s].push_back(comp[node]);
        adj[comp[node]].push_back(s);
    }
    for(int i=0; i<v; i++) {
        capacity[i][t]=1;
        adj[i].push_back(t);
        adj[t].push_back(i);
    }
    int n=sz(lhs)+2+v;
    int flow=maxflow(s,t,n,capacity,adj);
    return (flow>=k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> v >> e >> n >> k;
    for(int i=0; i<n; i++) {
        int val;
        cin >> val;
        val--;
        start[val]++;
    }
    for(int i=0; i<v; i++) {
        for(int j=0; j<v; j++)
            dist[i][j]=(i==j ? 0 : INF);
    }
    for(int i=0; i<e; i++) {
        int a,b,t;
        cin >> a >> b >> t;
        a--; b--;
        dist[a][b]=min(dist[a][b],t);
        dist[b][a]=min(dist[b][a],t);
    }
    floyd_warshall();
    int l=0,r=mxAns;
    int ans=-1;
    while(l<=r) {
        int mid=l+(r-l)/2;
        if(chk(mid)) {
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    cout << ans << "\n";

    return 0;
}
