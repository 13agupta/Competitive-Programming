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
        int n; int64_t k;
        cin >> n >> k;
        vector<int64_t> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        arr.erase(unique(arr.begin(),arr.end()),arr.end());
        int64_t gcd = 0;
        for(int i=1; i<n; i++)
            gcd = __gcd(gcd,arr[i]-arr[i-1]);
        for(int i=0; i<n; i++) {
            int64_t diff = arr[i] - k;
            if(diff % gcd == 0) {
                cout << "YES\n";
                goto end;
            }
        }
        cout << "NO\n";
        end:;
    }

    return 0;
}
