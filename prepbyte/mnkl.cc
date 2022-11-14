#include <bits/stdc++.h>
using namespace std;

int n;

/*
8
4 7 7 10 10 10 11 11
*/

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vs) {
  for (const auto& v : vs) os << v << ' ';
  os << '\n';
  return os;
}

int main() {
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
    --h[i];
  }
  sort(h.rbegin(), h.rend());
  int z = 0;
  while (z < n && h[z] >= z) ++z;
  --z;
  if (h[z] == z) {
    if (z+1 == n || h[z+1] < h[z]) {
      cout << "Second\n";
      return 0;
    }
    int zc = z;
    while (zc < n && h[zc] == h[z]) ++zc;
    int dz = zc - z - 1;
    cout << (dz % 2 ? "First\n" : "Second\n");
    return 0;
  }
  if (h[z] > z && (z == n-1 || h[z+1] < z)) {
    int dz = h[z] - z;
    cout << (dz % 2 ? "First\n" : "Second\n");
    return 0;
  }
  int dy = h[z] - z;
  int zc = z;
  while (zc < n && h[zc] == z) ++zc;
  int dx = zc - z - 1;
  cout << (dx % 2 == 0 && dy % 2 == 0 ? "Second\n" : "First\n");
  return 0;

  // sort(h.begin(), h.end());
  // int p = -1;
  // vector<pair<int, int>> rectangles = {{-1, -1}};
  // for (int i=0; i<n;) {
  //   int j = i;
  //   while (j<n && h[j] == h[i]) ++j;
  //   rectangles.emplace_back(j-1, h[i] - p);
  //   p = h[i];
  //   i = j;
  // }

  // int x = n-1;
  // for (; x>=0; --x) {
  //   if (h[x] < n-x-1) {
  //     ++x;
  //     break;
  //   }
  // }
}