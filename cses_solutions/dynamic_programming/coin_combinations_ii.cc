#include <bits/stdc++.h>

using namespace std;

int n, x, mod = 1e9 + 7;
vector<int> cs;

int solve() {
  vector<int> dp(x + 1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= x; ++j) {
      if (j - cs[i] >= 0) {
        dp[j] += dp[j - cs[i]];
        if (dp[j] > mod) dp[j] -= mod;
      }
    }
  }
  return dp[x];
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> x;
  cs.clear();
  for (int i = 0; i < n; ++i) cin >> cs.emplace_back();
  sort(cs.begin(), cs.end());
  cout << solve() << '\n';

  return EXIT_SUCCESS;
}
