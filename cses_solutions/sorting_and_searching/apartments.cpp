#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> as(n), bs(m);
    for (int i=0; i<n; ++i)
        cin >> as[i];
    for (int i=0; i<m; ++i)
        cin >> bs[i];
    sort(as.begin(), as.end()), sort(bs.begin(), bs.end());
    int i=0, j=0, c=0;
    while (i<n && j<m) {
        int a = as[i], b = bs[j];
        if (a-k <= b && b <= a+k) {
            ++i;
            ++j;
            ++c;
            continue;
        }
        if (b<a-k) {
            ++j;
            continue;
        }
        ++i;
    }
    cout << c << '\n';
    return EXIT_SUCCESS;
}