#include <bits/stdc++.h>

using namespace std;

int dfs(int u, const vector<vector<int>>& adj, vector<int>& subs) {
    for (int v : adj[u])
        subs[u] += dfs(v, adj, subs) + 1;
    return subs[u];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, u;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<int> subs(n, 0);
    for (int i=1; i<n; ++i) {
        cin >> u;
        adj[u-1].push_back(i);
    }
    dfs(0, adj, subs);
    for (int i=0; i<n; ++i)
        cout << subs[i] << " ";
    return EXIT_SUCCESS;
}