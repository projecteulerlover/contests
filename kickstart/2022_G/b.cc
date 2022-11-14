#include <bits/stdc++.h>
using namespace std;

int T;

int main() {
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int rs, rh, n, m;
    cin >> rs >> rh;
    cin >> n;
    vector<int> as, bs;
    for (int i = 0; i < n; ++i) {
      int x, y;
      cin >> x >> y;
      if (pow(x, 2) + pow(y, 2) <= pow(rs + rh, 2)) {
        as.push_back(pow(x, 2) + pow(y, 2));
      }
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      if (pow(x, 2) + pow(y, 2) <= pow(rs + rh, 2)) {
        bs.push_back(pow(x, 2) + pow(y, 2));
      }
    }
    sort(as.begin(), as.end(),
         [](const auto& a, const auto& b) { return a < b; });
    sort(bs.begin(), bs.end(),
         [](const auto& a, const auto& b) { return a < b; });
    int a = 0, b = 0;
    if (bs.empty()) {
      a = as.size();
    } else {
      for (int i = 0; i < as.size(); ++i) {
        if (as[i] < bs[0]) {
          ++a;
        } else {
          break;
        }
      }
    }
    if (as.empty()) {
      b = bs.size();
    } else {
      for (int i = 0; i < bs.size(); ++i) {
        if (bs[i] < as[0]) {
          ++b;
        } else {
          break;
        }
      }
    }
    cout << "Case #" << t << ": " << a << ' ' << b << '\n';
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