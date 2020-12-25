#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const int mxX=1e6+5;
const int MOD=1e9+7;
int64_t dp[mxX],tmp[mxX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x;
    cin >> n >> x;
    deque<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());
    arr.push_front(0);
    dp[0]=1;
    for(int i=1; i<=n; i++) {
        memcpy(tmp,dp,sizeof(dp));
        for(int j=1; j<=x; j++) {
            if(j-arr[i]<0) continue;
            tmp[j]+=tmp[j-arr[i]];
            tmp[j]%=MOD;
        }
        memcpy(dp,tmp,sizeof(tmp));
    }
    cout << dp[x] << "\n";

    return 0;
}
