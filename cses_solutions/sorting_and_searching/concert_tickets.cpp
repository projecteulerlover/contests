#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, h, t;
    cin >> n >> m;
    multiset<int> hs;
    for (int i=0; i<n; ++i) {
        cin >> h;
        hs.insert(h);
    }
    for (int i=0; i<m; ++i) {
        cin >> t;
        if (hs.empty()) {
            cout << -1 << '\n';
            continue;
        }
        auto itr = hs.upper_bound(t);
        if (itr == hs.begin()) {
            cout << -1 << '\n';
            continue;
        }
        --itr;
        cout << *itr << '\n';
        hs.erase(itr);
    }
    
    return EXIT_SUCCESS;
}