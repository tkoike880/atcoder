#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, r = -1;
  cin >> a >> b;
  if (a != b) {
    for (int i=1;i<=3;++i) {
        if (i != a && i != b) {
            r = i;
        }
    }
  }
  cout << r << endl;
}
