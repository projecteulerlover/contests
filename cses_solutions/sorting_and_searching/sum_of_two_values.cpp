#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> as(n);
    for (int i=0; i<n; ++i) {
        cin >> as[i].first;
        as[i].second = i+1;
    }
    sort(as.begin(), as.end());
    int l=0, r=n-1;
    while (l < r) {
        int t = as[l].first + as[r].first;
        if (t == x) {
            cout << as[l].second << ' ' << as[r].second << '\n';
            return EXIT_SUCCESS;
        } else if (t < x) {
            ++l;
        } else {
            --r;
        }
    }
    cout << "IMPOSSIBLE\n";
    return EXIT_SUCCESS;
}