#include <bits/stdc++.h>

using namespace std;

int n;

int solve() {
  cin >> n;
  vector es(n, vector<int>());
  int u, v;
  for (int i = 0; i < n; ++i) {
    cin >> u >> v;
    --u, --v;
    es[u].push_back(v), es[v].push_back(u);
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  solve();

  return EXIT_SUCCESS;
}