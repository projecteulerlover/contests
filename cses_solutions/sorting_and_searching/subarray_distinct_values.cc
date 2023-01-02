#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

using namespace __gnu_pbds;

size_t n, k;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  vector<int64_t> xs(n);
  for (size_t i = 0; i < n; ++i) cin >> xs[i];
  int64_t res = 0;
  size_t l = 0;
  unordered_map<int, int> fs;
  for (size_t r = 0; r < n; ++r) {
    ++fs[xs[r]];
    while (fs.size() > k) {
      if (--fs[xs[l]] == 0) fs.erase(xs[l]);
      ++l;
    }
    res += r - l + 1;
  }
  cout << res << '\n';

  return EXIT_SUCCESS;
}