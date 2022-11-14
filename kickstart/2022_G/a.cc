#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
  cin >> T;
  for (int t=1; t<=T; ++t) {
    int m, n, p;
    cin >> m >> n >> p;
    --p;
    vector<vector<int>> s(m, vector<int>(n));
    for (int i=0; i<m; ++i)
      for (int j=0; j<n; ++j)
        cin >> s[i][j];
    vector<int> ms(n, INT_MIN);
    for (int i=0; i<m; ++i) {
      if (i == p) continue;
      for (int j=0; j<n; ++j) {   
        ms[j] = max(ms[j], s[i][j]);
      }
    }
    int c = 0;
    for (int i=0; i<n; ++i)
      c += max(0, ms[i] - s[p][i]);

    cout << "Case #" << t << ": " << c << '\n';
  }

  return 0;
}