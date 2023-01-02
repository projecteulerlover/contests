#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int64_t x;
  cin >> n >> x;
  vector<int64_t> as(n);
  for (int i = 0; i < n; ++i) cin >> as[i];
  unordered_map<int64_t, pair<int, int>> vs;
  for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j) vs[as[i] + as[j]] = {i, j};
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      const auto& itr = vs.find(x - as[i] - as[j]);
      if (itr == vs.end()) {
        continue;
      }
      if (i != itr->second.first && i != itr->second.second &&
          j != itr->second.first && j != itr->second.second) {
        cout << i + 1 << ' ' << j + 1 << ' ' << itr->second.first + 1 << ' '
             << itr->second.second + 1 << '\n';
        return EXIT_SUCCESS;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
  return EXIT_SUCCESS;
}