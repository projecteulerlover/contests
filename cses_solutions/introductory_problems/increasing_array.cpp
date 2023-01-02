#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int64_t n, m, msf, t = 0;
    cin >> n;
    cin >> m;
    msf = m;
    for (int i=1; i<n; ++i) {
        cin >> m;
        msf = max(msf, m);
        t += msf - m;
    }
    cout << t << endl;

    return EXIT_SUCCESS;
}