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
    for(int i=0; i<n; i++)
        cin >> arr[i].first >> arr[i].second;
    int res = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            int dy = abs(arr[j].second-arr[i].second);
            int dx = abs(arr[j].first - arr[i].first);
            res += (dx>=dy ? 1 : 0);
        }
    }
    cout << res << "\n";

    return 0;
}
