#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        cin >> b[i];
    priority_queue<int> fpq,spq;
    priority_queue<int64_t> best;
    for(int i=0; i<n; i++) {
        fpq.push(a[i]);
        spq.push(b[i]);
        if(!fpq.empty())
            best.push(fpq.top() * 1LL * b[i]);
        best.push(a[i] * 1LL * b[i]);
        cout << best.top() << "\n";
    }

    return 0;
}
