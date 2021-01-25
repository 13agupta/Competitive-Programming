#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int INF = int(1e9) + 5;

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n,m;
        cin >> n >> m;
        vector<int64_t> arr[2];
        vector<int> v(n);
        for(int i=0; i<n; i++)
            cin >> v[i];
        for(int i=0; i<n; i++) {
            int e;
            cin >> e;
            arr[e - 1].push_back(v[i]);
        }
        sort(arr[0].begin(),arr[0].end(),greater<int64_t>());
        sort(arr[1].begin(),arr[1].end(),greater<int64_t>());
        for(int i=1; i<sz(arr[0]); i++)
            arr[0][i] += arr[0][i-1];
        for(int i=1; i<sz(arr[1]); i++)
            arr[1][i] += arr[1][i-1];
        int best = INF;
        int64_t rem = m;
        auto it = lower_bound(arr[1].begin(),arr[1].end(),rem);
        if(it != arr[1].end())
            best = min(best,int(distance(arr[1].begin(),it) + 1) * 2);
        for(int i=0; i<sz(arr[0]); i++) {
            rem = m - arr[0][i];
            if(rem <= 0) {
                best = min(best,i+1);
                continue;
            }
            it = lower_bound(arr[1].begin(),arr[1].end(),rem);
            if(it != arr[1].end())
                best = min(best,int(distance(arr[1].begin(),it) + 1) * 2 + (i + 1));
        }
        cout << (best == INF ? -1 : best) << "\n";
    }

    return 0;
}
