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
        int n;
        cin >> n;
        deque<int> arr;
        int prev=-1;
        for(int i=0; i<n; i++) {
            int e;
            cin >> e;
            if(e==prev)
                continue;
            prev=e;
            arr.push_back(e);
        }
        if(sz(arr)==1) {
            cout << 0 << "\n";
            continue;
        }
        map<int,int> freq;
        freq.insert({arr.front(),0});
        freq.insert({arr.back(),0});
        arr.pop_front();
        if(!arr.empty())
            arr.pop_back();
        for(int i=0; i<sz(arr); i++)
            freq[arr[i]]++;
        int best=1e8;
        for(auto p : freq) {
            if(p.second<best) {
                best=p.second;
            }
        }
        cout << best+1 << "\n";
    }

    return 0;
}
