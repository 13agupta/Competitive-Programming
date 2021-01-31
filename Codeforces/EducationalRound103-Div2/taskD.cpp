#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int mxN = int(3e5) + 5;
vector<int> adj[mxN],radj[mxN];
int vis[mxN][2],cnt[mxN][2];
int n;
string s;
int counter;

void dfs(int u,int par) {
    if(vis[u][par]) return;
    vis[u][par] = counter;
    cnt[u][par] = 1;
    if(par == 0) {
        for(auto v : adj[u]) {
            if(!vis[v][1-par]) {
                dfs(v,1-par);
                cnt[u][par] += cnt[v][1-par];
            }
        }
    }
    else {
        for(auto v : radj[u]) {
            if(!vis[v][1-par]) {
                dfs(v,1-par);
                cnt[u][par] += cnt[v][1-par];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n;
        counter = 1;
        for(int i=0; i<n+1; i++) {
            adj[i].clear();
            radj[i].clear();
            vis[i][0] = vis[i][1] = 0;
            cnt[i][0] = cnt[i][1] = 0;
        }
        cin >> s;
        for(int i=0; i<n; i++) {
            if(s[i] == 'L') {
                adj[i+1].push_back(i);
                radj[i].push_back(i+1);
            }
            else {
                adj[i].push_back(i+1);
                radj[i+1].push_back(i);
            }
        }
        for(int i=0; i<n+1; i++) {
            if(!vis[i][0]) {
                dfs(i,0);
                counter++;
            }
        }
        vector<int> best(n + 5,0);
        /* cout << "counts:\n";
        for(int j=0; j<2; j++) {
            for(int i=0; i<n+1; i++)
                cout << cnt[i][j] << " ";
            cout << endl;
        }
        cout << endl;
        cout << "vis:\n";
        for(int j=0; j<2; j++) {
            for(int i=0; i<n+1; i++)
                cout << vis[i][j] << " ";
            cout << endl;
        }
        cout << endl; */
        for(int i=0; i<n+1; i++) {
            for(int j=0; j<2; j++) {
                int count = vis[i][j];
                best[count] = max(best[count],cnt[i][j]);
            }
        }
        for(int i=0; i<n+1; i++)
            cout << best[vis[i][0]] << " ";
        cout << "\n";
    }

    return 0;
}
