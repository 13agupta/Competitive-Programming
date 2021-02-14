#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int qry(int x) {
    cout << "? " << x + 1 << endl;
    cin >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int l = 0,r = n-1;
    while(l != r) {
        int m = (l + r) / 2;
        if(qry(m) < qry(m + 1))
            r = m;
        else
            l = m + 1;
    }
    cout << "! " << l + 1 << endl;

    return 0;
}
