#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using sorted_list =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, x;
  cin >> n;
  vector<int> dp;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    auto itr = upper_bound(dp.begin(), dp.end(), x);
    if (itr == dp.end())
      dp.push_back(x);
    else
      *itr = x;
  }
  cout << dp.size() << '\n';
  return EXIT_SUCCESS;
}