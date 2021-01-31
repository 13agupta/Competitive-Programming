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
        int n;
        cin >> n;
        vector<int64_t> a(n),b(n),c(n);
        for(int i=0; i<n; i++)
            cin >> c[i];
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<n; i++) {
            cin >> b[i];
            if(b[i] < a[i])
                swap(a[i],b[i]);
        }
        int64_t best = 0;
        int i = 1;
        int64_t tot = b[i] - a[i] + 1;
        while(i < n) {
            best = max(best,tot + c[i]);
            if(i < n-1 && a[i+1] == b[i+1])
                tot = 1;
            else if(i < n-1)
                tot += a[i+1] + c[i] - b[i+1] + 1;
            if(i < n-1)
                tot = max(tot,b[i+1] - a[i+1] + 1);
            i++;
        }
        // tot += c[n-1];
        best = max(best,tot);
        cout << best << "\n";
    }

    return 0;
}
