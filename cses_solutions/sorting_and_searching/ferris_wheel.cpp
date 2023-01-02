#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<int> ps(n);
    for (int i=0; i<n; ++i)
        cin >> ps[i];
    sort(ps.begin(), ps.end());
    int l=0, r=n-1, c=0;
    while (l < r) {
        ++c;
        int pl = ps[l], pr = ps[r];
        if (pl + pr <= x) {
            ++l;
            --r;
            continue;
        }
        --r;
    }
    if (l == r)
        ++c;
    cout << c << '\n';
    return EXIT_SUCCESS;
}