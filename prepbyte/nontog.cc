#include <bits/stdc++.h>
using namespace std;

int64_t n;

int main() {
  cin >> n;
  vector<int64_t> as(n);
  for (int i=0; i<n; ++i) cin >> as[i];
  int64_t msf = 1e18;
  // + - case
  {
    int64_t t = 0, ps = 0;
    for (int i=0; i<n; ++i) {
      ps += as[i];
      if (i % 2) {
        if (ps < 0) continue;
        t += ps + 1;
        ps = -1;
      } else {
        if (ps > 0) continue;
        t += abs(ps + 1);
        ps = 1;
      }
    }
    msf = min(msf, t);
  }
  {
    int64_t t = 0, ps = 0;
    for (int i=0; i<n; ++i) {
      ps += as[i];
      if (i % 2 == 0) {
        if (ps < 0) continue;
        t += ps + 1;
        ps = -1;
      } else {
        if (ps > 0) continue;
        t += abs(ps + 1);
        ps = 1;
      }
    }
    msf = min(msf, t);
  }
  cout << msf << '\n';

  return 0;
}