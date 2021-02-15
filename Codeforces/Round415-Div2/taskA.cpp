#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
int n,k;
const int mxN = 105;
int arr[mxN];

bool check(int value) {
    int64_t tot = 0;
    for(int i=0; i<n; i++)
        tot += arr[i];
    tot += value * 1LL * k;
    int64_t high = (k * 1LL * (n + value));
    int64_t low = ((k - 1) * 1LL * (n + value));
    return (tot >= low && high - tot <= tot - low);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int l = 0, r = 100000;
    int ans = -1;
    while(l <=r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ans << "\n";

    return 0;
}
