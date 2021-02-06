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
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        int cnt = 0;
        while(true) {
            cnt++;
            int res = -1;
            for(int i=0; i<n; i++) {
                if(i == n-1) {
                    cout << "-1\n";
                    goto done;
                }
                if(arr[i] < arr[i+1]) {
                    res = i;
                    arr[i]++;
                    break;
                }
            }
            if(cnt == k) {
                cout << res + 1 << "\n";
                goto done;
            }
        }
        done:;
    }

    return 0;
}
