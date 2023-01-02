#include <bits/stdc++.h>

using namespace std;


int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<string>> dp = {{""}, {}};
    int curr = 0, next = 1;
    while (n--) {
        int m = dp[curr].size();
        dp[next].clear();
        for (int i=0; i<m; ++i)
            dp[next].push_back("0"+dp[curr][i]);
        for (int i=m-1; i>=0; --i)
            dp[next].push_back("1"+dp[curr][i]);
        curr ^= 1, next ^= 1;
    }
    for (const auto& s : dp[curr])
        cout << s << "\n";

    return EXIT_SUCCESS;
}