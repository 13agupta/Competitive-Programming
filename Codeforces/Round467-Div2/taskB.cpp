#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int smallestPrime(int y) {
    for(int i=2; i*i <= y; i++) {
        if(y % i == 0)
            return i;
    }
    return y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int p,y;
    cin >> p >> y;
    while(true) {
        if(y < p)
            break;
        int factor = smallestPrime(y);
        if(factor > p) {
            cout << y << "\n";
            goto end;
        }
        y--;
    }
    cout << -1 << "\n";
    end:;

    return 0;
}
