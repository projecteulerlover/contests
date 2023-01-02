#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, bool>> ts(2*n);
    for (int i=0; i<n; ++i) {
        cin >> ts[2*i].first;
        ts[2*i].second = true;
        cin >> ts[2*i+1].first;
        ts[2*i+1].second = false;
    }
    sort(ts.begin(), ts.end());
    int msf = 0, c = 0;
    for (const auto& [t, b] : ts) {
        if (b)
            msf = max(msf, ++c);
        else
            --c;
    }
    cout << msf << '\n';
    return EXIT_SUCCESS;
}