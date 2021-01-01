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
        string s;
        cin >> s;
        vector<int> arr(sz(s));
        for(int i=0; i<sz(s); i++)
            arr[i]=s[i]-'a';
        int cur=26;
        int res=0;
        for(int i=1; i<sz(s); i++) {
            if(arr[i]==arr[i-1] || (i-2>=0 && arr[i]==arr[i-2])) {
                arr[i]=cur++;
                res++;
            }
        }
        cout << res << "\n";
    }

    return 0;
}
