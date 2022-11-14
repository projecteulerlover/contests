#include <bits/stdc++.h>
using namespace std;

int64_t n;

int64_t solver() {
  vector<int64_t> as(n);
  int64_t t = 0;
  vector<int64_t> cs(63, 0);
  vector<int64_t> last_one(63);
  for (int i=0; i<n; ++i) {
    cin >> as[i];
  }
  for (int64_t a : as) {
    for (int i=0; i<63; ++i)
      if (a & (1LL << i)) {
        ++cs[i];
      }
    for (int i=0; i<63; ++i)
      if (a & (1LL << i)) {
        ++last_one[i];
        break;
      }
  }
  /*
  1 2 1
  2 3         10 11 11
  3 2


  */
  for (int i=62; i>=0; --i) {
    if (cs[i] % 2) {
      if (last_one[i] == 0) {
        return -1;
      }
      --cs[i];
      --last_one[i];
      for (int j=i-1; j>=0; --j) ++cs[j];
      ++t;
    }
  }
  return t;
}

int main() {
  cin >> n;
  cout << solver() << '\n';
  return 0;
}
/*

010 011 100
         11
010 011 011
001 011 011
*/