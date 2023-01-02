#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9+7;

int PowMod(int64_t b, int p) {
    int64_t t = 1;
    while (p) {
        if (p % 2)
           t = (t * b) % kMod;
        b = (b * b) % kMod;
        p /= 2;
    }
    return t;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    cout << PowMod(2, n) << endl;

    return EXIT_SUCCESS;
}