#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;
    while(q--) {
        string s,t;
        cin >> s >> t;
        if(sz(s)>sz(t))
            swap(s,t);
        string gcd = "";
        int times,timesFirst,timesSecond;
        for(int i=1; i<=sz(s); i++) {
            if(sz(t)%i!=0) continue;
            gcd = s.substr(0,i);
            for(int j=0; j<sz(t); j+=sz(gcd)) {
                if(gcd!=t.substr(j,sz(gcd))) {
                    gcd = "";
                    break;
                }
            }
            if(gcd!="") {
                for(int j=0; j<sz(s); j+=sz(gcd)) {
                    if(gcd!=s.substr(j,sz(gcd))) {
                        gcd = "";
                        break;
                    }
                }
            }
            if(gcd!="")
                break;
        }
        if(gcd=="") {
            cout << "-1\n";
            goto end;
        }
        timesFirst = sz(s) / sz(gcd),timesSecond = sz(t) / sz(gcd);
        times = (timesFirst*timesSecond) / __gcd(timesFirst,timesSecond);
        while(times--)
            cout << gcd;
        cout << "\n";
        end:;
    }

    return 0;
}
