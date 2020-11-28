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
        vector<int> arr(n);
        for(int i=0; i<n; i++)
            cin >> arr[i];
        set<int> vis,se;
        for(auto i : arr) {
            if(vis.find(i)==vis.end())
                se.insert(i);
            if(vis.find(i)!=vis.end() && se.find(i)!=se.end())
                se.erase(i);
            vis.insert(i);
        }
        if(!se.empty()) {
            int val=*se.begin();
            int ind=-1;
            for(int i=0; i<n; i++) {
                if(arr[i]==val) {
                    ind=i;
                    break;
                }
            }
            cout << ind+1 << "\n";
        }
        else
            cout << "-1\n";
    }

    return 0;
}
