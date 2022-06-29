#include <bits/stdc++.h>

using namespace std;

#define FOR(N) for(int i=0; i<(N); ++i)
#define INF 987654321

typedef vector<int> vi;
typedef pair<int, int> pii;

int m, q, n;
int R[101];
double Begin[501];
double T[501][501], M[501][501];
string corpus[501];
double cache[101][502];
int choice[102][502];

void init() {
	for (int i = 0; i < n; ++i) for (int j = 0; j < m + 1; ++j)
			cache[i][j] = 1.0;
}
void getInput() {
  cin >> m >> q;
  for (int i = 1; i < m + 1; ++i)
    cin >> corpus[i];
  for (int i = 1; i < m + 1; ++i) {
    cin >> Begin[i];
    Begin[i] = log(Begin[i]);
  }
  for (int i = 0; i < m + 1; ++i) for (int j = 1; j < m + 1; ++j) {
    if (i == 0) T[i][j] = Begin[j];
    else {
      cin >> T[i][j];
      T[i][j] = log(T[i][j]);
    }
  }
  for (int i = 1; i < m + 1; ++i) for (int j = 1; j < m + 1; ++j) {
    cin >> M[i][j];
    M[i][j] = log(M[i][j]);
  }
}

double recognize(int segment, int previousMatch) {
	if (segment == n) return 0;
	double&ret = cache[segment][previousMatch];
	if (ret != 1.0)return ret;
	ret = -1e200;
	int &choose = choice[segment][previousMatch];
	for (int thisMatch = 1; thisMatch < m + 1; ++thisMatch) {
		double cand = \
      T[previousMatch][thisMatch] + \
      M[thisMatch][R[segment]] +  \
      recognize(segment + 1, thisMatch);
		if (ret < cand) {
			ret = cand;
			choose = thisMatch;
		}
	}
  return ret;
}

string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment][previousMatch];
  string ret = corpus[choose];
  if (segment < n-1)
    ret = ret + " " + reconstruct(segment+1, choose);
  return ret;
}

void solve() {
  while (q--) {
  cin >> n;
  init();
  for (int i = 0; i < n; ++i) {
    string tmp;
    cin >> tmp;
    for (int j = 1; j < m + 1; ++j)
      if (tmp == corpus[j]) {
        R[i] = j;
        break;
      }
  }
    recognize(0, 0);
    cout << reconstruct(0, 0) << '\n';
  }
}

#ifdef DEBUG
// 테스트용
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  getInput();
  solve();
  return 0;
}
#endif

#ifndef DEBUG
// 제출용
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  getInput();
  solve();
  return 0;
}
#endif
