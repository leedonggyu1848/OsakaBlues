#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321

typedef vector<int> vi;
typedef pair<int, int> pii;

int gN, gM;
double gCache[1001][1001];

void getInput() {
  cin >> gN >> gM;
}

double getProbability(int days, int height) {
  if (days == gM) return height >= gN ? 1 : 0;
  if (height >= gN) return 1;
  double& ret = gCache[days][height];
  if (ret != -1) return ret;
  return ret = 0.25*getProbability(days+1, height+1) + 0.75*getProbability(days+1, height+2);
}

void solve() {
  for(int i=0; i<1001; ++i) for(int j=0; j<1001; ++j)
    gCache[i][j] = -1;
  cout.precision(11);
  cout << getProbability(0, 0) << '\n';
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

