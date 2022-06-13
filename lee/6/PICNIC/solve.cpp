#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
int n;
bool isPair[10][10];

void getInput(){
  int m;
  int i,j;
  memset(isPair, 0, sizeof(isPair));
  scanf("%d %d\n", &n, &m);
  while (m--){
    scanf("%d %d ", &i, &j);
    isPair[i][j] = true;
    isPair[j][i] = true;
  }
}

int countCases(bool isTaken[10]){
  int i = 0;
  int ret = 0;
  for (i=0; i < n; ++i) if (!isTaken[i]) break;
  if (i == n)
    return 1;
  isTaken[i] = true;
  for (int j=i+1; j < n; ++j){
    if (!isTaken[j] && isPair[i][j]){
      isTaken[j] = true;
      ret += countCases(isTaken);
      isTaken[j] = false;
    }
  }
  isTaken[i] = false;
  return ret;
}


void solve() {
  bool isTaken[10];
  memset(isTaken, 0, sizeof(isTaken));
  printf("%d\n", countCases(isTaken));
}

int main() {
  int t = 0;
  scanf("%d\n", &t);
  while (t--) {
    getInput();
    solve();
  }
  return 0;
}
