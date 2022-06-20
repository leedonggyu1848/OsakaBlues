#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

string target;

void getInput() {
  cin >> target;
}

string reverse(string::iterator& iter) {
  char head = *iter;
  iter++;
  if (head == 'b' || head == 'w')
    return string(1, head);
  string three = reverse(iter);
  string four = reverse(iter);
  string one = reverse(iter);
  string two = reverse(iter);
  return 'x' + one + two + three + four;
}

void solve() {
  string::iterator iter = target.begin();
  cout << reverse(iter) << '\n';
}

int main() {
  int t = 0;
  scanf("%d\n", &t);
  while (t--) {
    getInput();
    solve();
  }
}
