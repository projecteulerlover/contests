#include <bits/stdc++.h>

using namespace std;

int n;
int x;
vector<int> as;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n;
  as.resize(n);
  for (int i = 0; i < n; ++i) cin >> as[i];
  vector<int> counter(n, 0);
  counter[0] = 1;
  int c = 0;
  int64_t t = 0;
  for (int a : as) {
    c = ((c + a) % n + n) % n;
    t += counter[c];
    ++counter[c];
  }
  cout << t << '\n';
  return EXIT_SUCCESS;
}