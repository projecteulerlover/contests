#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> kDs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const vector<vector<char>> kDMs = {{'*', 'D', '*'}, {'R', '*', 'L'}, {'*', 'U', '*'}};

int n, m, si, sj, ei, ej;
vector<vector<pair<int, int>>> path;

int bfs(vector<string>& g) {
    vector<vector<pair<int, int>>> frontier = {{{si, sj}}, {}};
    int curr = 0, next = 1, d = 0;
    path = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(m, {-1, -1}));
    path[si][sj] = {si, sj};
    while (!frontier[curr].empty()) {
        ++d;
        frontier[next].clear();
        for (const auto& [i, j] : frontier[curr]) {
            for (const auto& [di, dj] : kDs) {
                int ni = i+di, nj = j+dj;
                if (0<=ni && ni<n && 0<=nj && nj<m && g[ni][nj] != '#' && path[ni][nj].first == -1) {
                    path[ni][nj] = {i, j};
                    if (ni == ei && nj == ej) {
                        return d;
                    }
                    frontier[next].push_back({ni, nj});
                }
            }
        }
        curr ^= 1, next ^= 1;
    }
    return -1;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    vector<string> g(n);
    for (int i=0; i<n; ++i) {
        cin >> g[i];
        for (int j=0; j<m; ++j) {
            if (g[i][j] == 'A')
                si = i, sj = j;
            else if (g[i][j] == 'B')
                ei = i, ej = j;
        }
    }
    int d = bfs(g);
    if (d == -1) {
        cout << "NO\n";
        return EXIT_SUCCESS;
    }
    cout << "YES\n" << d << '\n';
    vector<pair<int, int>> cp = {{ei, ej}, {-1, -1}};
    int c = 0, p = 1;
    string s;
    while (d--) {
        cp[p] = path[cp[c].first][cp[c].second];
        s.push_back(kDMs[cp[p].first-cp[c].first+1][cp[p].second-cp[c].second+1]);
        c ^= 1, p ^= 1;
    }
    reverse(s.begin(), s.end());
    cout << s << '\n';

    return EXIT_SUCCESS;
}