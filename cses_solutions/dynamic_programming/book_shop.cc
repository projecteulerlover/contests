#include <bits/stdc++.h>
 
using namespace std;
 
int n;
 
int solve() {
  int n, x;
  cin >> n >> x;
  vector<int> hs(n), ss(n);
  for (int i=0; i<n; ++i) cin >> hs[i];
  for (int i=0; i<n; ++i) cin >> ss[i];
  vector dp(n+1, vector(x+1, 0));
  for (int i=1; i<=n; ++i) {
    for (int j=1; j<=x; ++j) {
      dp[i][j] = dp[i-1][j];
      if (j >= hs[i-1])
        dp[i][j] = max(dp[i][j], dp[i-1][j-hs[i-1]] + ss[i-1]);
    }
  }
  return dp[n][x];
}
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << solve() << '\n';
 
  return EXIT_SUCCESS;
}