#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<int> cs;

int solve() {
  vector<int64_t> dp(x + 1, 1e9);
  dp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= x; ++j) {
      if (j - cs[i - 1] >= 0) dp[j] = min(dp[j], dp[j - cs[i - 1]] + 1);
    }
  }
  return dp[x] >= 1e9 ? -1 : dp[x];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> x;
  cs.clear();
  for (int i = 0, j; i < n; ++i) {
    cin >> j;
    cs.push_back(j);
  }
  sort(cs.begin(), cs.end());
  cout << solve() << '\n';

  return EXIT_SUCCESS;
}
