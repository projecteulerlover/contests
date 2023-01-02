#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using sorted_list = tree<pair<int, size_t>, null_type, less<pair<int, int>>,
                         rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  size_t n, k;
  cin >> n >> k;
  sorted_list sl;
  vector<int64_t> xs(n);
  int64_t res;
  for (size_t i = 0; i < n; ++i) {
    cin >> xs[i];
    sl.insert({xs[i], i});
    if (i >= k) sl.erase(sl.lower_bound({xs[i - k], 0}));
    if (i >= k - 1) cout << sl.find_by_order((k - 1) / 2)->first << ' ';
  }
  cout << '\n';
  return EXIT_SUCCESS;
}