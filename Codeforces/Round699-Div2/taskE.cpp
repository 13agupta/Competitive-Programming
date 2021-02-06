#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int mxN = int(5e5) + 5;
int dp[mxN],colors[mxN],first[mxN],last[mxN],cnt[mxN];
int n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)
        cin >> colors[i];
    for(int i=0; i<n; i++)
        last[colors[i]] = i;
    for(int i=n-1; ~i; i--)
        first[colors[i]] = i;
    for(int i=n-1; ~i; i--) {
        cnt[colors[i]]++;
        // First try fixing all books of this color
        if(i == first[colors[i]])
            dp[i] = cnt[colors[i]] + dp[last[colors[i]] + 1];
        else
            dp[i] = cnt[colors[i]];
        // Next, try to remove this book
        dp[i] = max(dp[i],dp[i + 1]);
    }
    cout << n - dp[0] << "\n";

    return 0;
}
