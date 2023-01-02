#include <bits/stdc++.h>

using namespace std;

vector<int64_t> GetSubsetSums(const vector<int64_t>& nums) {
    vector<unordered_set<int64_t>> subset_sums = {{0LL}, {}};
    int curr = 0, next = 1;
    for (int64_t i : nums) {
        subset_sums[next] = subset_sums[curr];
        for (int64_t j : subset_sums[curr]) {
            subset_sums[next].insert(i+j);
        }
        curr ^= 1, next ^= 1;
    }
    return {subset_sums[curr].begin(), subset_sums[curr].end()};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int64_t> l(n/2), r(n-n/2);
    for (int i=0; i<n/2; ++i)
        cin >> l[i];
    for (int i=n/2; i<n; ++i)
        cin >> r[i-n/2];
    int64_t total = accumulate(l.begin(), l.end(), 0LL) + accumulate(r.begin(), r.end(), 0LL);
    vector<int64_t> left_sums = GetSubsetSums(l), right_sums = GetSubsetSums(r);
    sort(right_sums.begin(), right_sums.end());
    int64_t msf = LONG_LONG_MAX;
    for (int64_t i : left_sums) {
        auto itr = lower_bound(right_sums.begin(), right_sums.end(), total/2 - i);
        if (itr != right_sums.end())
            msf = min(msf, abs(total - 2 * (i + *itr)));
        itr = upper_bound(right_sums.begin(), right_sums.end(), total/2 - i);
        if (itr != right_sums.begin()) {
            --itr;
            msf = min(msf, abs(total - 2 * (i + *itr)));
        }
    }
    cout << msf << "\n";

    return EXIT_SUCCESS;
}