#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9+7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;
    vector<int> counter(26, 0);
    for (char c : s)
        ++counter[c-'A'];
    bool middle = false;
    int p = 0, n = s.size();
    for (int i=0; i<26; ++i) {
        int j = counter[i];
        while (j > 1) {
            j -= 2;
            s[p] = 'A' + i;
            s[n-p-1] = 'A' + i;
            ++p;
        }
        if (j == 1) {
            if (middle) {
                cout << "NO SOLUTION\n";
                return EXIT_SUCCESS;
            }
            middle = true;
            s[n/2] = 'A' + i;
        }
    }

    cout << s << "\n";
    return EXIT_SUCCESS;
}