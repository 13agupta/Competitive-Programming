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
        int arr[3];
        int tot=0;
        for(int i=0; i<3; i++) {
            cin >> arr[i];
            tot+=arr[i];
        }
        if(tot%3!=0) {
            cout << "No\n";
            continue;
        }
        int x=(2*tot)/3;
        if(x%6!=0) {
            cout << "No\n";
            continue;
        }
        x/=6;
        for(int i=0; i<3; i++) {
            if(arr[i]<x) {
                cout << "No\n";
                goto end;
            }
        }
        cout << "Yes\n";
        end:;
    }

    return 0;
}
