#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    set<int> se;
    for(int i=0; i<n; i++) {
        int e;
        cin >> e;
        se.insert(e);
    }
    if(se.find(0) != se.end())
        se.erase(0);
    cout << sz(se) << "\n";

    return 0;
}
