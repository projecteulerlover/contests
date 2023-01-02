#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int64_t n;
  cin >> n;
  int64_t a00 = 1, a01 = 1, a10 = 1, a11 = 0;
  int64_t r00 = 1, r01 = 0, r10 = 0, r11 = 1;
  while (n) {
    if (n % 2) {
      int64_t rc00 = r00, rc01 = r01, rc10 = r10, rc11 = r11;
      r00 = rc00 * a00 % mod + rc01 * a10 % mod;
      r01 = rc00 * a01 % mod + rc01 * a11 % mod;
      r10 = rc10 * a00 % mod + rc11 * a10 % mod;
      r11 = rc10 * a01 % mod + rc11 * a11 % mod;
      r00 %= mod, r01 %= mod, r10 %= mod, r11 %= mod;
    }
    int64_t ac00 = a00, ac01 = a01, ac10 = a10, ac11 = a11;
    a00 = ac00 * ac00 % mod + ac01 * ac10 % mod;
    a01 = ac00 * ac01 % mod + ac01 * ac11 % mod;
    a10 = ac10 * ac00 % mod + ac11 * ac10 % mod;
    a11 = ac10 * ac01 % mod + ac11 * ac11 % mod;
    a00 %= mod, a01 %= mod, a10 %= mod, a11 %= mod;
    n /= 2;
  }
  cout << r01 % mod << '\n';
  return EXIT_SUCCESS;
}