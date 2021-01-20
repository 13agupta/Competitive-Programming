#pragma GCC optimize("O3")

#include "bits/stdc++.h"

#define sz(x) (int)(x).size()
using namespace std;
const int mxN = int(2e5) + 5;
set <int> prime;
bool is_composite[mxN];

void sieve (int n) {
	std::fill (is_composite, is_composite + n, false);
	for (int i = 2; i < n; ++i) {
		if (!is_composite[i]) prime.insert (i);
		for (int j = 2; i * j < n; ++j)
			is_composite[i * j] = true;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve(mxN);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        int first = *prime.lower_bound(n+1);
        int second = *prime.lower_bound(first+n);
        cout << first * 1LL * second << "\n";
    }

    return 0;
}
