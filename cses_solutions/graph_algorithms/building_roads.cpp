#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> ps;

int ds_find(int i) {
    if (i == ps[i])
        return i;
    return ps[i] = ds_find(ps[i]);
}

void ds_union(int i, int j) {
    int pi = ds_find(i), pj = ds_find(j);
    if (pi != pj)
        ps[pi] = pj;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> n >> m;
    ps = vector<int>(n, 0);
    iota(ps.begin(), ps.end(), 0);
    int a, b;
    for (int i=0; i<m; ++i) {
        cin >> a >> b;
        ds_union(--a, --b);
    }
    vector<bool> reps(n, false);
    vector<int> rs;
    for (int i=0; i<n; ++i) {
        if (!reps[ds_find(i)])
            rs.push_back(ds_find(i));
        reps[ds_find(i)] = true;
    }
    int k = rs.size();
    cout << k - 1 << '\n';
    if (k - 1 == 0)
        return EXIT_SUCCESS;
    for (int i=0; i<k-1; ++i)
        cout << rs[i]+1 << ' ' << rs[i+1]+1 << '\n';
    
    return EXIT_SUCCESS;
}