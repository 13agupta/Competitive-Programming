#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int factorize(int value) {
    map<int,int> primes;
    for(int i=2; i*i<=value; i++) {
        if(value%i==0) {
            primes[i] = 0;
            while(value%i==0) {
                primes[i]++;
                value/=i;
            }
        }
    }
    if(value!=1)
        primes[value]++;
    int res = 1;
    for(auto &p : primes) {
        if(p.second%2!=0)
            res *= p.first;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        map<int,int> freq;
        for(int i=0; i<n; i++) {
            cin >> arr[i];
            freq[factorize(arr[i])]++;
        }
        int ans[2];
        ans[0] = ans[1] = 0;
        for(auto &p : freq)
            ans[0] = max(p.second,ans[0]);
        for(auto p : freq) {
            if(p.first==1) continue;
            if(p.second%2==0) {
                freq[1] += p.second;
            }
        }
        for(auto &p : freq)
            ans[1] = max(ans[1],p.second);
        int q;
        cin >> q;
        while(q--) {
            int64_t w;
            cin >> w;
            cout << (w==0 ? ans[0] : ans[1]) << "\n";
        }
    }

    return 0;
}
