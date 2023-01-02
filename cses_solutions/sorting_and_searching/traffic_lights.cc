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
  cin >> x >> n;
  set<int> dp = {0, x};
  map<int, int> fs = {{x, 1}};
  for (int i = 0; i < n; ++i) {
    cin >> x;
    auto itr = dp.insert(x).first;
    auto pre = prev(itr), nxt = next(itr);
    auto fs_itr = fs.find(*nxt - *pre);
    if (--fs_itr->second == 0) fs.erase(fs_itr);
    ++fs[x - *pre], ++fs[*nxt - x];
    cout << fs.rbegin()->first << '\n';
  }
  return EXIT_SUCCESS;
}