#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int>> ts(n);
    for (int i=0; i<n; ++i)
        cin >> ts[i].first >> ts[i].second;
    sort(ts.begin(), ts.end(), [](const auto& t1, const auto& t2) {
        return t1.second < t2.second;
    });
    int ce = INT_MIN, c = 0;
    for (const auto& [s, e] : ts) {
        if (s >= ce) {
            ce = e;
            ++c;
        }
    }
    cout << c << '\n';
    return EXIT_SUCCESS;
}