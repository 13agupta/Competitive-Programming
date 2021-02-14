#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n,q,k;
    cin >> n >> q >> k;
    deque<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    arr.push_front(0);
    arr.push_back(k+1);
    vector<int64_t> pref;
    vector<int64_t> bef,aft;
    pref.push_back(0);
    for(int i=1; i<n+1; i++) {
        int before = arr[i-1];
        int after = arr[i+1];
        int range = after - before + 1 - 3;
        pref.push_back(range);
        bef.push_back(before);
        aft.push_back(after);
    }
    for(int i=1; i<n+1; i++)
        pref[i] += pref[i-1];
    while(q--) {
        int l,r;
        cin >> l >> r;
        l--; r--;
        int64_t before = bef[l];
        int64_t after = aft[r];
        cout << pref[r+1] - pref[l] + before + k - after + 1 << "\n";
    }

    return 0;
}
