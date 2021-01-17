#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    multiset<int> se;
    for(int i=0; i<n; i++) {
        int e;
        cin >> e;
        se.insert(e);
    }
    int64_t res = 0;
    while(k--) {
        int cur = 0;
        while(!se.empty() && se.find(cur)!=se.end()) {
            se.erase(se.find(cur)); cur++;
        }
        res += cur;
    }
    cout << res << "\n";

    return 0;
}
