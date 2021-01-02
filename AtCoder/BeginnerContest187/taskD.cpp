#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int,int>> arr(n);
    int64_t tot = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i].first >> arr[i].second;
        tot += arr[i].first;
    }
    sort(arr.begin(),arr.end(),[](pair<int,int> &f,pair<int,int> &s) {
            int64_t fval = 2LL*f.first + f.second;
            int64_t sval = 2LL*s.first + s.second;
            return fval>sval;
            });
    int res = 0;
    while(tot>=0) {
        tot -= 2LL*arr[res].first + arr[res].second;
        res++;
    }
    cout << res << "\n";

    return 0;
}
