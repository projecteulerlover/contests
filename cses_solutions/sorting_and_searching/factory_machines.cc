#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using sorted_list =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, x;

bool helper(const vector<int64_t>& vs, int64_t m, int64_t x_) {
  for (int i = 0; i < n; ++i)
    if ((x_ -= m / vs[i]) <= 0) return true;
  return false;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> x;
  vector<int64_t> vs(n);
  for (int i = 0; i < n; ++i) cin >> vs[i];
  int64_t mn = *min_element(vs.begin(), vs.end());
  int64_t l = 1, r = mn * x;
  while (l < r) {
    int64_t m = l + (r - l) / 2;
    if (helper(vs, m, x))
      r = m;
    else
      l = m + 1;
  }
  cout << l << '\n';
  return EXIT_SUCCESS;
}