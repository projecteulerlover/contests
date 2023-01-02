#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;
constexpr int kMax = 1e6 + 1;

int n;
vector<int64_t> fs(kMax, 1);

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
  return fs[a] * exponentiation(fs[b], kMod - 2) % kMod *
         exponentiation(fs[a - b], kMod - 2) % kMod;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  int a, b;
  for (int i = 1; i < kMax; ++i) fs[i] = fs[i - 1] * i % kMod;
  for (int i = 0; i < n; ++i) {
    cin >> a >> b;
    cout << aChooseb(a, b) << '\n';
  }

  return EXIT_SUCCESS;
}