#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define FOR2(N, M) for (int i=0; i<(N); ++i) for (int j=0; j<(M); ++j)
#define INF 1000000100

typedef vector<int> vi;
typedef pair<int, int> pii;

int gN, gM, gK;
int gBino[201][201];

void getInput() {
  cin >> gN >> gM >> gK;
}

void init() {
  for (int i=0; i<=200; ++i) {
    gBino[i][0] = gBino[i][i] = 1;
    for (int j=1; j<i; ++j)
      gBino[i][j] = min(INF, gBino[i-1][j-1] + gBino[i-1][j]);
  }
}

void _generate(int n, int m, string s) {
  if (gK < 0) return;
  if (n==0 && m==0) {
    if (gK == 0) cout << s << '\n';
    --gK;
    return;
  }
  if (gBino[n+m][n] <= gK) {
    gK -= gBino[n+m][n];
    return;
  }
  if (n>0) _generate(n-1, m, s+"-");
  if (m>0) _generate(n, m-1, s+"o");
}

void solve() {
  gK--;
  _generate(gN, gM, "");
}

#ifndef DEBUG
// 제출용
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  init();
  getInput();
  solve();
  return 0;
}
#endif

#ifdef DEBUG
// 테스트용
int main() {
  int t;
  init();
  cin >> t;
  while(t--){
    getInput();
    solve();
  }
  return 0;
}
#endif
