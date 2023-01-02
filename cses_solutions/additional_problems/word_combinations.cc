#include <bits/stdc++.h>

using namespace std;
 
int n, k, mod = 1e9 + 7;
int64_t dp[5001];
string s, x;

struct Node {
  vector<Node*> es = vector<Node*>(26, nullptr);
  bool is_word = false;
};

void add(Node* u, const string& w) {
  for (char c : w) {
    if (u->es[c-'a'] == nullptr) u->es[c-'a'] = new Node();
    u = u->es[c-'a'];
  }
  u->is_word = true;
}

bool contains(Node* u, const string& w) {
  for (char c : w) {
    if (u->es[c-'a'] == nullptr) return false;
    u = u->es[c-'a'];
  }
  return u->is_word;
}

int64_t helper(Node* r, int i) {
  if (i == n) return 1;
  if (dp[i] == -1) {
    int64_t x = 0;
    Node* u = r;
    for (int j=i; j<n; ++j) {
      u = u->es[s[j]-'a'];
      if (u == nullptr) break;
      if (u->is_word) x = (x + helper(r, j+1)) % mod;
    }
    dp[i] = x;
  }
  return dp[i];
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> k;
  n = s.size();
  for (int i=0; i<=n; ++i) dp[i] = -1;
  Node r = Node();
  for (int i=0; i<k; ++i) {
    cin >> x;
    if (x.size() > n) continue;
    add(&r, x);
  }
  cout << helper(&r, 0) << endl;
  return EXIT_SUCCESS;
} 