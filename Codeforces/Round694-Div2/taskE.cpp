#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int qry(int pos) {
    cout << "? " << pos+1 << endl;
    int res;
    cin >> res;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    int start = 0;
    int value;
    for(int i=1; true; i++) {
        value = qry(start);
        if(value!=k)
            break;
        start += i;
        start %= n;
    }
    bool to_left = (value > k);
    for(int shift=1<<20; shift>=1; shift>>=1) {
        if(shift>=n) continue;
        if(to_left) {
            int maybe = (start + n-shift)%n;
            if(qry(maybe)>k)
                start = maybe;
        }
        else {
            int maybe = (start+shift)%n;
            if(qry(maybe)<k)
                start = maybe;
        }
    }
    cout << "! ";
    if(to_left)
        cout << (start-1+n)%n + 1 << endl;
    else
        cout << (start+1)%n + 1 << endl;

    return 0;
}
