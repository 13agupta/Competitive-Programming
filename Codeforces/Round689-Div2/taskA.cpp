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
        int n,k;
        cin >> n >> k;
        vector<char> arr = {'a','b','c'};
        while(true) {
            for(auto e : arr) {
                if (n <= 0) goto end;
                n--;
                cout << e;
            }
        }
        end:;
        cout << "\n";
    }

    return 0;
}
