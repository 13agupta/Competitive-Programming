#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
vector<int64_t> arr;
int n,k;

bool check(int64_t add) {
    int64_t cur = arr[0] + add;
    for(int i=1; i<n; i++) {
        if(k*cur < arr[i]*100)
            return false;
        cur += arr[i];
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n >> k;
        arr.assign(n,0);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        int64_t l=0,r=1e14;
        int64_t res = 0;
        while(l <= r) {
            int64_t mid = l + (r-l)/2;
            if(check(mid)) {
                res = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }
        cout << res << "\n";
    }

    return 0;
}
