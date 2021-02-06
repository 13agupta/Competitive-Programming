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
        vector<int> a(n),b(n),c(m);
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<n; i++)
            cin >> b[i];
        for(int i=0; i<m; i++)
            cin >> c[i];
        set<int> colored;
        map<int,vector<int>> needs;
        map<int,vector<int>> good;
        vector<int> res(m);
        for(int i=1; i<=n; i++)
            needs[i] = good[i] = {};
        for(int i=n-1; ~i; i--) {
            if(a[i] != b[i])
                needs[b[i]].push_back(i);
            else
                good[b[i]].push_back(i);
        }
        for(int i=m-1; ~i; i--) {
            int cur = c[i];
            if(!needs[cur].empty()) {
                int index = needs[cur].back();
                a[index] = cur;
                needs[cur].pop_back();
                colored.insert(index);
                res[i] = index;
            }
            else if(!good[cur].empty()) {
                res[i] = good[cur].back();
                colored.insert(good[cur].back());
                good[cur].pop_back();
            }
            else if(!colored.empty()) {
                res[i] = *colored.begin();
            }
            else {
                cout << "NO\n";
                goto end;
            }
        }
        for(int i=0; i<n; i++) {
            if(a[i] != b[i]) {
                cout << "NO\n";
                goto end;
            }
        }
        cout << "YES\n";
        for(auto e : res)
            cout << e + 1 << " ";
        cout << "\n";
        end:;
    }

    return 0;
}
