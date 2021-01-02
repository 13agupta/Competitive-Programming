#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a,b;
    cin >> a >> b;
    vector<int> res(2,0);
    while(a) {
        res[0]+=a%10;
        a/=10;
    }
    while(b) {
        res[1]+=b%10;
        b/=10;
    }
    cout << max(res[0],res[1]) << "\n";

    return 0;
}
