#include <bits/stdc++.h>
    
using namespace std;
 
int n, x, N = 1e6;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<bool> dp(N+1, false);
  vector<int> ds(N+1, 1);
  dp[1] = true, dp[0] = true;
  for (int p=2; p<=sqrt(N); ++p) {
    if (dp[p]) continue;
    for (int q = 2 * p; q <= N; q += p) {
      int r = q, c = 1;
      while (r % p == 0) ++c, r /= p;
      ds[q] *=  c;
      dp[q] = true;
    }
    ds[p] = 2;
  }
  for (int p=sqrt(N)+1; p<=N; ++p) if (!dp[p]) {
    for (int q = 2 * p; q <= N; q += p) {
      int r = q, c = 1;
      while (r % p == 0) ++c, r /= p;
      ds[q] *=  c;
    }
    ds[p] = 2;
  }
  for (int i=0; i<n; ++i) {
    cin >> x;
    cout << ds[x] << '\n';
  }

  return EXIT_SUCCESS;
}