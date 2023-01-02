#include <bits/stdc++.h>

using namespace std;

int a, b;
int helper(vector<vector<int>>& dp, int x, int y) {
  if (x == 0 || y == 0) return 0;
  if (x == y) return 1;
  if (dp[x][y] != INT_MAX) return dp[x][y];
  for (int i = 1; i <= min(x, y); ++i) {
    dp[x][y] =
        min(dp[x][y], 1 + min(helper(dp, i, y - i) + helper(dp, x - i, y),
                              helper(dp, x - i, i) + helper(dp, x, y - i)));
  }
  return dp[x][y];
}

int solve() {
  cin >> a >> b;
  vector dp(a + 1, vector<int>(b + 1, INT_MAX));
  return helper(dp, a, b) - 1;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << solve() << '\n';

  return EXIT_SUCCESS;
}