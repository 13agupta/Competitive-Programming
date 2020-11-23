#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

bool check(int cur,int d,int k) {
    return (cur + k)*1LL*(cur + k) + cur*1LL*cur > d*1LL*d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int d,k;
        cin >> d >> k;
        int cur=0;
        while(cur*2LL*cur < d*1LL*d)
            cur+=k;
        cur-=k;
        cout << (check(cur,d,k) ? "Utkarsh" : "Ashish") << "\n";
    }

    return 0;
}
