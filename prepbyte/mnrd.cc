#include <bits/stdc++.h>
using namespace std;

int n, y;

int main() {
  cin >> n >> y;
  vector<int64_t> ws(n);
  for (int i=0; i<n; ++i) cin >> ws[i];
  int MASK = 1 << n;
  vector<pair<int, int64_t>> dp(MASK, make_pair(n+1, 0));
  dp[0].first = 1, dp[0].second = 0;
  for (int x=1; x<MASK; ++x) {
    for (int i=0; i<n; ++i) {
      if (x & (1 << i)) {
        pair<int, int64_t> prev = dp[x ^ (1 << i)];
        if (prev.second + ws[i] <= y) {
          prev.second += ws[i];
        } else {
          ++prev.first;
          prev.second = ws[i];
        }
        dp[x] = min(dp[x], prev);
      }
    }
  }
  cout << dp[MASK - 1].first << '\n';

  // sort(h.begin(), h.end());
  // int p = -1;
  // vector<pair<int, int>> rectangles = {{-1, -1}};
  // for (int i=0; i<n;) {
  //   int j = i;
  //   while (j<n && h[j] == h[i]) ++j;
  //   rectangles.emplace_back(j-1, h[i] - p);
  //   p = h[i];
  //   i = j;
  // }

  // int x = n-1;
  // for (; x>=0; --x) {
  //   if (h[x] < n-x-1) {
  //     ++x;
  //     break;
  //   }
  // }
}