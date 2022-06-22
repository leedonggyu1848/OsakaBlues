#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321
#define MOD 1000000007

typedef vector<int> vi;
typedef pair<int, int> pii;

int gN;
int gTiling[101], gSymTiling[101];

void getInput() {
  cin >> gN;
}

int getSymTiling(int n) {
  if (n <= 1) return 1;
  int& ret = gSymTiling[n];
  if (ret != -1) return ret;
  return ret = (getSymTiling(n-2) + getSymTiling(n-4)) % MOD;
}

int getTiling(int n) {
  if (n <= 1) return 1;
  int& ret = gTiling[n];
  if (ret != -1) return ret;
  return ret = (getTiling(n-1) + getTiling(n-2)) % MOD;
}

int getAsymTiling(int n) {
  return (getTiling(n) - getSymTiling(n) + MOD) % MOD;
}

void solve() {
  cout << getAsymTiling(gN) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  memset(gTiling, -1, sizeof(gTiling));
  memset(gSymTiling, -1, sizeof(gSymTiling));
  while(t--){
    getInput();
    solve();
  }
  return 0;
}
