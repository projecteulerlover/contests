#include <bits/stdc++.h>
using namespace std;

int64_t n, x = 0, y = 0, s = 0, a, b;

/*
a <= A <= b <=> s-a >= B >= s-b

Alice losing <=> Bob forcing: B > s-a || B < s - b


*/

int main() {
  cin >> n >> a >> b;
  vector<int64_t> vs(n);
  for (int i = 0; i < n; ++i) {
    cin >> vs[i];
  }
  sort(vs.begin(), vs.end());
  for (int i = 0; i < n; ++i) {
    s += vs[i];
    i % 2 ? y += vs[i] : x += vs[i];
  }
  // a > b after this
  a = s - a, b = s - b;

  cout << ((y < b || x > a) ? "Alpha" : "Beta") << '\n';
  return 0;
}