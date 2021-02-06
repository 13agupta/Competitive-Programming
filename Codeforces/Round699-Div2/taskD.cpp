#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n,m;
        cin >> n >> m;
        vector<string> adj(n);
        for(int i=0; i<n; i++)
            cin >> adj[i];
        if(n == 2 && adj[0][1] != adj[1][0] && m % 2 == 0) {
            cout << "NO\n";
            continue;
        }
        if(n == 2 && adj[0][1] == adj[1][0]) {
            cout << "YES\n";
            m++;
            while(m--)
                cout << (m % 2) + 1 << " ";
            cout << "\n";
            continue;
        }
        if(m % 2 == 1) {
            cout << "YES\n";
            m++;
            while(m--)
                cout << (m % 2) + 1 << " ";
            cout << "\n";
            continue;
        }
        vector<int> arr = {0,1,2};
        do {
            if(adj[arr[0]][arr[1]] == adj[arr[1]][arr[2]])
                break;
        }
        while(next_permutation(arr.begin(),arr.end()));
        assert(adj[arr[0]][arr[1]] == adj[arr[1]][arr[2]]);
        cout << "YES\n";
        vector<pair<int,int>> edges;
        for(int i=m/2 - 2; ~i; i--)
            if(i % 2 == 0)
                edges.push_back({arr[2],arr[0]});
            else
                edges.push_back({arr[0],arr[2]});
        edges.push_back({arr[0],arr[1]});
        edges.push_back({arr[1],arr[2]});
        for(int i=0; i<m/2 - 1; i++)
            if(i % 2)
                edges.push_back({arr[0],arr[2]});
            else
                edges.push_back({arr[2],arr[0]});
        for(int i=0; i<m; i++) {
            if(i == m-1)
                cout << edges[i].first + 1 << " " << edges[i].second + 1 << "\n";
            else
                cout << edges[i].first + 1 << " ";
        }
    }

    return 0;
}
