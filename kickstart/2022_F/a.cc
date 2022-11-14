#include <bits/stdc++.h>
using namespace std;

int64_t T, N;

int main() {
  cin >> T;
  for (int t=1; t<=T; ++t) {
    cin >> N;
    vector<tuple<string, int, int>> vs(N);
    for (int i=0; i<N; ++i) {
      cin >> get<0>(vs[i]) >> get<1>(vs[i]) >> get<2>(vs[i]);
    }
    auto ws(vs);
    sort(vs.begin(), vs.end(), [](const auto& a, const auto& b) {
      if (get<0>(a) == get<0>(b))
        return get<2>(a) < get<2>(b);
      return get<0>(a) < get<0>(b);
    });
    sort(ws.begin(), ws.end(), [](const auto& a, const auto& b) {
      if (get<1>(a) == get<1>(b))
        return get<2>(a) < get<2>(b);
      return get<1>(a) < get<1>(b);
    });
    int c = 0;
    for (int i=0; i<N; ++i) c += vs[i] == ws[i];
    cout << "Case #" << t << ": " << c << '\n';
  }

  return 0;
}