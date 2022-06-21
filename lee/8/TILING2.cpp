#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321
#define MOD 1000000007

typedef vector<int> vi;
typedef pair<int, int> pii;

int gN;
int gCache[102];

void getInput() {
  cin >> gN;
}

int tiling(int n) {
  int& ret = gCache[n];
  if (ret != -1) return ret;
  if (n <= 1) return ret = 1;
  return ret = (tiling(n-2) + tiling(n-1)) % MOD;
}

void solve() {
  cout << tiling(gN) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  memset(gCache, -1, sizeof(gCache));
  int t;
  cin >> t;
  while(t--){
    getInput();
    solve();
  }
  return 0;
}
