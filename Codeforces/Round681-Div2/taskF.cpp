#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
const ll MOD=998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n,k;
        cin >> n >> k;
        vector<int> a(n),b(k);
        for(int i=0; i<n; i++)
            cin >> a[i];
        for(int i=0; i<k; i++)
            cin >> b[i];
        map<int,int> comp;
        for(int i=0; i<n; i++)
            comp[a[i]]=i;
        for(int i=0; i<k; i++)
            b[i]=comp[b[i]];
        set<int> se;
        for(int i=-1; i<n; i++)
            se.insert(i);
        set<int> unvis;
        for(int i=0; i<k; i++)
            unvis.insert(b[i]);
        ll tot=1;
        for(int i=0; i<k; i++) {
            unvis.erase(b[i]);
            auto uit=se.lower_bound(b[i]);
            ++uit;
            auto lit=se.lower_bound(b[i]);
            --lit;
            if(uit==se.end()) {
                if(lit!=se.begin() && unvis.find(*lit)!=unvis.end()) {
                    tot=0;
                    break;
                }
                else {
                    assert(lit!=se.begin());
                    se.erase(*lit);
                }
            }
            else {
                if(lit==se.begin()) {
                    if(uit!=se.end() && unvis.find(*uit)!=unvis.end()) {
                        tot=0;
                        break;
                    }
                    else {
                        assert(uit!=se.end());
                        se.erase(*uit);
                    }
                }
                else {
                    if(unvis.find(*uit)!=unvis.end() && unvis.find(*lit)==unvis.end())
                        se.erase(*lit);
                    else if (unvis.find(*uit)==unvis.end() && unvis.find(*lit)!=unvis.end())
                        se.erase(*uit);
                    else if (unvis.find(*uit)==unvis.end() && unvis.find(*lit)==unvis.end()) {
                        tot*=2;
                        tot%=MOD;
                        se.erase(*lit);
                    }
                    else {
                        tot=0;
                        break;
                    }
                }
            }
        }
        cout << tot << "\n";
    }

    return 0;
}
