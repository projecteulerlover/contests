#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ps;
vector<vector<int>> adj;

int bfs() {
    vector<vector<int>> frontier = {{0}, {}};
    ps[0] = 0;
    int p = 0, c = 1, d = 1;
    while (!frontier[p].empty()) {
        ++d;
        frontier[c].clear();
        for (int u : frontier[p]) {
            for (int v : adj[u]) {
                if (ps[v] == -1) {
                    ps[v] = u;
                    if (v == n-1)
                        return d;
                    frontier[c].push_back(v);
                }
            }
        }
        p ^= 1, c ^= 1;
    }
    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    int a, b;
    ps = vector<int>(n, -1);
    adj = vector<vector<int>>(n);
    for (int i=0; i<m; ++i) {
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int d = bfs();
    if (d == -1) {
        cout << "IMPOSSIBLE\n";
        return EXIT_SUCCESS;
    }
    cout << d << '\n';
    vector<int> path = {n-1};
    for (int i=1; i<d; ++i)
        path.push_back(ps[path.back()]);
    for (int i=d-1; i>=0; --i)
        cout << path[i]+1 << ' ';
    return EXIT_SUCCESS;
}