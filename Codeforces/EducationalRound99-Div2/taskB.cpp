#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int x;
        cin >> x;
        int cur=1;
        while((cur*(cur+1))/2<x) cur++;
        if((cur*(cur+1))/2-1==x)
            cur++;
        cout << cur << "\n";
    }

    return 0;
}
