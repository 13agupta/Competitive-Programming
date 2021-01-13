#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s,t;
    cin >> s >> t;
    int cnt = 0;
    for(int i=0; i<=sz(s)-sz(t); i++) {
        if(s.substr(i,sz(t))==t) {
            s[i+sz(t)-1] = '#';
            cnt++;
        }
    }
    cout << cnt << "\n";

    return 0;
}
