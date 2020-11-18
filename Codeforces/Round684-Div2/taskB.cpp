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
        int n,k;
        cin >> n >> k;
        deque<int> arr(n*k);
        for(int i=0; i<n*k; i++)
            cin >> arr[i];
        int del=((n+1)/2-1)*k;
        for(int i=0; i<del; i++)
            arr.pop_front();
        ll tot=0;
        int rem=(n-((n+1)/2-1)-1);
        for(int i=0; i<k; i++) {
            tot+=arr.front();
            arr.pop_front();
            int cur=0;
            while(!arr.empty() && cur!=rem) {
                arr.pop_front();
                cur++;
            }
        }
        cout << tot << "\n";
    }

    return 0;
}
