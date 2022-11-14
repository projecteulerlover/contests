#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 998244353;

int64_t pow_mod(int64_t b, int64_t p) {
  int64_t res = 1;
  while (p) {
    if (p & 1) res = res * b % mod;
    b = b * b % mod;
    p /= 2;
  }
  return res;
}

int64_t g(int64_t x) {
  return (x % mod + mod) % mod;
}

int main() {
  int T;
  int64_t m, n;
  cin >> T;
  while (T--) {
    cin >> n >> m;
    int64_t res = 0;
    ++m;
    for (int i=0; i<31; ++i) {
      int64_t c = (m >> (i+1)) << i;
      if ((m >> i) & 1) c += m & ((1 << i) - 1);
      res = g(res + g(pow_mod(c, n) * (1 << i)));
    }
    cout << res << '\n';
  }
  return 0;
}
