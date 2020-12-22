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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt=0;
        while(!s.empty() && s.back()==')') { s.pop_back(); cnt++;}
        cout << (cnt>sz(s) ? "Yes" : "No") << "\n";
    }

    return 0;
}
