#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> xs(n);
    for (int i=0; i<n; ++i)
        cin >> xs[i];
    sort(xs.begin(), xs.end());
    int count = 0;
    for (int i=0; i<n;) {
        ++count;
        int j=i+1;
        while (j<n && xs[j] == xs[i])
            ++j;
        i = j;
    }
    cout << count << '\n';
    return EXIT_SUCCESS;
}