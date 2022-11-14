#include <bits/stdc++.h>
using namespace std;

constexpr int64_t kMod = 998244353; 

int main() {
  int64_t t, n, x;
  cin >> t;
  while (t--) {
    cin >> n >> x;
    for (int64_t y=0; y<x; ++y) {
      int64_t total = 0, j = 0;
      int z = y;
      for (int64_t i=1LL; i<=n; ++i) {
        z = z/i * i + i;
        if (z/i  == i && z/i * i == z) {
          j = i;
          break;
        }
        // cout << x << endl;
        total = (total + z) % kMod;
      }
     //cout << "starting " << y << endl;
      cout << y+1 << ' ' << j << '\n';
      //cout << "total " << total << endl;
    }

    // cout << '\n';
    // int64_t N = (n % 2) ? (n+2) % kMod : (n/2 + 1) % kMod;
    // int64_t M = (n % 2) ? (n-1)/2 % kMod : (n-1) % kMod;
    // total = (total + N * M % kMod) % kMod;
    // cout << total << '\n';
  }

  
  return 0;
}

/*

1
1000000000000000000
1000000000000000000

4
5 100
1 10
10 1
100 100

1
5 100


*/