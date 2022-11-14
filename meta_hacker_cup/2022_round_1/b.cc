#include <bits/stdc++.h>
using namespace std;

int T, N, Q;
int kMod = 1e9+7;

/*
1
2
2 2
5 5
2
2 5
6 6
*/

int main() {
  cin >> T;
  for (int c = 1; c <= T; ++c) {
    cin >> N;
    // cout << c << " N read\n";
    vector<int64_t> t_x(N), t_y(N);
    for (int i=0; i<N; ++i)
      cin >> t_x[i] >> t_y[i];
    cin >> Q;
    // cout << c << " Q read\n";
    vector<int64_t> q_x(Q), q_y(Q);
    for (int i=0; i<Q; ++i)
      cin >> q_x[i] >> q_y[i];
    // cout << c << " arrays constructed\n";
    int64_t total = 0;
    int64_t t_x_squared = 0, t_y_squared = 0;
    int64_t t_x_sum = 0, t_y_sum = 0;
    // cout << c << " nums read\n";
    for (int64_t t : t_x) {
      t_x_squared = (t_x_squared + (t * t % kMod)) % kMod;
      t_x_sum = (t_x_sum + t) % kMod;
    }
    for (int64_t t : t_y) {
      t_y_squared = (t_y_squared + (t * t % kMod)) % kMod;
      t_y_sum = (t_y_sum + t) % kMod;
    }
    for (int64_t q : q_x) {
      total = (total + t_x_squared - (2 * q * t_x_sum % kMod) + ((q * q % kMod) * N) % kMod) % kMod;
    }
    for (int64_t q : q_y) {
      total = (total + t_y_squared - (2 * q * t_y_sum % kMod) + ((q * q % kMod) * N) % kMod) % kMod;
    }
    total = (total + kMod) % kMod;
    cout << "Case #" << c << ": " << total << '\n';
  }
  
  return 0;
}
/*

010 011 100
         11
010 011 011
001 011 011
*/