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
        int x,y;
        cin >> x >> y;
        string s;
        cin >> s;
        map<char,int> ma;
        ma['U'] = ma['R'] = ma['D'] = ma['L'] = 0;
        for(int i=0; i<sz(s); i++) {
            if(s[i] == 'R')
                ma['R']++;
            else if(s[i] == 'L')
                ma['L']--;
            else if(s[i] == 'U')
                ma['U']++;
            else
                ma['D']--;
        }
        if(y > ma['U'] || y < ma['D']) {
            cout << "NO\n";
            goto end;
        }
        if(x > ma['R'] || x < ma['L']) {
            cout << "NO\n";
            goto end;
        }
        cout << "YES\n";
        end:;
    }

    return 0;
}
