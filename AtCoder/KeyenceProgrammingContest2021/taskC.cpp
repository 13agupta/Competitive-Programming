#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int64_t INV = int64_t(332748118);
const int64_t MOD = int64_t(998244353);
const int mxN = int(5e3) + 5;
int64_t dp[mxN][mxN];
char arr[mxN][mxN];
int h,w,k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> h >> w >> k;
    for(int i=0; i<k; i++) {
        int r,c; char val;
        cin >> r >> c >> val;
        arr[r][c] = val;
    }
    dp[1][1] = 1;
    for(int i=1; i<=h; i++)
        arr[i][0] = 'X';
    for(int j=1; j<=w; j++)
        arr[0][j] = 'X';
    for(int i=1; i<=h; i++) {
        for(int j=1; j<=w; j++) {
            if(i==1 && j==1) continue;
            switch(arr[i-1][j]) {
                case 0:
                    dp[i][j] += (2 * INV * dp[i-1][j]) % MOD;
                    break;
                case 'X':
                case 'D':
                    dp[i][j] += dp[i-1][j];
                    break;
            }
            switch(arr[i][j-1]) {
                case 0:
                    dp[i][j] += (2 * INV * dp[i][j-1]) % MOD;
                    break;
                case 'X':
                case 'R':
                    dp[i][j] += dp[i][j-1];
                    break;
            }
        }
    }
    int times = h * w - k;
    int64_t mul = 1;
    while(times--) {
        mul *= 3;
        mul %= MOD;
    }
    cout << (dp[h][w] * mul) % MOD << "\n";

    return 0;
}
