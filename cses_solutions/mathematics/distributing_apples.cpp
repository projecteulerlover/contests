#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;
constexpr int kMax = 1e6 + 1;

int64_t exponentiation(int64_t a, int b) {
  int64_t t = 1;
  while (b) {
    if (b % 2) t = t * a % kMod;
    a = a * a % kMod;
    b /= 2;
  }
  return t;
}

int aChooseb(int a, int b) {
  b = min(b, a - b);
  int64_t nu = 1, de = 1;
  for (int i = a - b + 1; i <= a; ++i) nu = nu * i % kMod;
  for (int i = 2; i <= b; ++i) de = de * i % kMod;
  return nu * exponentiation(de, kMod - 2) % kMod;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int a, b;
  cin >> a >> b;
  cout << aChooseb(a + b - 1, a - 1) << '\n';

  return EXIT_SUCCESS;
}