#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

bool check(ll n) {
    ll tmp=n;
    set<ll> digits;
    while(tmp) {
        digits.insert(tmp%10);
        tmp/=10;
    }
    for(auto &digit : digits) {
        if(digit==0) continue;
        if(n%digit) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        while(!check(n)) n++;
        cout << n << "\n";
    }

    return 0;
}
