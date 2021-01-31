#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;

int64_t binpow(int64_t a,int64_t b) {
    if(b == 0)
        return 1;
    int64_t res = binpow(a,b/2);
    if(b % 2) return res * res * a;
    return res * res;
}

int64_t logfl(int64_t value,int64_t base) {
    int64_t res = -1;
    int64_t l = 0,h = (log(abs(value)) / log(abs(base))) + 2;
    while(l <= h) {
        int64_t mid = l + (h - l) / 2;
        int64_t result = binpow(base,mid);
        if(abs(result) <= abs(value)) {
            res = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int64_t first,q,l,n;
    cin >> first >> q >> l >> n;
    vector<int64_t> arr(n);
    bool hasFirst[2];
    hasFirst[0] = hasFirst[1] = false;
    bool hasZero = false;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
        if(arr[i] == 0)
            hasZero = true;
        if(arr[i] == first)
            hasFirst[0] = true;
        if(arr[i] == -first)
            hasFirst[1] = true;
    }
    if(first == 0 || q == 0) {
        if(abs(first) > l)
            cout << "0\n";
        else if(hasZero && first != 0 && !hasFirst[0])
            cout << "1\n";
        else if(hasZero)
            cout << "0\n";
        else
            cout << "inf\n";
        return 0;
    }
    if((q == 1 || q == -1) && abs(first) <= l) {
        if(q == 1 && hasFirst[0])
            cout << "0\n";
        else if(q == -1 && hasFirst[0] && hasFirst[1])
            cout << "0\n";
        else
            cout << "inf\n";
        return 0;
    }
    if((q == 1 || q == -1) && abs(first) > l) {
        cout << "0\n";
        return 0;
    }
    int64_t res = 0;
    for(int i=0; i<n; i++) {
        if(abs(arr[i]) < abs(first) || abs(arr[i]) > l)
            continue;
        int64_t div = arr[i] / first;
        int64_t times = logfl(div,q);
        int64_t value = binpow(q,times);
        if(first * value == arr[i])
            res--;
    }
    first = abs(first);
    q = abs(q);
    int64_t div = l / first;
    int64_t times = logfl(div,q) + 1;
    res += times;
    cout << res << "\n";

    return 0;
}
