#include <bits/stdc++.h>
#pragma GCC target("popcnt")
    
using namespace std;
 
int n;
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    bitset<3000> g[3000];
    for (int i=0; i<n; ++i) cin >> g[i];
    int64_t t = 0;
    for (int i=0; i<n-1; ++i)
        for (int j=i+1; j<n; ++j) {
            int64_t x = (g[i] & g[j]).count();
            t += x * (x - 1) / 2;
        }
    cout << t << endl;
    return EXIT_SUCCESS;
}