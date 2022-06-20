#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321

typedef vector<int> vi;
typedef pair<int, int> pii;

int gN;
int gArr[101][101];
int gCache[101][101];
const int gDir[2][2] = {{0, 1}, {1, 0}};

void getInput() {
  cin >> gN;
  for (int i=0; i<gN; ++i)
    for (int j=0; j<gN; ++j)
      cin >> gArr[i][j];
  memset(gCache, -1, sizeof(gCache));
}

int canArriveDest(int y, int x) {
  if (y < 0 || y >= gN || x < 0 || x >= gN)
    return false;
  int &ref = gCache[y][x];
  int cur = gArr[y][x];
  if (ref != -1)
    return ref;
  if (y == gN-1 && x == gN-1)
    return ref = true;
  for (int i=0; i<2 && ref!=1; ++i)
    ref = canArriveDest(y+gDir[i][0]*cur, x+gDir[i][1]*cur);
  return ref;
}

void solve() {
  const string answer[2] = {"NO", "YES"};
  cout << answer[canArriveDest(0, 0)] << '\n';
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


