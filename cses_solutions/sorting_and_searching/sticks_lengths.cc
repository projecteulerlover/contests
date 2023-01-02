#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  cin >> n;
  vector<int64_t> vs(n);
  for (int i=0; i<n; ++i) cin >> vs[i];
  sort(vs.begin(), vs.end());
  int64_t m = vs[vs.size() / 2], res = 0;
  for (int64_t c : vs) res += abs(c - m);
  cout << res << '\n';
}