#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int64_t n;
    cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return EXIT_SUCCESS;
    }
    for (int i = (n % 2) ? n : n - 1; i >= 1; i -= 2)
        cout << i << "\n";
    for (int i = (n % 2) ? n - 1 : n; i >= 2; i -= 2)
        cout << i << "\n";
    
    return EXIT_SUCCESS;
}