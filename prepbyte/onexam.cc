#include <bits/stdc++.h>
using namespace std;

int main() {
  double n;
  cin >> n;
  /*
  (1+x)*x / 2 >= n
  x^2 + x >= 2n
  4x^2+4x+1 >= 8n + 1
  (2x + 1)^2 >= 8n + 1
  
  .5 * (sqrt(8n+1)-1)
  */
  cout << ceil(.5 * (pow(8*n+1, .5) - 1)) << '\n';
  return 0;
}