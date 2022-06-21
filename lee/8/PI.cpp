#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321

typedef vector<int> vi;
typedef pair<int, int> pii;

string N;
int gCache[10002];

void getInput() {
  cin >> N;
}

int getScore(int a, int b) {
  string M = N.substr(a, b-a+1);
  int i;
  if(M == string(M.size(), M[0])) return 1;
  for(i=0; i<M.size()-1; ++i)
    if(M[i+1]-M[i] != M[1]-M[0])
      break;
  if(i==M.size()-1) return abs(M[1]-M[0]) == 1 ? 2 : 5;
  for (i=0; i<M.size(); ++i)
    if(M[i] != M[i%2])
      break;
  if (i == M.size()) return 4;
  return 10;
}

int getEasiest(int idx) {
  int& ret = gCache[idx];
  if (ret != -1) return ret;
  if (idx == N.size()) return ret=0;
  ret = INF;
  for (int step=3; step<=5; ++step)
    if (idx+step <= N.size())
      ret = min(ret, getScore(idx, idx+step-1) + getEasiest(idx+step));
  return ret;
}

void solve() {
  memset(gCache, -1, sizeof(gCache));
  cout << getEasiest(0) << '\n';
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
