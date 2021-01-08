#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int n,k,q;
const int mxN = int(5e3) + 5;
const int64_t MOD = int(1e9) + 7;
int64_t dp[mxN][mxN],tmp[mxN][mxN];
int64_t sums[mxN];

int64_t mul(int64_t a,int64_t b) {
    a = (a+MOD)%MOD;
    b = (b+MOD)%MOD;
    return (a*b)%MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k >> q;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    for(int i=0; i<n; i++) {
        dp[i][0] = 1;
    }
    int64_t totVal = 0;
    for(int j=1; j<=k; j++) {
        for(int i=0; i<n; i++) {
            int tot = 0;
            if(i-1>=0)
                tot += dp[i-1][j-1];
            if(i+1<n)
                tot += dp[i+1][j-1];
            dp[i][j] = tot%MOD;
        }
    }
    /* cout << "dp:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<=k; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    } */
    for(int j=0; j<=k; j++) {
        for(int i=0; i<n; i++) {
            int64_t cur = dp[i][j] * dp[i][k-j];
            tmp[i][j] = cur;
        }
    }
    memcpy(dp,tmp,sizeof(tmp));
    for(int i=0; i<n; i++) {
        for(int j=0; j<=k; j++) {
            sums[i] += dp[i][j];
            sums[i] %= MOD;
        }
    }
    /* cout << "dp:\n";
    for(int i=0; i<n; i++) {
        for(int j=0; j<=k; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    cout << "sums:\n";
    for(int i=0; i<n; i++)
        cout << sums[i] << " ";
    cout << endl; */
    for(int i=0; i<n; i++) {
        totVal += (sums[i]*1LL*arr[i]) % MOD;
        totVal %= MOD;
    }
    while(q--) {
        int i,x;
        cin >> i >> x;
        i--;
        totVal -= mul(arr[i],sums[i]);
        arr[i] = x;
        totVal += mul(arr[i],sums[i]);
        totVal = ((totVal%MOD) + MOD)%MOD;
        cout << totVal << "\n";
    }

    return 0;
}
