#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int MOD = int(1e9) + 7;

struct mi {
 	int v; explicit operator int() const { return v; } 
	mi() { v = 0; }
	mi(int64_t _v):v(_v%MOD) { v += (v<0)*MOD; }
};
mi& operator+=(mi& a, mi b) { 
	if ((a.v += b.v) >= MOD) a.v -= MOD; 
	return a; }
mi& operator-=(mi& a, mi b) { 
	if ((a.v -= b.v) < 0) a.v += MOD; 
	return a; }
mi operator+(mi a, mi b) { return a += b; }
mi operator-(mi a, mi b) { return a -= b; }
mi operator*(mi a, mi b) { return mi((int64_t)a.v*b.v); }
mi& operator*=(mi& a, mi b) { return a = a*b; }
mi pow(mi a, int64_t p) { assert(p >= 0); // asserts are important! 
	return p==0?1:pow(a*a,p/2)*(p&1?a:1); }
mi inv(mi a) { assert(a.v != 0); return pow(a,MOD-2); }
mi operator/(mi a, mi b) { return a*inv(b); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<mi> dp(n,0);
        vector<int64_t> arr(n,0);
        dp[0] = mi(1);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        int64_t pref = 0;
        mi prefDp = 1;
        map<int64_t,mi> seen;
        seen[0] = 1;
        for(int i=1; i<n; i++) {
            pref += arr[i-1];
            dp[i] = prefDp;
            if(seen.find(pref) != seen.end())
                dp[i] -= seen[pref];
            seen[pref] += dp[i];
            prefDp += dp[i];
        }
        cout << int(prefDp) << "\n";
    }

    return 0;
}
