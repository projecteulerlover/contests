#include <bits/stdc++.h>
    
using namespace std;
 
int64_t x, n;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> x >> n;
  int64_t t = x;
  priority_queue<int, vector<int>, greater<>> pq;
  for (int i=0; i<n; ++i) {
    cin >> x;
    pq.push(x);
  }
  
  while (pq.size() > 2) {
    int64_t a = pq.top(); pq.pop();
    int64_t b = pq.top(); pq.pop();
    t += (a += b);
    pq.push(a);
  }
  cout << t << endl;
  return EXIT_SUCCESS;
}