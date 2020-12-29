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
        string s;
        cin >> s;
        if(sz(s)%2==1 || s[0]==')' || s[sz(s)-1]=='(')
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
