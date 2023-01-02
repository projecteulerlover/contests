#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> xs;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> k;
  string s;
  xs.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < k; ++j) {
      xs[i] <<= 1;
      xs[i] += s[j] - '0';
    }
  }
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      k = min(k, __builtin_popcount(xs[i] ^ xs[j]));
  cout << k << '\n';
  return EXIT_SUCCESS;
}
