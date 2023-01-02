#include <bits/stdc++.h>

using namespace std;

int n, q, r1, r2, c1, c2;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> q;
  string s;
  vector<vector<int>> ps(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < n; ++j)
      ps[i][j] = (i > 0 ? ps[i - 1][j] : 0) + (j > 0 ? ps[i][j - 1] : 0) -
                 (i > 0 && j > 0 ? ps[i - 1][j - 1] : 0) + (s[j] == '*');
  }
  for (int i = 0; i < q; ++i) {
    cin >> r1 >> c1 >> r2 >> c2;
    r1 -= 2, --r2, c1 -= 2, --c2;
    cout << ps[r2][c2] - (r1 >= 0 ? ps[r1][c2] : 0) -
                (c1 >= 0 ? ps[r2][c1] : 0) +
                (r1 >= 0 && c1 >= 0 ? ps[r1][c1] : 0)
         << '\n';
  }

  return EXIT_SUCCESS;
}