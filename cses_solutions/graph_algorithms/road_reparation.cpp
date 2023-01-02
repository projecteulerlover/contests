#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> p;

int ds_find(int i) {
  if (i == p[i]) return i;
  return p[i] = ds_find(p[i]);
}

bool ds_join(int i, int j) {
  int pi = ds_find(i), pj = ds_find(j);
  if (pi != pj) {
    p[pj] = pi;
    return true;
  }
  return false;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m;
  p = vector<int>(n, 0);
  iota(p.begin(), p.end(), 0);

  vector<tuple<int, int, int>> e(m);
  int64_t t = 0;
  int ec = 0;
  for (int i = 0; i < m; ++i)
    cin >> get<0>(e[i]) >> get<1>(e[i]) >> get<2>(e[i]);
  sort(e.begin(), e.end(),
       [](const auto& e1, const auto& e2) { return get<2>(e1) < get<2>(e2); });
  for (int i = 0; i < m; ++i) {
    auto& [a, b, c] = e[i];
    if (ds_join(--a, --b)) {
      t += c;
      if (++ec == n - 1) break;
    }
  }
  cout << (ec == n - 1 ? to_string(t) : "IMPOSSIBLE") << '\n';

  return EXIT_SUCCESS;
}