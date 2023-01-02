#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1e9 + 7;

int n;

void exponentiation() {
  int64_t a, t = 1;
  int b;
  cin >> a >> b;
  while (b) {
    if (b % 2) t = t * a % kMod;
    a = a * a % kMod;
    b /= 2;
  }
  cout << t << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  for (int i=0; i<n; ++i) exponentiation();

  return EXIT_SUCCESS;
}