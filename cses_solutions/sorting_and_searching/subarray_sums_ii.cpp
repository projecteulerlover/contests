#include <bits/stdc++.h>

using namespace std;

int n;
int64_t x;
vector<int> as;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> n >> x;
  as.resize(n);
  for (int i = 0; i < n; ++i) cin >> as[i];
  map<int64_t, int> counter = {{0LL, 1}};
  int64_t c = 0;
  int64_t t = 0;
  for (int a : as) {
    c += a;
    // c - y = x => y = c - x
    t += counter[c - x];
    ++counter[c];
  }
  cout << t << '\n';
  return EXIT_SUCCESS;
}