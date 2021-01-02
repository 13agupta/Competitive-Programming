#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int n,m;
const int mxN = int(3e5) + 5;
const int INF = 100;
int dp[mxN];
bool fcc[mxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<pair<int,int>> edges(m);
    for(int i=0; i<m; i++) {
        cin >> edges[i].first >> edges[i].second;
        edges[i].first--; edges[i].second--;
    }
    for(int msk=0; msk<(1<<n); msk++) {
        dp[msk] = INF;
        int cnt = 0;
        for(int i=0; i<m; i++) {
            int fval = (1<<edges[i].first);
            int sval = (1<<edges[i].second);
            if((fval&msk)>0 && (sval&msk)>0)
                cnt++;
        }
        int popcnt = __builtin_popcount(msk);
        if(cnt==(popcnt * (popcnt-1))/2)
            fcc[msk] = true;
    }
    dp[0] = 0;
    for(int msk=1; msk<(1<<n); msk++) {
        if(fcc[msk]) {
            dp[msk] = 1;
            continue;
        }
        for(int submsk=msk; submsk; submsk=(submsk-1)&msk)
            dp[msk] = min(dp[msk],dp[submsk]+dp[msk^submsk]);
    }
    cout << dp[(1<<n)-1] << "\n";

    return 0;
}
