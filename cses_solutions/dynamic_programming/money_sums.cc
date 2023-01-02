#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> xs(n);
  for (int i = 0; i < n; ++i) cin >> xs[i];
  int t = accumulate(xs.begin(), xs.end(), 0);
  vector dp(n + 1, vector<bool>(t + 1));
  dp[0][0] = true;
  for (int j=1; j<=n; ++j) {
    int c = xs[j-1];
    for (int i = 0; i <= t; ++i) {
      dp[j][i] = dp[j-1][i] || (i - c >= 0 && dp[j-1][i - c]);
    }
  }
  cout << accumulate(dp[n].begin() + 1, dp[n].end(), 0) << '\n';
  for (int i = 1; i <= t; ++i)
    if (dp[n][i]) cout << i << ' ';
  cout << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();

  return EXIT_SUCCESS;
}