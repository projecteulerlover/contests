#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    int t = 0;
    while (n >= 5) {
        t += n/5;
        n /= 5;
    }
    cout << t << endl;

    return EXIT_SUCCESS;
}