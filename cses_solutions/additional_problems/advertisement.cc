#include <bits/stdc++.h>
    
using namespace std;
 
int n;
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<int64_t> vs(n);
    for (int i=0; i<n; ++i) cin >> vs[i];
    vector<int64_t> ms, ls(n);
    for (int i=0; i<n; ++i) {
        while (!ms.empty() && vs[ms.back()] >= vs[i]) ms.pop_back();
        ls[i] = (i - (ms.empty() ? -1 : ms.back()));
        ms.push_back(i);
    }
    ms.clear();
    int64_t msf = 0;
    for (int i=n-1; i>=0; --i) {
        while (!ms.empty() && vs[ms.back()] >= vs[i]) ms.pop_back();
        msf = max(msf, (ls[i] + (ms.empty() ? n : ms.back()) - i - 1) * vs[i]);
        ms.push_back(i);
    }
    cout << msf << '\n';
    return EXIT_SUCCESS;
}