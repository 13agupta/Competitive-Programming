#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int n;
vector<int> arr;

bool check(int pos) {
    if(pos<1 || pos>=n-1) return false;
    if(arr[pos]>arr[pos-1] && arr[pos]>arr[pos+1])
        return true;
    return (arr[pos]<arr[pos-1] && arr[pos]<arr[pos+1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while(tt--) {
        cin >> n;
        arr.assign(n,0);
        int tot = 0;
        for(int i=0; i<n; i++)
            cin >> arr[i];
        for(int i=1; i<n-1; i++)
            tot += check(i);
        int best = tot;
        for(int i=0; i<n; i++) {
            // set equal to left
            int original = arr[i];
            int cur = tot;
            for(int j=i-1; j<=i+1; j++)
                cur -= check(j);
            arr[i] = arr[i-1];
            for(int j=i-1; j<=i+1; j++)
                cur += check(j);
            best = min(best,cur);
            // set equal to right
            arr[i] = original;
            cur = tot;
            for(int j=i-1; j<=i+1; j++)
                cur -= check(j);
            arr[i] = arr[i+1];
            for(int j=i-1; j<=i+1; j++)
                cur += check(j);
            best = min(best,cur);
            arr[i] = original;
        }
        cout << best << "\n";
    }

    return 0;
}
