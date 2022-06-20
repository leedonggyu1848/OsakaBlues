#include <bits/stdc++.h>
#include <random>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321

typedef vector<int> vi;
typedef pair<int, int> pii;

int gTriangle[101][101];
int gCache[101][101];
int gN;

void getInput() {
  cin >> gN;
  for(int i=0; i<gN; ++i)
    for (int j=0; j<i+1; ++j)
      cin >> gTriangle[i][j];
}

int getMaxAcc(int y, int x) {
  if (y == gN)
    return 0;
  int& ret = gCache[y][x];
  if (ret != -1)
    return ret;
  ret = max(getMaxAcc(y+1, x), getMaxAcc(y+1, x+1)) + gTriangle[y][x];
  return ret;

}

void solve() {
  memset(gCache, -1, sizeof(gCache));
  cout << getMaxAcc(0, 0) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    getInput();
    solve();
  }
  return 0;
}
