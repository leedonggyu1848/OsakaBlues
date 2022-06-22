#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321
#define MAXD 101
#define MAXH 51

typedef vector<int> vi;
typedef pair<int, int> pii;

int gN, gDays, gP, gT;
int gDests[MAXH];
bool isConnected[MAXH][MAXH];
double gCache[MAXH][MAXD];
int gDeg[MAXH];

void getInput() {
  cin >> gN >> gDays >> gP;
  for (int i=0; i< gN; ++i) for (int j=0; j<gN; ++j)
    cin >> isConnected[i][j];
  cin >> gT;
  FOR(gT) cin >> gDests[i];
}

void fillDeg() {
  memset(gDeg, 0, sizeof(gDeg));
  for(int i=0; i<gN; ++i)
    for(int j=0; j<gN; ++j)
      if (isConnected[i][j]) gDeg[i]+=1;
}

double getProbability(int cur, int days) {
  double& ret = gCache[cur][days];
  if (ret != -1) return ret;
  if (days == 0) return ret = (cur == gP ? 1.0 : 0.0);
  ret = 0.0;
  for (int i=0; i<gN; ++i) {
    if (isConnected[cur][i]) ret += getProbability(i, days-1) / gDeg[i];
  }
  return ret;
}

void solve() {
  for (int i=0; i<MAXH; ++i) for (int j=0; j<MAXD; ++j) gCache[i][j] = -1;
  fillDeg();
  FOR(gT) cout << getProbability(gDests[i], gDays) << ' ';
  cout << '\n';
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

