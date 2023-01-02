#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int64_t n;
    cin >> n;
    cout << n << endl;
    while (n != 1) {
        n = n % 2 ? 3 * n + 1 : n / 2;
        cout << n << endl;
    }
    return EXIT_SUCCESS;
}