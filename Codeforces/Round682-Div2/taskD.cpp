#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    int xor_sum = 0;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        xor_sum ^= arr[i];
    }
    if(n%2==0 && xor_sum!=0) {
        cout << "NO\n";
        return 0;
    }
    if(n%2==0) n--;
    vector<tuple<int,int,int>> res;
    for(int i=0; i<n-1; i+=2)
        res.push_back(make_tuple(i+1,i+2,i+3));
    for(int i=0; i<n-3; i+=2)
        res.push_back(make_tuple(i+1,i+2,n));
    cout << "YES\n" << sz(res) << "\n";
    for(auto &t : res)
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << "\n";

    return 0;
}
