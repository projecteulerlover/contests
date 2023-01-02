#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> groups;
vector<vector<int>> adj;

bool dfs(int u, int c) {
    groups[u] = c;
    for (int v : adj[u]) {
        if (groups[v] == -1) {
            if (!dfs(v, 1-c))
                return false;
        } else if (groups[v] != 1-c)
            return false;
    }
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    int a, b;
    adj = vector<vector<int>>(n);
    groups = vector<int>(n, -1);
    for (int i=0; i<m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0; i<n; ++i) {
        if (groups[i] == -1) {
            if (!dfs(i, 1)) {
                cout << "IMPOSSIBLE\n";
                return EXIT_SUCCESS;
            }
        }
        cout << groups[i] + 1 << ' ';
    }
    for (int i=0; i<n; ++i)
        cout << groups[i] + 1 << ' ';
    return EXIT_SUCCESS;
}