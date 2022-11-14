#include <bits/stdc++.h>
using namespace std;

int T;

/*

1 -1 2 1 5

1
5
1 -2 3 -2 4

*/

template <typename T>
void PrintVec(const vector<T>& vs) {
  for (const auto& v : vs) cout << v << ' ';
  cout << '\n';
}

int main() {
  cin >> T;
  for (int t=1; t<=T; ++t) {
    int n, c = 0;
    cin >> n;
    vector<int> as(n);
    for (int i=0; i<n; ++i) cin >> as[i];
    for (int i=1; i<n; ++i) as[i] += as[i-1];
    PrintVec(as);
    for (int i=0; i<n;) {
      if (as[i] < 0) {
        ++i;
        continue;
      }
      int j=i;
      while (j<n && as[j] >= 0) {
        c += as[j] - (i == 0 ? 0 : as[i-1]);
        cout << i << ' ' << j << '\n';
        ++j;
      }
      i = j;
    }
    cout << "Case #" << t << ": " << c << '\n';
  }

  return 0;
}