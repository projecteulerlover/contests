#include <bits/stdc++.h>

using namespace std;

using pii = pair<int64_t, int>;

int n, m;
vector<int64_t> wss;
vector<bool> seen;
vector<vector<pii>> adj;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    int a, b;
    int64_t c;
    adj = vector<vector<pii>>(n);
    seen = vector<bool>(n, false);
    for (int i=0; i<m; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].push_back({c, b});
    }
    wss = vector<int64_t>(n, LLONG_MAX);
    
    priority_queue<pii, vector<pii>, greater<pii>> frontier;
    frontier.push({0, 0});
    wss[0] = 0LL;
    while (!frontier.empty()) {
        int u = frontier.top().second;
        frontier.pop();
        if (seen[u])
            continue;
        seen[u] = true;
        for (const auto& [dw, v] : adj[u]) {
            int64_t nw = wss[u] + dw;
            if (nw < wss[v]) {
                wss[v] = nw;
                frontier.push({nw, v});    
            }
        }
    }
    for (int i=0; i<n; ++i)
        cout << wss[i] << ' ';
        
    return EXIT_SUCCESS;
}