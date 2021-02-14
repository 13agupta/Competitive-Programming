#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int INF = 100000;

int64_t findAns(int64_t a,int64_t b) {
    int64_t res = 0;
    while(a) {
        res++;
        a = a / b;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int64_t a,b;
        cin >> a >> b;
        int64_t res = 0;
        if(b == 1) {
            res++;
            b++;
        }
        int64_t best = INF;
        for(int i=b; i<=b+30; i++)
            best = min(best,res + i - b + findAns(a,i));
        cout << best << "\n";
    }

    return 0;
}
