#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321

typedef vector<int> vi;
typedef pair<int, int> pii;

int gN;
int gTri[101][101];
int gPath[101][101];
int gCounting[101][101];

void getInput() {
  cin >> gN;
  for (int i=0; i<gN; ++i) for (int j=0; j<=i; ++j)
      cin >> gTri[i][j];
}

int path(int y, int x) {
  int& ret = gPath[y][x];
  if (y == gN-1) return ret = gTri[y][x];
  if (ret != -1) return ret;
  return ret = max(path(y+1, x), path(y+1, x+1)) + gTri[y][x];
}

int count(int y, int x) {
  int& ret = gCounting[y][x];
  if (ret != -1) return ret;
  if (y == gN-1) return ret = 1;
  int path1 = path(y+1, x);
  int path2 = path(y+1, x+1);
  ret = 0;
  if (path1 > path2) return ret = count(y+1, x);
  if (path1 < path2) return ret = count(y+1, x+1);
  else return ret = count(y+1, x) + count(y+1, x+1);
}

void solve() {
  memset(gCounting, -1, sizeof(gCounting));
  memset(gPath, -1, sizeof(gPath));
  cout << count(0, 0) << '\n';
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

