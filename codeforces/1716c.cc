#include <bits/stdc++.h>

using namespace std;

int T, m;
array<array<int64_t, 200000>, 2> as;

int64_t helper(int s, int64_t t) {
  for (int i = s; i < m; ++i) {
    t = i == 0 ? 0 : max(t, as[s & 1][i]) + 1;
  }
  for (int i = m - 1; i >= s; --i) {
    t = max(t, as[!(s & 1)][i]) + 1;
  }
  return t;
}

int64_t solve() {
  cin >> m;
  for (int i = 0; i < m; ++i) cin >> as[0][i]; 
  for (int i = 0; i < m; ++i) cin >> as[1][i];
  int64_t t = 0;
  int64_t msf = LLONG_MAX;
  for (int i = 0; i < m; ++i) {
    msf = min(msf, helper(i, t));
    t = i == 0 ? 0 : max(t, as[i & 1][i]) + 1;
    t = max(t, as[!(i & 1)][i]) + 1;
  }
  msf = min(msf, t);
  return msf;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> T;
  while (T-- > 0) {
    cout << solve() << '\n';
  }

  return EXIT_SUCCESS;
}