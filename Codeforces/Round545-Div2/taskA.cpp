#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    vector<vector<int>> cnt(2,vector<int>(n,0));
    int prev = arr[n-1];
    int cur = 0;
    for(int i=n-1; ~i; i--) {
        if(prev == arr[i]) {
            cur++;
            cnt[arr[i] - 1][i] = cur;
        }
        else {
            cur = 1;
            cnt[arr[i] -1][i] = cur;
        }
        prev = arr[i];
    }
    int best = 0;
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<2; j++) {
            if(cnt[j][i] <= cnt[1-j][i + cnt[j][i]])
                best = max(best,cnt[j][i] * 2);
        }
    }
    cout << best << "\n";

    return 0;
}
