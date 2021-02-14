#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int INF = 1e7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    int cur = 0;
    int prev = arr[0];
    vector<int> compress;
    while(cur < n) {
        while(cur < n && arr[cur] == prev)
            cur++;
        compress.push_back(prev);
        if(cur >= n)
            break;
        prev = arr[cur];
    }
    n = sz(compress);
    vector<int> nxt(n);
    map<int,int> nm;
    for(int i=n-1; ~i; i--) {
        if(nm.find(compress[i]) == nm.end())
            nxt[i] = INF;
        else
            nxt[i] = nm[compress[i]];
        nm[compress[i]] = i;
    }
    int mn[2];
    mn[0] = mn[1] = INF;
    int top[2];
    top[0] = top[1] = -1;
    int matches = 0;
    for(int i=0; i<n; i++) {
        if(compress[i] == top[0]) {
            matches++;
            mn[0] = nxt[i];
            if(mn[0] > mn[1]) {
                swap(mn[0],mn[1]);
                swap(top[0],top[1]);
            }
            continue;
        }
        mn[1] = nxt[i];
        top[1] = compress[i];
        if(mn[1] < mn[0]) {
            swap(mn[0],mn[1]);
            swap(top[0],top[1]);
        }
    }
    cout << n - matches << "\n";

    return 0;
}
