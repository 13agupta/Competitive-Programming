#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
string s,t;

vector<int> prefix_function(string str) {
    int n = (int)str.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && str[i] != str[j])
            j = pi[j-1];
        if (str[i] == str[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    int cnt[2][2];
    cnt[0][0] = cnt[0][1] = cnt[1][0] = cnt[1][1] = 0;
    for(int i=0; i<sz(s); i++)
        cnt[0][s[i] - '0']++;
    for(int i=0; i<sz(t); i++)
        cnt[1][t[i] - '0']++;
    if(cnt[0][0] < cnt[1][0] || cnt[0][1] < cnt[1][1]) {
        cout << s << "\n";
        return 0;
    }
    string res = t;
    cnt[0][0] -= cnt[1][0];
    cnt[0][1] -= cnt[1][1];
    vector<int> pi = prefix_function(t);
    int prefix = pi[sz(t) - 1];
    int suffix = sz(t) - prefix;
    while(cnt[0][0] && cnt[0][1]) {
        for(int i=sz(t)-suffix; i<sz(t); i++) {
            if(!cnt[0][t[i] - '0']) break;
            cnt[0][t[i] - '0']--;
            res.push_back(t[i]);
        }
    }
    while(cnt[0][0]--)
        res.push_back('0');
    while(cnt[0][1]--)
        res.push_back('1');
    cout << res << "\n";

    return 0;
}
