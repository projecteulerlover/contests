#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
  int64_t x, msf = -1e18, cs = 0;
  cin >> n;
  for (int i=0; i<n; ++i) {
    cin >> x;
    msf = max(msf, cs += x);
    if (cs < 0) cs = 0;
  }
  cout << msf << '\n';
}