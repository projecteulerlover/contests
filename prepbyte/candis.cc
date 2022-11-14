#include <bits/stdc++.h>
using namespace std;

int n;
int64_t c = 0;

void recurse(vector<int64_t>& as, int l, int r) {
  if (l == r) return;
  int m = *min_element(as.begin()+l, as.begin()+r);
  c += m;
  for (int i=l; i<r; ++i) as[i] -= m;
  for (int x = l; x < r;) {
    while (x < r && as[x] == 0) ++x;
    int y = x;
    while (y < r && as[y] > 0) ++y;
    recurse(as, x, y);
    x = y;
  }
}

int main() {
  cin >> n;
  vector<int64_t> as(n);
  for (int i=0; i<n; ++i) cin >> as[i];
  recurse(as, 0, n);
  cout << c << '\n';

  return 0;
}