#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size(), msf = 0;
    for (int i=0; i<n;) {
        int j=i+1;
        while (j < n && s[j] == s[i])
            ++j;
        msf = max(msf, j - i);
        i = j;
    }
    cout << msf << endl;
}