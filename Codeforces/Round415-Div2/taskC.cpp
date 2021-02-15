#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
int n;
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

    cin >> n;
    vector<int> tmp(n);
    for(int i=0; i<n; i++)
        cin >> tmp[i];
    sort(tmp.begin(),tmp.end());
    vector<mi> arr(n);
    for(int i=0; i<n; i++)
        arr[i] = mi(tmp[i]);
    mi res = 0;
    for(int i=0; i<n; i++) {
        res += arr[i] * pow(mi(2),i);
        res -= arr[i] * pow(mi(2),n - i - 1);
    }
    cout << int(res) << "\n";

    return 0;
}
