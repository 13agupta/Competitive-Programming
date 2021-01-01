#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int MOD = int64_t(1e9) + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int64_t> arr(n),cnt(60,0);
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            for(int j=0; j<60; j++)
                cnt[j]+=(arr[i]>>j)&1;
        }
        vector<int64_t> orz(n,0);
        for(int i=0; i<n; i++) {
            int64_t cur = 1;
            for(int j=0; j<60; j++) {
                int64_t bit = (arr[i]>>j)&1;
                orz[i] += ((bit ? n : cnt[j]) * cur) %MOD;
                orz[i] %= MOD;
                cur = (cur<<1) % MOD;
            }
        }
        int64_t res = 0;
        for(int i=0; i<n; i++) {
            int64_t cur = 1;
            for(int j=0; j<60; j++) {
                if((arr[i]>>j)&1) {
                    res += (((cnt[j] * cur) % MOD) * orz[i]) % MOD;
                    res %= MOD;
                }
                cur = (cur<<1) % MOD;
            }
        }
        cout << res << "\n";
    }

    return 0;
}
