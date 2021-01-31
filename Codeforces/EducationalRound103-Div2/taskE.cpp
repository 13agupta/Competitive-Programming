#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
int n,m,k;
const int mxN = int(1e5) + 5;
vector<int> adj[mxN];
vector<string> pattern,str;
vector<int> mt;
vector<int> order,vis;

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = 1;
    for(auto v : adj[u])
        dfs(v);
    order.push_back(u);
}

bool checkPattern(string s,string pat) {
    for(int i=0; i<k; i++) {
        if(s[i] != pat[i] && pat[i] != '_')
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    pattern.assign(n,"");
    str.assign(m,"");
    mt.assign(m,0);
    map<string,int> comp;
    map<int,int> position;
    vis.assign(n,0);
    for(int i=0; i<n; i++) {
        cin >> pattern[i];
        comp[pattern[i]] = i;
    }
    for(int i=0; i<m; i++) {
        cin >> str[i] >> mt[i];
        mt[i]--;
    }
    for(int cur=0; cur<m; cur++) {
        string s = str[cur];
        if(!checkPattern(s,pattern[mt[cur]])) {
            cout << "NO\n";
            goto end;
        }
        int firstIndex = mt[cur];
        for(int msk=0; msk<(1<<k); msk++) {
            string t(k,' ');
            for(int i=0; i<k; i++)
                t[i] = ((msk >> i & 1) ? s[i] : '_');
            if(t != pattern[firstIndex] && comp.find(t) != comp.end())
                adj[firstIndex].push_back(comp[t]);
        }
    }
    for(int i=0; i<n; i++)
        if(!vis[i]) dfs(i);
    reverse(order.begin(),order.end());
    for(int i=0; i<n; i++)
        position[order[i]] = i;
    for(int cur=0; cur<m; cur++) {
        string s = str[cur];
        int firstIndex = mt[cur];
        int mn = n+1;
        for(int msk=0; msk<(1<<k); msk++) {
            string t(k,' ');
            for(int i=0; i<k; i++)
                t[i] = ((msk >> i & 1) ? s[i] : '_');
            if(comp.find(t) != comp.end())
                mn = min(mn,position[comp[t]]);
        }
        if(mn < position[firstIndex]) {
            cout << "NO\n";
            goto end;
        }
    }
    cout << "YES\n";
    for(auto value : order)
        cout << value+1 << " ";
    cout << "\n";
    end:;

    return 0;
}
