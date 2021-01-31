#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    deque<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr.begin(),arr.end());
    int cnt = 0;
    for(int i=0; i<n; i++)
        cnt += (arr[i] + k - 1) / k;
    cout << (cnt + 1) / 2 << "\n";
        
    return 0;
}
