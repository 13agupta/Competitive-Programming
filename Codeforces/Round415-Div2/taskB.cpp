#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int mxN = int(1e5) + 5;
int64_t k[mxN],l[mxN];
int n,f;

bool comp(int a,int b) {
    int64_t resA = min(2 * k[a], l[a]) - min(k[a], l[a]);
    int64_t resB = min(2 * k[b], l[b]) - min(k[b], l[b]);
    return resA > resB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> f;
    for(int i=0; i<n; i++)
        cin >> k[i] >> l[i];
    vector<int> arr(n);
    iota(arr.begin(),arr.end(),0);
    sort(arr.begin(),arr.end(),comp);
    int64_t tot = 0;
    for(int i=0; i<n; i++) {
        if(i < f)
            tot += min(2 * k[arr[i]], l[arr[i]]);
        else
            tot += min(k[arr[i]], l[arr[i]]);
    }
    cout << tot << "\n";

    return 0;
}
