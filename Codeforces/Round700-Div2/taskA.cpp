#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        string s;
        cin >> s;
        for(int i=0; i<sz(s); i++) {
            if(i % 2 == 0) {
                s[i] = (s[i] == 'a' ? 'b' : 'a');
            }
            else
                s[i] = (s[i] == 'z' ? 'y' : 'z');
        }
        cout << s << "\n";
    }

    return 0;
}
