#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321

typedef vector<int> vi;
typedef pair<int, int> pii;

int gN, gS;
int gSeq[101];
int gCache[102][12];
int gAcc[101];
int gSAcc[101];

void getInput() {
  cin >> gN >> gS;
  FOR(gN) cin >> gSeq[i];
}

void fillAcc() {
  sort(gSeq, gSeq+gN);
  gAcc[0] = gSeq[0];
  gSAcc[0] = gSeq[0] * gSeq[0];
  for (int i=1; i<gN; ++i) {
    gAcc[i] = gAcc[i-1] + gSeq[i];
    gSAcc[i] = gSAcc[i-1] + gSeq[i] * gSeq[i];
  }
}

int getAcc(int* arr, int a, int b) {
  if (a == 0) return arr[b];
  return arr[b] - arr[a-1];
}

int getMs(int lo, int hi) {
  int sum = getAcc(gAcc, lo, hi);
  int sqSum = getAcc(gSAcc, lo ,hi);
  int m = int(0.5 + (double)sum / (hi - lo + 1));
  int ret = sqSum - 2 * m * sum + m * m *(hi-lo+1);
  return ret;
}

int getMinimumMs(int idx, int cnt) {
  int& ret = gCache[idx][cnt];
  int curMs;
  if (ret != -1) return ret;
  if (idx == gN) return ret = 0;
  if (cnt == 0) return ret = INF;
  ret = INF;
  for (int i=idx; i< gN; ++i) {
    curMs = getMs(idx, i);
    ret = min(getMinimumMs(i+1, cnt-1) + curMs , ret);
  }
  return ret;
}

void solve() {
  fillAcc();
  memset(gCache, -1, sizeof(gCache));
  cout << getMinimumMs(0, gS) << '\n';
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
