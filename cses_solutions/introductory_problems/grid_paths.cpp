#include <bits/stdc++.h>

using namespace std;

constexpr int kN = 7;
constexpr int kM = 48;
const vector<pair<int, int>> kDs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
const unordered_map<char, int> kMap = {{'U', 0}, {'L', 1}, {'D', 2}, {'R', 3}};

string s;

bool dp[kN][kN] = {{false}};
int cc = 0;

void helper(int r, int c, int i) {
  if (i == kM) {
    ++cc;
    return;
  }
    
  if (s[i] != '?') {
    const auto& itr = kMap.find(s[i]);
    const auto& [dr, dc] = kDs[itr->second];
    int nr = r + dr, nc = c + dc;
    
    if (0 <= nr && nr < kN && 0 <= nc && nc < kN && !dp[nr][nc]) {
      if (nr == kN - 1 && nc == 0 && i != kM - 1) return;
      dp[nr][nc] = true;
      helper(nr, nc, i + 1);
      dp[nr][nc] = false;
    }
    return;
  }
  for (const auto& [dr, dc] : kDs) {
    int nr = r + dr, nc = c + dc;
    if (0 <= nr && nr < kN && 0 <= nc && nc < kN && !dp[nr][nc]) {
      if (nr == kN - 1 && nc == 0 && i != kM - 1) continue;
      dp[nr][nc] = true;
      helper(nr, nc, i + 1);
      dp[nr][nc] = false;
    }
  }
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  cin >> s;
  dp[0][0] = true;
  helper(0, 0, 0);
  cout << cc << '\n';
  return EXIT_SUCCESS;
}
