#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int64_t> xs;

bool helper(int64_t m) {
  int l = 0;
  int64_t c = 0;
  for (int64_t x : xs) {
    if (x > m)
      return false;
    if (c == 0 || c + x > m) {
      ++l;
      c = x;
    } else {
      c += x;
    }
  }
  return l <= k;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> k;
  xs.resize(n);
  int64_t l = 1, r = 0;
  for (int i = 0; i < n; ++i) {
    cin >> xs[i];
    r += xs[i];
  }
  
  while (l < r) {
    int64_t m = l + (r - l) / 2;
    if (helper(m))
      r = m;
    else
      l = m+1;
  }
  cout << l << '\n';

  return EXIT_SUCCESS;
}