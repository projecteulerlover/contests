#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> ks(n);
    for (int i=0; i<n; ++i)
        cin >> ks[i];
    int msf = 0, l = 0;
    set<int> seen;
    for (int r=0; r<n; ++r) {
        while (seen.find(ks[r]) != seen.end())
            seen.erase(ks[l++]);
        seen.insert(ks[r]);
        msf = max(msf, r-l+1);
    }
    
    cout << msf << '\n';
    return EXIT_SUCCESS;
}