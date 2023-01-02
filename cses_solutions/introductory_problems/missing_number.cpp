#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int64_t n, m, t = 0;
    cin >> n;
    for (int i=0; i<n-1; ++i) {
        cin >> m;
        t += m;
    }
    cout << n*(n+1)/2 - t << endl;

    return EXIT_SUCCESS;
}