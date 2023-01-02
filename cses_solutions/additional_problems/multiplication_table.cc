#include <bits/stdc++.h>
    
using namespace std;
 
int64_t n, x;
 
bool ok(int64_t g) {
  int64_t t = 0;
  for (int a = 1; a <= n; ++a) {
    t += min(n, g / a);
  }
  return t < x;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  x = (n * n + 1) / 2;
  int64_t l = 1, r = n * n;
  while (l < r) {
    auto m = l + (r - l) / 2;
    if (ok(m)) l = m + 1;
    else r = m;
  }
  cout << l << '\n';
  return EXIT_SUCCESS;
}