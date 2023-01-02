#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> p, s;

int ds_find(int i) {
  if (i == p[i]) return i;
  return p[i] = ds_find(p[i]);
}

bool ds_join(int i, int j) {
  int pi = ds_find(i), pj = ds_find(j);
  if (pi != pj) {
    if (s[pi] < s[pj]) swap(pi, pj);
    p[pj] = pi;
    s[pi] += s[pj];
    return true;
  }
  return false;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> m;
  p = vector<int>(n, 0), s = vector<int>(n, 1);
  iota(p.begin(), p.end(), 0);

  int a, b, cc = n, cs = 1;
  for (int i=0; i<m; ++i) {
    cin >> a >> b;
    --a, --b;
    if (ds_join(a, b)) {
      --cc;
      cs = max(cs, max(s[ds_find(a)], s[ds_find(b)]));
    }
    cout << cc << ' ' << cs << '\n';
  }

  return EXIT_SUCCESS;
}