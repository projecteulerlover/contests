#include <bits/stdc++.h>
using namespace std;

int64_t n, q, A;
int kMod = 1e9+7;

vector<unordered_map<int, int>> GetDivisors(int A) {
  vector<unordered_map<int, int>> divisors(A+1);
  vector<bool> primes(A+1, true);
  for (int p=2; p<=A; ++p) {
    if (!primes[p])
      continue;
    for (int64_t r=p; r<=A; r*=p) {
      for (int64_t q=r; q<=A; q+=r) {
        ++divisors[q][p];
        primes[q] = false;
      }
    }
  }
  return divisors;
}

int GetCubesModP(int p) {
  vector<bool> cubes(p);
  for (int i=0; i<p; ++i) {
    cout << (i * i % p) * i % p << endl;
    cubes[(i * i % p) * i % p] = true;
  }
  int c = 0;
  for (int i=0; i<p; ++i)
    if (cubes[i]) {
      cout << i << endl;
      ++c;
    }
  return c;
}

int main() {
  // cin >> n >> q;
  // vector<int64_t> as(n);
  // for (int i=0; i<n; ++i) {
  //   cin >> as[i];
  //   A = max(A, as[i]);
  // }
  // vector<unordered_map<int, int>> divisors = GetDivisors(A);
  // for (int i=2; i<=A; ++i) {
  //   cout << "Printing divisor counts for " << i << '\n';
  //   for (const auto& [k, v] : divisors[i])
  //     cout << k << ' ' << v << '\n';
  // }
  cout << "Count: " << GetCubesModP(9) << '\n';
  cout << "Count: " << GetCubesModP(7) << '\n';
  cout << "Count: " << GetCubesModP(11) << '\n';
  cout << "Count: " << GetCubesModP(13) << '\n';


  return 0;
}