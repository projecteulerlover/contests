#include <bits/stdc++.h>

using namespace std;

int solve() {
  int n;
  cin >> n;
  vector<int> xs(n);
  for (int i = 0; i < n; ++i) cin >> xs[i];
  vector<int> dp;
  for (int x : xs) {
    auto itr = lower_bound(dp.begin(), dp.end(), x);
    if (itr == dp.end()) dp.push_back(x);
    else *itr = x;
  }
  return dp.size();
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cout << solve() << '\n';

  return EXIT_SUCCESS;
}