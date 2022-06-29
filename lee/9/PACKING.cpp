#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321

typedef vector<int> vi;
typedef pair<int, int> pii;

int gN, gW;
string gBaggages[101];
int gWeights[101], gNeeds[101];
int gCache[1001][101], gNext[102];

void getInput() {
  cin >> gN >> gW;
  FOR(gN) cin >> gBaggages[i] >> gWeights[i] >> gNeeds[i];
}

int pack(int capa, int item) {
  if (item == gN) return 0;
  int &ret = gCache[capa][item];
  if (ret != -1) return ret;
  ret = pack(capa, item+1);
  if (capa >= gWeights[item])
    ret = max(ret, pack(capa-gWeights[item], item+1)+gNeeds[item]);
  return ret;
}

int reconstruct(int capa, int item, vector<string>& picked) {
  if (item == gN) return 0;
  if (pack(capa, item) == pack(capa, item+1))
    return reconstruct(capa, item+1, picked);
  picked.push_back(gBaggages[item]);
  return reconstruct(capa-gWeights[item], item+1, picked)+1;
}

void solve() {
  memset(gCache, -1, sizeof(gCache));
  vector<string> picked;
  cout << pack(gW, 0) << ' ' << reconstruct(gW, 0, picked) << '\n';
  for (string s: picked)
    cout << s << '\n';
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
