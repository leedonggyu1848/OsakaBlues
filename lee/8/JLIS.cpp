#include <bits/stdc++.h>
#include <limits>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321

typedef vector<int> vi;
typedef pair<int, int> pii;

int gAn, gBn;
int gASeq[101], gBSeq[101];
int gCache[101][101];
const long long NINF = numeric_limits<long long>::min();

void getInput() {
  cin >> gAn >> gBn;
  FOR(gAn) cin >> gASeq[i];
  FOR(gBn) cin >> gBSeq[i];
}

int jlis(int ai, int bi) {
  int& ret = gCache[ai+1][bi+1];
  if (ret != -1) return ret;
  ret = 2;
  long long a = (ai == -1 ? NINF : gASeq[ai]);
  long long b = (bi == -1 ? NINF : gBSeq[bi]);
  long long maxValue = max(a, b);
  for (int i=ai+1; i<gAn; ++i)
    if (maxValue < gASeq[i])
      ret = max(ret, jlis(i, bi)+1);
  for (int i=bi+1; i<gBn; ++i)
    if (maxValue < gBSeq[i])
      ret = max(ret, jlis(ai, i)+1);

  return ret;
}

void solve() {
  memset(gCache, -1, sizeof(gCache));
  cout << jlis(-1, -1)-2 << '\n';
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
