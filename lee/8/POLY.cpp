#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321
#define MOD 10000000

typedef vector<int> vi;
typedef pair<int, int> pii;

int gN;
int gCache[101][101];

void getInput() {
  cin >> gN;
}

int getPoly(int n, int first) {
  if (n == first) return 1;
  int& ret = gCache[n][first];
  int add;
  if (ret != -1) return ret;
  ret = 0;
  for (int next=1; next<=n-first; ++next) {
    add = first == 0 ? 1 : next + first - 1;
    add *= getPoly(n-first, next);
    add %= MOD;
    ret += add;
    ret %= MOD;
  }
  return ret;
}

void solve() {
  cout << getPoly(gN, 0) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  memset(gCache, -1, sizeof(gCache));
  while(t--){
    getInput();
    solve();
  }
  return 0;
}
