#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> outputs = {s};
    while (next_permutation(s.begin(), s.end()))
        outputs.push_back(s);
    cout << outputs.size() << '\n';
    for (const auto& p : outputs)
        cout << p << " ";
    return EXIT_SUCCESS;
}