#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n, m;
  map<int,int> a = {}, b = {};
  vector<int> c = {};
  for (int i=0;i<n;++i) {
    int aa;
    cin >> aa;
    a.insert({aa, 1});
    c.push_back(aa);
  }
  for (int i=0;i<m;++i) {
    int bb;
    cin >> bb;
    b.insert({bb, 1});
    c.push_back(bb);
  }
  sort(c.begin(), c.end());
  int cc = 0;
  cout << (c.size()) << endl;
  for (const auto& v : c) {
    cout << v << endl;
    if (a.find(v) != a.end()) {
      ++cc;
    }
    if (b.find(v) != b.end()) {
      cc = 0;
    }
  }
  cout << (cc > 1 ? "Yes" : "No") << endl;
}
