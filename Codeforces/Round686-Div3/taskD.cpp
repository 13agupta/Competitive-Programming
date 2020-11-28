#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

map<ll,ll> factorize(ll n) {
    map<ll,ll> res;
    for(int i=2; i*1LL*i<=n; i++) {
        while(n%i==0) {
            res[i]++;
            n/=i;
        }
    }
    if(n)
        res[n]++;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        map<ll,ll> primes=factorize(n);
        ll best=-1;
        ll val=-1;
        for(auto p : primes) {
            if(best<p.second) {
                best=p.second;
                val=p.first;
            }
        }
        cout << best << "\n";
        ll tot=1;
        for(auto p : primes) {
            if(p.first==val)
                tot*=1LL*val;
            else {
                ll cur=p.second;
                while(cur--)
                    tot*=1LL*p.first;
            }
        }
        for(int i=0; i<best-1; i++)
            cout << val << " ";
        cout << tot << "\n";
    }

    return 0;
}
