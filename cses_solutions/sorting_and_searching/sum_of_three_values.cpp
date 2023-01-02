#include <bits/stdc++.h>

using namespace std;

int n, x;
vector<pair<int64_t, int>> as;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> x;
  as.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> as[i].first;
    as[i].second = i + 1;
  }
  sort(as.begin(), as.end());
  for (int i = 0; i < n - 2; ++i) {
    int l = i + 1, r = n - 1;
    while (l < r) {
      int64_t t = as[i].first + as[l].first + as[r].first;
      if (t > x)
        --r;
      else if (x > t)
        ++l;
      else {
        cout << as[i].second << ' ' << as[l].second << ' ' << as[r].second
             << '\n';
        return EXIT_SUCCESS;
      }
    }
  }
  cout << "IMPOSSIBLE\n";
  return EXIT_SUCCESS;
}