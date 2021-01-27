#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
int64_t multiple,k,d,t;

double check(double ans) {
    int64_t times = int64_t(ans) / multiple;
    double time[2];
    time[0] = times * k;
    time[1] = times * (multiple - k);
    ans -= times * multiple;
    if(k > ans)
        time[0] += ans;
    else {
        time[0] += k;
        time[1] += (ans - k);
    }
    return time[0] + time[1] / 2;
}

uint64_t checkInt(uint64_t ans) {
    uint64_t times = uint64_t(ans) / multiple;
    uint64_t time[2];
    time[0] = times * k;
    time[1] = times * (multiple - k);
    ans -= times * multiple;
    if(uint64_t(k) > ans)
        time[0] += ans;
    else {
        time[0] += k;
        time[1] += (ans - k);
    }
    return time[0] + time[1] / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);

    cin >> k >> d >> t;
    auto start = std::chrono::high_resolution_clock::now();
    multiple = (k + d - 1) / d;
    multiple *= d;
    if(t < int64_t(1e10)) {
        double lo = 0, hi = 2e18;
        std::chrono::duration<double> diff(0.9);
        while(std::chrono::high_resolution_clock::now() - start < diff) {
            double mid = lo + (hi - lo) / 2;
            if(check(mid) > t)
                hi = mid;
            else
                lo = mid;
        }
        cout << lo << "\n";
    }
    else {
        uint64_t lo = 0, hi = 2e18;
        std::chrono::duration<double> diff(0.9);
        while(std::chrono::high_resolution_clock::now() - start < diff) {
            uint64_t mid = lo + (hi - lo) / 2;
            if(checkInt(mid) > uint64_t(t))
                hi = mid;
            else
                lo = mid;
        }
        cout << lo << "\n";
    }

    return 0;
}
