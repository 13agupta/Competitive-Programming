#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int64_t INF = int64_t(1e14);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int64_t> arr(n-1);
    int64_t prev; cin >> prev;
    for(int i=0; i<n-1; i++) {
        int64_t cur; cin >> cur;
        arr[i] = abs(cur - prev);
        prev = cur;
    }
    for(int i=0; i<n-1; i++)
        if(i % 2) arr[i] *= -1;
    vector<int64_t> pref(n);
    pref[0] = 0;
    for(int i=1; i<n; i++)
        pref[i] = pref[i-1] + arr[i-1];
    int64_t best = -INF;
    multiset<int64_t,greater<int64_t>> ms;
    for(int i=0; i<n; i++)
        ms.insert(pref[i]);
    for(int i=0; i<n; i++) {
        ms.erase(ms.find(pref[i]));
        if(!ms.empty()) {
            int64_t mx = *ms.begin();
            best = max(best,mx - pref[i]);
        }
    }
    for(int i=0; i<n-1; i++)
        arr[i] *= -1;
    for(int i=1; i<n; i++)
        pref[i] = pref[i-1] + arr[i-1];
    ms.clear();
    for(int i=0; i<n; i++)
        ms.insert(pref[i]);
    for(int i=0; i<n; i++) {
        ms.erase(ms.find(pref[i]));
        if(!ms.empty()) {
            int64_t mx = *ms.begin();
            best = max(best,mx - pref[i]);
        }
    }
    cout << best << "\n";

    return 0;
}
