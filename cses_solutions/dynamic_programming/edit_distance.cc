#include <bits/stdc++.h>

using namespace std;


int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string a, b;
  cin >> a >> b;
  int m = a.size(), n = b.size();
  vector dp(m+1, vector<int>(n+1));
  for (int i=0; i<=m; ++i) dp[i][0] = i;
  for (int i=0; i<=n; ++i) dp[0][i] = i;
  for (int i=1; i<=m; ++i) {
    for (int j=1; j<=n; ++j) {
      if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
      else
        dp[i][j] = 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
    }
  }
  cout << dp[m][n] << '\n';

  return EXIT_SUCCESS;
}