#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int mxN=1e6+5;
const int MOD=1e9+7;
int dp[mxN];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    dp[0]=1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=6; j++) {
            if(i-j<0) continue;
            dp[i]+=dp[i-j];
            dp[i]%=MOD;
        }
    }
    cout << dp[n] << "\n";

    return 0;
}
