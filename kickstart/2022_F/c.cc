#include <bits/stdc++.h>
using namespace std;

int64_t T, D, N, X;

int main() {
  cin >> T;
  for (int t=1; t<=T; ++t) {
    cin >> D >> N >> X;
    // profit, maturity, quantity 
    vector<array<int64_t, 3>> seeds(N);
    for (int i=0; i<N; ++i)
      cin >> seeds[i][2] >> seeds[i][1] >> seeds[i][0];
    sort(seeds.begin(), seeds.end(), [](const auto& a, const auto& b) {
      return a[1] < b[1];
    };
    priority_queue<array<int64_t, 3>, vector<array<int64_t, 3>>> pq;
    for (int i=0; i<N;) {
      int j=i+1;
      pq.push(seeds[i]);
      while (j<N && seeds[j][1] == seeds[i][1]) {
        pq.push(seeds[j]);
        ++j;
      }
      

    }
    cout << "Case #" << t << ": " << res << '\n';
  }

  return 0;
}