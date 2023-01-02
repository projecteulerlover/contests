#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int n;

/*
a**(p-1) == 1 mod p 
*/

int64_t exponentiation(int64_t a, int b, int mod) {
  int64_t t = 1;
  while (b) {
    if (b % 2) t = t * a % mod;
    a = a * a % mod;
    b /= 2;
  }
  return t;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  int64_t a, b;
  int c;
  
  for (int i=0; i<n; ++i) {
    cin >> a >> b >> c;
    int p = exponentiation(b, c, kMod - 1);
    cout << exponentiation(a, p, kMod) << '\n';
  }
  return EXIT_SUCCESS;
}