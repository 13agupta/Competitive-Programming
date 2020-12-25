#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;
    vector<int64_t> a(n),b(m);
    for(int i=0; i<n; i++)
        cin >> a[i];
    sort(a.begin(),a.end());
    for(int i=0; i<m; i++)
        cin >> b[i];
    int64_t gcd=0;
    for(int i=1; i<n; i++)
        gcd=__gcd(gcd,a[i]-a[i-1]);
    for(int i=0; i<m; i++)
        cout << __gcd(gcd,a[0]+b[i]) << " ";
    cout << "\n";

    return 0;
}
