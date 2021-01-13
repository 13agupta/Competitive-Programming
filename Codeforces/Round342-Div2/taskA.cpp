#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t n;
    cin >> n;
    int64_t a,b,c;
    cin >> a >> b >> c;
    a = min(a,b);
    int64_t best = n/a;
    if(n>=b) {
        int64_t times = (n-b)/(b-c);
        int64_t left = n - times * (b-c);
        best = max(best,times + left/a);
        while(left>=b) {
            int64_t otimes = left/b;
            left -= otimes * b;
            times += otimes;
            left += otimes * c;
        }
        best = max(best,times + left/a);
    }
    cout << best << "\n";

    return 0;
}
