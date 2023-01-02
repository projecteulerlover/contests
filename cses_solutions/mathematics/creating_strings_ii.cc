#include <bits/stdc++.h>

using namespace std;

string s;

constexpr int mod = 1e9 + 7;

int64_t pow_mod(int64_t b, int64_t p) {
  int64_t res = 1;
  while (p) {
    if (p & 1) res = res * b % mod;
    b = b * b % mod;
    p >>= 1;
  }
  return res;
}

vector<int64_t> fac_mod() {
  int n = s.size();
  vector<int64_t> res(n+1, 1);
  for (int i=1; i<=n; ++i)
    res[i] = res[i-1] * i % mod;
  return res;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> s;
  vector<int> fs(26);
  for (char c : s) ++fs[c - 'a'];
  vector<int64_t> fm = fac_mod();
  int64_t res = fm.back();
  for (int64_t x : fs)
    if (x > 1) res = res * pow_mod(fm[x], mod - 2) % mod;
  cout << (res % mod + mod) % mod << '\n';
  return EXIT_SUCCESS;
}