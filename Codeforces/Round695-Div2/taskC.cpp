#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int INF = int(1e9) + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> n(3);
    for(int i=0; i<3; i++)
        cin >> n[i];
    vector<int> mns(3,INF);
    vector<int64_t> sums(3,0);
    int64_t tot = 0;
    for(int j=0; j<3; j++) {
        for(int i=0; i<n[j]; i++) {
            int e;
            cin >> e;
            tot += e;
            mns[j] = min(mns[j],e);
            sums[j] += e;
        }
    }
    sort(sums.begin(),sums.end());
    sort(mns.begin(),mns.end());
    cout << max(tot-2LL*(mns[0]+mns[1]),tot-2LL*sums[0]) << "\n";

    return 0;
}
