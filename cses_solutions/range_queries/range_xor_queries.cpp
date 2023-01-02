#include <bits/stdc++.h>

using namespace std;

int n, q;
vector<int> xs;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> q;
    xs.resize(n+1);
    xs[0] = 0;
    for (int i=0; i<n; ++i) {
        cin >> xs[i+1];
        xs[i+1] ^= xs[i];
    }
    int a, b;
    for (int i=0; i<q; ++i) {
        cin >> a >> b;
        cout << (xs[b] ^ xs[a-1]) << '\n';
    }
    /*
    010
    100
    101
    011
    */
    return EXIT_SUCCESS;
}