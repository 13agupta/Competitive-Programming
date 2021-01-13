#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
typedef long long ll;
using namespace std;
int n;

bool check(int value) {
    int tot = value;
    int temp = value;
    int cnt = -1;
    while(temp) {
        cnt++;
        temp /= 10;
    }
    temp = value;
    int cur = 0;
    int rev = 0;
    while(temp) {
        int d = temp%10;
        temp /= 10;
        rev += d * pow(10,cnt-cur);
        cur++;
    }
    tot += rev;
    return tot==n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=1; i<n; i++) {
        if(check(i))
            cout << i << endl;
    }

    return 0;
}
