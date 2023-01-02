#include <bits/stdc++.h>

using namespace std;

/*
1, ..., n
n*(n+1)/2
6*7/2 = 21

5*6/2 = 15

n % 4 == 0
split

n % 4 == 3
1 2 3 4 5 6 7

1 2 3 4 5 6 7 8 9 10 11
1 2 3 4 5 6 11 = 32
7 8 9 10 = 
15 + 9 + 10 = 34
*/

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    if (n % 4 == 3) {
        int m = n - 3;
        cout << "YES\n";
        cout << n/2 << "\n";
        cout << "3 ";
        for (int i=0; i<m/4; ++i)
            cout << i+4 << " " << n - i << " ";
        cout << "\n" << n/2+1 << "\n";
        cout << "1 2 ";
        for (int i=m/4; i<m/2; ++i)
            cout << i+4 << " " << n - i << " ";
    } else if (n % 4 == 0) {
        cout << "YES\n";
        cout << n/2 << "\n";
        for (int i=0; i<n/4; ++i)
            cout << i+1 << " " << n - i << " ";
        cout << "\n" << n/2 << "\n";
        for (int i=n/4; i<n/2; ++i)
            cout << i+1 << " " << n - i << " ";
    } else {
        cout << "NO\n";
    }

    return EXIT_SUCCESS;
}