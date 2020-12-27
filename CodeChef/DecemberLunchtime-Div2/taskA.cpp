#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n,k;
        cin >> n >> k;
        int tot=0;
        for(int i=0; i<n; i++) {
            int e;
            cin >> e;
            tot+=e;
        }
        cout << (tot%k!=0 ? 1 : 0) << "\n";
    }

    return 0;
}
