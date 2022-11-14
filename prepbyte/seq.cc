#include <bits/stdc++.h>
using namespace std;

int n;
constexpr int kMod = 1e9+7;

int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  // 0        1  2  3
  // neither, 9, both
  vector<vector<int64_t>> dp(2, vector<int64_t>(4));
  dp[0][0] = 1;
  int p = 0, c = 1;
  for (int i=1; i<=n; ++i) {
    dp[c][0] = 8 * dp[p][0] % kMod;
    dp[c][1] = (dp[p][0] + dp[p][1] * 9) % kMod;
    dp[c][2] = (dp[p][0] + dp[p][2] * 9) % kMod;
    dp[c][3] = (10 * dp[p][3] + dp[p][1] + dp[p][2]) % kMod;
    p ^= 1, c ^= 1;
  }
  cout << dp[p].back() << endl;
  int t = 0;
  for (int w=0; w<10; ++w)
    for (int x=0; x<10; ++x)
      for (int y=0; y<10; ++y)
        for (int z=0; z<10; ++z) {
          vector<bool> ds(10);
          ds[x] = true, ds[y] = true, ds[z] = true, ds[w] = true;
          t += ds[0] && ds[9];
        }
  cout << t << endl;
  return 0;
}