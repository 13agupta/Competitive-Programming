#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    map<string,int> strs[2];
    for(int i=0; i<n; i++) {
        string s;
        cin >> s;
        if(s[0]=='!')
            strs[1][s.substr(1)]++;
        else
            strs[0][s]++;
    }
    for(auto &s : strs[0]) {
        if(strs[1].find(s.first)!=strs[1].end()) {
            cout << s.first << "\n";
            goto end;
        }
    }
    cout << "satisfiable\n";
    end:;

    return 0;
}
