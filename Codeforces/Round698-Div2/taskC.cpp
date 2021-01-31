#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
vector<int64_t> arr;

bool cmp(int a,int b) {
    return arr[a] < arr[b];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        arr.assign(2*n,0);
        vector<int> inds(2*n);
        map<int64_t,int> freq;
        vector<int64_t> res(2*n);
        int64_t start = n;
        int64_t tot = 0;
        set<int64_t> seen;
        for(int i=0; i<2*n; i++) {
            cin >> arr[i];
            inds[i] = i;
            freq[arr[i]]++;
        }
        for(auto p : freq) {
            if(p.first % 2 == 1 || p.second != 2) {
                cout << "NO\n";
                goto end;
            }
        }
        sort(inds.begin(),inds.end(),cmp);
        reverse(inds.begin(),inds.end());
        for(int i=0; i<2*n; i+=2) {
            int64_t cur = arr[inds[i]];
            int64_t curres = (cur - tot) / (2 * start);
            if((cur - tot) % (2 * start) != 0 || curres <= 0) {
                cout << "NO\n";
                goto end;
            }
            res[inds[i]] = curres;
            res[inds[i+1]] = -curres;
            tot += 2 * curres;
            start--;
        }
        for(auto e : res) {
            if(seen.find(e) != seen.end()) {
                cout << "NO\n";
                goto end;
            }
            seen.insert(e);
        }
        cout << "YES\n";
        end:;
    }

    return 0;
}
