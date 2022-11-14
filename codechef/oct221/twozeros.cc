#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

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
  int64_t inv_3 = g(pow_mod(3, mod - 2));
  int64_t inv_2 = g(pow_mod(2, mod - 2));

  vector<int64_t> cs = {1, inv_2, -inv_2, -1, -inv_2, inv_2};
  vector<int64_t> ds = {-inv_2, inv_2, 1, inv_2, -inv_2, -1};
  vector<int64_t> es = {-inv_2, -1, -inv_2, inv_2, 1, inv_2};
  while (T--) {
    cin >> n >> m;

    int64_t two_power_m = pow_mod(2, m);
    int64_t m0 = g(inv_3 * ((two_power_m + 2 * cs[m % 6]) % mod));
    int64_t m1 = g(inv_3 * (g(two_power_m + 2 * ds[m % 6] % mod)) % mod);
    int64_t m2 = g(inv_3 * (g(two_power_m + 2 * es[m % 6] % mod)) % mod);
    
    int64_t two_power_n = pow_mod(2, n);
    int64_t n0 = g(inv_3 * ((two_power_n + 2 * cs[n % 6]) % mod));
    int64_t n1 = g(inv_3 * (g(two_power_n + 2 * ds[n % 6] % mod)) % mod);
    int64_t n2 = g(inv_3 * (g(two_power_n + 2 * es[n % 6] % mod)) % mod);
    // cout << g(m0) << ' ' << g(m1) << ' ' << g(m2) << ' ' << g(n0) << ' ' << g(n1) << ' ' << g(n2) << '\n';
    int64_t res = g((m0 * n0 % mod) + (m1 * n1 % mod) + (m2 * n2 % mod) - 1);
    cout << res << '\n';
  }
  return 0;
}
