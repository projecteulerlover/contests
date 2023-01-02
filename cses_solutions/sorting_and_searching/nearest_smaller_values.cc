#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using sorted_list =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  vector<int> st, vs(n);
  for (int i=0; i<n; ++i) {
    cin >> vs[i];
    while (!st.empty() && vs[st.back()] >= vs[i]) st.pop_back();
    cout << (st.empty() ? 0 : st.back() + 1) << ' ';
    st.push_back(i);
  }
  
  return EXIT_SUCCESS;
}