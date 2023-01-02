#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n;
  vector<int64_t> xs(n);
  for (int i=0; i<n; ++i) cin >> xs[i];
  sort(xs.begin(), xs.end());
  int64_t msf = 0;
  for (int x : xs) {
    if (x - 1 > msf) break;
    msf += x;
  }
  cout << msf + 1 << '\n';
  return EXIT_SUCCESS;
}