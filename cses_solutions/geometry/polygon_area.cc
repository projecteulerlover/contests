#include <bits/stdc++.h>
    
using namespace std;
 
int64_t n, a;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int64_t> xs(n), ys(n);
  for (int i=0; i<n; ++i) cin >> xs[i] >> ys[i];
  for (int i=0; i<n; ++i)
    a += xs[i] * ys[(i+1) % n] - ys[i] * xs[(i+1) % n];
  cout << abs(a) << endl;
  return EXIT_SUCCESS;
} 