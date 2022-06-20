#include <bits/stdc++.h>

using namespace std;
#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321

typedef vector<int> vi;
typedef pair<int, int> pii;

string gWildcard;
int gN;
string gFiles[51];
vector<string> gAnswer;
int cache[101][101];

void getInput() {
  gAnswer.resize(0);
  cin >> gWildcard;
  cin >> gN;
  FOR(gN) cin >> gFiles[i];
}

bool isTarget(const string& tar, unsigned int w, unsigned int s) {
  int& ret = cache[w][s];
  if (ret != -1) return ret;
  if (s < tar.size() &&
          w < gWildcard.size() &&
          (gWildcard[w] == '?' || gWildcard[w] == tar[s]
        )) return ret = isTarget(tar, w+1, s+1);
  if (w == gWildcard.size())
    return ret = (s == tar.size());
  if (gWildcard[w] == '*')
      if(isTarget(tar, w+1, s) || (s < tar.size() && isTarget(tar, w, s+1)))
        return ret = 1;
  return ret = 0;
}

void solve() {
  FOR(gN){
    memset(cache, -1, sizeof(cache));
    if(isTarget(gFiles[i], 0, 0)) gAnswer.push_back(gFiles[i]);
  }
  sort(gAnswer.begin(), gAnswer.end());
  for(string s:gAnswer)
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
