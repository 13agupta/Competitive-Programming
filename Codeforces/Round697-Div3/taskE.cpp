#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int MOD = int(1e9) + 7;

int64_t mul(int64_t a,int64_t b) {
    a %= MOD;
    b %= MOD;
    return (a*b) % MOD;
}

int64_t modpow(int64_t n,int64_t k) {
    if(k==0)
        return 1;
    int64_t res = modpow(n,k/2);
    if(k % 2 == 0)
        return mul(res,res);
    return mul(res,mul(res,n));
}

int64_t choose(int64_t n,int64_t k) {
    int64_t res = 1;
    int64_t div = 1;
    while(k--) {
        div *= (k+1);
        div %= MOD;
        res *= (n-k);
        res %= MOD;
    }
    return mul(res,modpow(div,MOD-2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        sort(arr.begin(),arr.end(),greater<int>());
        int cnt[2];
        cnt[0] = cnt[1] = 0;
        for(int i=k; i<n; i++) {
            cnt[0] += (arr[i] == arr[k-1]);
        }
        for(int i=0; i<k; i++)
            cnt[1] += (arr[i] == arr[k-1]);
        cout << choose(cnt[0] + cnt[1],cnt[1]) << "\n";
    }

    return 0;
}
