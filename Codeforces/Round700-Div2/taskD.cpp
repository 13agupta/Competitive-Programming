#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int cur = 0;
    int cnt = 0;
    int prev = arr[0];
    vector<pair<int,int>> compress;
    while(cur < n) {
        while(cur < n && arr[cur] == prev) {
            cur++;
            cnt++;
        }
        compress.push_back({prev,cnt});
        if(cur >= n)
            break;
        cnt = 0;
        prev = arr[cur];
    }
    int dom = -1;
    int res = 0;
    for(int i=0; i<sz(compress); i++) {
        pair<int,int> p = compress[i];
        if(p.first == dom)
            res++;
        else if(p.second >= 2) {
            res += min(p.second,2);
            dom = p.first;
        }
        else {
            res++;
            if(i > 0 && compress[i-1].second == 1 && compress[i-1].first != dom && p.second == 1)
                dom = -1;
        }
    }
    cout << res << "\n";

    return 0;
}
