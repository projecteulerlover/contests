#include <bits/stdc++.h>
 
using namespace std;
 
int n;
 
int solve() {
  vector<int> dp(n + 1, INT_MAX);
  dp[0] = 0;
  for (int i=1; i<=n; ++i) {
    int x = i;
    while (x) {
      int r = x % 10;
      x /= 10;
      if (r == 0) continue;
      dp[i] = min(dp[i], dp[i-r] + 1);
    }
  }
  return dp[n];
}
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  cout << solve() << '\n';
 
  return EXIT_SUCCESS;
}