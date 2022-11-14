#include <bits/stdc++.h>

using namespace std;

constexpr int64_t N = 2 * 1e5 + 2;

int64_t gs, gs1, mx, mx1, n, t[4 * N][2], p[N], qz[N], zs[N], dp[N][2];

int64_t query(int64_t k, int64_t l, int64_t r, int64_t L, int64_t R,
              int64_t op) {
  if (L > R) return 0;
  if (L <= l && r <= R) return t[k][op];
  int64_t m = (l + r) / 2, res = 0;
  if (L <= m) res = max(res, query(k * 2, l, m, L, R, op));
  if (m < R) res = max(res, query(k * 2 + 1, m + 1, r, L, R, op));
  return res;
}

void add(int64_t k, int64_t l, int64_t r, int64_t wz, int64_t op, int64_t z) {
  if (l == r) {
    t[k][op] = z;
    return;
  }
  int64_t m = (l + r) / 2;
  if (wz <= m)
    add(k * 2, l, m, wz, op, z);
  else
    add(k * 2 + 1, m + 1, r, wz, op, z);
  t[k][op] = max(t[k * 2][op], t[k * 2 + 1][op]);
}

int64_t ok(int64_t dd) {
  int64_t dq = gs + zs[dd] - gs1, pd = 0;
  if (dq >= 0 && query(1, 1, n, mx1 + 1, n, dq % 2) >= dq) pd = 1;
  dq = gs1 + zs[dd] - gs;
  if (dq >= 0 && query(1, 1, n, mx + 1, n, dq % 2) >= dq) pd = 1;
  return pd;
}

int main() {
  cin >> n;
  int64_t zd = 0;
  for (int64_t i = 1; i <= n; ++i) {
    cin >> p[i];
    if (zd < p[i]) qz[i] = 1, zd = p[i];
  }
  for (int64_t i = 1; i <= 4 * n; ++i) t[i][0] = t[i][1] = -1e18;
  for (int64_t i = n; i >= 1; i--) {
    int64_t zz = query(1, 1, n, p[i] + 1, n, (qz[i] + 1) % 2);
    dp[i][0] = dp[i][1] = -1e18;
    if (zz || (qz[i] + 1) % 2 == 0) dp[i][0] = zz + qz[i] + 1;
    int64_t zz1 = query(1, 1, n, p[i] + 1, n, qz[i]);
    if (zz1 || (qz[i] + 1) % 2 == 1) dp[i][1] = zz1 + qz[i] + 1;
    add(1, 1, n, p[i], 0, dp[i][0]), add(1, 1, n, p[i], 1, dp[i][1]);
  }
  for (int64_t i = n; i; i--) zs[i] = zs[i + 1] + qz[i];
  gs = 0, gs1 = 0, mx = 0, mx1 = 0;
  if (!ok(1)) {
    cout << -1;
    return 0;
  }
  for (int64_t i = 1; i <= n; ++i) {
    add(1, 1, n, p[i], 0, -1e18), add(1, 1, n, p[i], 1, -1e18);
    int64_t pgs = gs, pmx = mx;
    if (p[i] > mx) mx = p[i], gs++;
    if (ok(i + 1))
      cout << 'a';
    else {
      gs = pgs, mx = pmx;
      if (p[i] > mx1) mx1 = p[i], ++gs1;
      cout << 'b';
    }
  }
  return 0;
}