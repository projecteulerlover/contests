#include <bits/stdc++.h>
using namespace std;

int64_t T, N, Q;

vector<int> bfs(vector<vector<int>>& g) {
  vector<int> ps;
  vector<int> f = {0};
  vector<bool> vs(N);
  vs[0] = true;
  while (!f.empty()) {
    vector<int> n;
    ps.push_back(f.size() + (ps.empty() ? 0 : ps.back()));  
    for (int u : f) {
      for (int v : g[u]) {
        if (vs[v]) continue;
        vs[v] = true;
        n.push_back(v);
      }
    }
    swap(n, f);
  }
  return ps;
}

int main() {
  cin >> T;
  for (int t=1; t<=T; ++t) {
    cin >> N >> Q;
    vector<vector<int>> g(N);
    int u, v, q;
    for (int i=0; i<N-1; ++i) {
      cin >> u >> v;
      g[u-1].push_back(v-1);
      g[v-1].push_back(u-1);
    }
    for (int i=0; i<Q; ++i) cin >> q;
    auto res = bfs(g);
    // cout << res.size() << '\n';
    // for (int r : res) cout << r << ' ';
    // cout << '\n';
    int c = *prev(upper_bound(res.begin(), res.end(), Q));
    cout << "Case #" << t << ": " << c << '\n';
  }

  return 0;
}

/*
1
5 2
1 2
5 3
3 1
2 4
4
5
*/