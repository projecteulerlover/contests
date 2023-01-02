#include <bits/stdc++.h>

using namespace std;

int n, x;
  
vector<int> GetSubsetSums(const vector<int>& nums) {
  vector<int> subset_sums = {0};
  for (int i : nums) {
    int n = subset_sums.size();
    for (int j = 0; j < n; ++j) {
      int64_t t = subset_sums[j] + i;
      if (t > x) continue;
      subset_sums.push_back(t);
    }
  }
  return subset_sums;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> x;

  vector<int> l(n / 2), r(n - n / 2);
  for (int i = 0; i < n / 2; ++i) cin >> l[i];
  for (int i = n / 2; i < n; ++i) cin >> r[i - n / 2];
  auto left_sums = GetSubsetSums(l), right_sums = GetSubsetSums(r);
  map<int, int> counter;
  for (int i : right_sums) ++counter[i];
  int64_t count = 0;
  for (int i : left_sums) {
    const auto& itr = counter.find(x-i);
    count += itr == counter.end() ? 0 : counter[x-i];
  }
  cout << count << '\n';
  return EXIT_SUCCESS;
}