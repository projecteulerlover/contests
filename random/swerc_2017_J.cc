#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  cin >> n;
  vector<int64_t> as(n+1), bs(n+1), tr(3), res(3);
  for (int i=1; i<=n; ++i) {
    cin >> bs[i];
    tr[i % 3] += bs[i];
  }
  for (int i=1; i<=n; ++i) cin >> as[i];
  
  int offset = 0;
  for (int j=1; j<=n; ++j) {
    res[(j+offset) % 3] += tr[offset % 3] * as[j]; 
    res[(j+offset+1) % 3] += tr[(offset+1) % 3] * as[j]; 
    res[(j+offset+2) % 3] += tr[(offset+2) % 3] * as[j];
    offset = (offset + 2) % 3;
  }
  cout << res[0] << ' ' << res[1] << ' ' << res[2] << '\n';
  return 0;
}