#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(15);

    int tt;
    cin >> tt;
    while(tt--) {
        int n,m;
        cin >> n >> m;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        int cnt = 0;
        for(int i=n-1; ~i; i--) {
            if(arr[i] != i + 1) break;
            cnt++;
        }
        double res = 1;
        int need = n - cnt;
        vector<double> valid;
        if(cnt == n) {
            cout << "1\n";
            for(int i=0; i<m; i++) {
                int r; double p;
                cin >> r >> p;
            }
            goto end;
        }
        for(int i=0; i<m; i++) {
            int r; double p;
            cin >> r >> p;
            if(r < need) continue;
            valid.push_back(p);
        }
        for(auto p : valid)
            res *= 1 - p;
        cout << 1 - res << "\n";
        end:;
    }

    return 0;
}
