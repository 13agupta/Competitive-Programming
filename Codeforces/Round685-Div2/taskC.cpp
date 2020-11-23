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
        int n,k;
        cin >> n >> k;
        string a,b;
        cin >> a >> b;
        multiset<char> se[2];
        for(int i=0; i<n; i++) {
            se[0].insert(a[i]);
            se[1].insert(b[i]);
        }
        while(!se[1].empty()) {
            char s=*se[1].begin();
            char f=*se[0].begin();
            if(f==s) {
                se[0].erase(se[0].begin());
                se[1].erase(se[1].begin());
            }
            else if(f>s) {
                cout << "NO\n";
                goto end;
            }
            else {
                if(sz(se[0])<k) {
                    cout << "NO\n";
                    goto end;
                }
                for(int i=0; i<k; i++) {
                    if(*se[0].begin()!=f) {
                        cout << "NO\n";
                        goto end;
                    }
                    se[0].erase(se[0].begin());
                }
                for(int i=0; i<k-1; i++)
                    se[0].insert(s);
                se[1].erase(se[1].begin());
            }
        }
        cout << "YES\n";
        end:;
    }

    return 0;
}
