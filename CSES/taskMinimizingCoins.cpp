#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int mxX=1e6+6;
const int INF=2e9;
int dp[mxX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin >> n >> x;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    for(int i=1; i<=x; i++) {
        dp[i]=INF;
        for(auto &c : arr) {
            if(i-c<0) continue;
            dp[i]=min(dp[i],dp[i-c]+1);
        }
    }
    cout << (dp[x]==INF ? -1 : dp[x]) << "\n";

    return 0;
}
