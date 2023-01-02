#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> kDs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int n, m;

void dfs(vector<string>& g, int i, int j) {
    g[i][j] = '#';
    for (const auto& [di, dj] : kDs) {
        int ni = i+di, nj = j+dj;
        if (0<=ni && ni<n && 0<=nj && nj<m && g[ni][nj] == '.')
            dfs(g, ni, nj);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int c = 0;
    cin >> n >> m;
    vector<string> g(n);
    for (int i=0; i<n; ++i)
        cin >> g[i];
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            if (g[i][j] == '.') {
                ++c;
                dfs(g, i, j);
            }
    
    cout << c << '\n';
    return EXIT_SUCCESS;
}