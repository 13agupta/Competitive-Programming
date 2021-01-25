#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int mxN = int(2e5) + 5;
vector<int> factors[mxN];

vector<int> factorize(int value) {
    vector<int> factors;
    for(int i=1; i*i<=value; i++) {
        if(value % i == 0) {
            factors.push_back(i);
            factors.push_back(value/i);
        }
    }
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    for(int i = 1; i<mxN; i++)
        factors[i] = factorize(i);
    while(tt--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        sort(arr.begin(),arr.end());
        unordered_map<int,int> seen;
        seen[arr[0]] = 1;
        for(int i=1; i<n; i++) {
            int best = 1;
            for(auto factor : factors[arr[i]]) {
                if(seen.find(factor)!=seen.end())
                    best = max(best,1 + seen[factor]);
            }
            seen[arr[i]] = best;
        }
        int best = 1;
        for(auto e : seen)
            best = max(best,e.second);
        cout << n-best << "\n";
    }

    return 0;
}
