#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
int n,m;

bool check(vector<int> &pref,int fc,int sc) {
    if(fc < 0 || sc >= m) return false;
    return (pref[sc + 1] - pref[fc] == (sc - fc + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n >> m;
        vector<string> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        vector<vector<int>> pref(n,vector<int>(m+1,0));
        for(int i=0; i<n; i++) {
            for(int j=1; j<m+1; j++)
                pref[i][j] = pref[i][j-1] + (arr[i][j-1] == '*');
        }
        int64_t cnt = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int len = 0;
                while(i + len < n && check(pref[i + len],j-len,j+len)) len++;
                cnt += len;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
