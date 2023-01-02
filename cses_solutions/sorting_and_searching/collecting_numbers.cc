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
  int n, res = 0, x;
  cin >> n;
  vector<bool> dp(n);
  for (int i = 0; i < n; ++i) {
    cin >> x;
    if (!dp[x - 1]) ++res;
    dp[x] = true;
  }
  cout << res << '\n';
  return EXIT_SUCCESS;
}