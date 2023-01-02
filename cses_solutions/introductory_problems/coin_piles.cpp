#include <bits/stdc++.h>

using namespace std;

/*
2*x + y = a
x + 2*y = b

x-y = a-b => 3x = 2*a-b
y-x = b-a => 3y = 2*b-a

*/

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int t, a, b;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int u = 2*a - b, v = 2*b - a;
        cout << ((u >= 0 && v >= 0 && u % 3 == 0 && v % 3 == 0) ? "YES\n" : "NO\n");
    }

    return EXIT_SUCCESS;
}