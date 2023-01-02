#include <bits/stdc++.h>

using namespace std;

int64_t solve(vector<vector<int64_t>>& dp, vector<int64_t>& xs, int l, int r) {
  if (l == r) return xs[l];
  if (dp[l][r] == LLONG_MAX) {
    dp[l][r] =
        max(xs[l] - solve(dp, xs, l + 1, r), xs[r] - solve(dp, xs, l, r - 1));
  }
  return dp[l][r];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector dp(n, vector<int64_t>(n, LLONG_MAX));
  vector<int64_t> xs(n);
  for (int i = 0; i < n; ++i) cin >> xs[i];
  int64_t t = accumulate(xs.begin(), xs.end(), 0LL),
          diff = solve(dp, xs, 0, n - 1);
  cout << (t + diff) / 2 << '\n';

  return EXIT_SUCCESS;
}