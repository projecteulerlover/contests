#include <bits/stdc++.h>
 
using namespace std;
 
int n, mod = 1e9+7;
 
int solve() {
  vector dp(n+1, vector(n+1, 0));
  dp[0][1] = 1;
  string s;
  for (int i=1; i<=n; ++i) {
    cin >> s;
    for (int j=1; j<=n; ++j)
      if (s[j-1] == '*') dp[i][j] = -1;
  }
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=n; ++j) {
      if (dp[i][j] == -1) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % mod;
    }
  }
  return dp[n][n];
}
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  cout << solve() << '\n';
 
  return EXIT_SUCCESS;
}