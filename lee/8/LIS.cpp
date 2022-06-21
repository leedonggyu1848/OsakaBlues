#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321

typedef vector<int> vi;
typedef pair<int, int> pii;

int gN;
int gArr[501];
int gCache[501];

void getInput() {
  cin >> gN;
  FOR(gN) cin >> gArr[i];
}

int getLIS(int idx) {
  int& ret = gCache[idx+1];
  if (ret != -1) return ret;
  ret = 1;
  for (int next=idx+1; next<gN; ++next)
    if (idx == -1 || gArr[idx] < gArr[next])
      ret = max(ret, getLIS(next)+1);
  return ret;
}

void solve() {
  memset(gCache, -1, sizeof(gCache));
  cout << getLIS(-1)-1 << '\n';
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
