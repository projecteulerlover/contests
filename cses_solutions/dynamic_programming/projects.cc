#include <bits/stdc++.h>
 
using namespace std;
 
int n, m, mod = 1e9 + 7;
 
int64_t helper(vector<vector<int64_t>>& dp, int d, int i) {
    if (i == n+1) return d == 0;
    if (d > m) return 0;
    if (dp[d][i] == -1) {
        dp[d][i] = (helper(dp, d+i, i+1) + helper(dp, abs(d-i), i+1)) % mod;
    }
    return dp[d][i];
}
 
int main() {
    cin >> n;
    if (n % 4 != 3 && n % 4 != 0) {
        cout << 0 << endl;
        return EXIT_SUCCESS;
    }
    m = n * (n+1) / 4;
    vector dp(m+1, vector<int64_t>(n+1, -1));
    cout << (helper(dp, 0, 1) * (mod + 1) / 2) % mod << endl;    
    return EXIT_SUCCESS;
}