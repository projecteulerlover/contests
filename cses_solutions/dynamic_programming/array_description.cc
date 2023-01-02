#include <bits/stdc++.h>

using namespace std;

int n, mod = 1e9 + 7;

int solve() {
  int n, m;
  cin >> n >> m;
  vector<int> xs(n);
  for (int i = 0; i < n; ++i) cin >> xs[i];
  vector dp(n, vector<int64_t>(m + 1, 0LL));
  if (xs[0] == 0)
    for (int i = 1; i <= m; ++i) dp[0][i] = 1;
  else
    dp[0][xs[0]] = 1;
  for (int i = 1; i < n; ++i)
    if (xs[i] != 0)
      for (int j = 1; j <= m; ++j)
        if (j != xs[i]) dp[i][j] = -1;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (dp[i][j] == -1) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = ((j > 1 ? dp[i - 1][j - 1] : 0) + dp[i - 1][j] +
                  (j < m ? dp[i - 1][j + 1] : 0)) %
                 mod;
    }
  }
  return (accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0LL) % mod + mod) % mod;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << solve() << '\n';

  return EXIT_SUCCESS;
}