#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
typedef vector<string> vecs;

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int cache[5][5][10];

void getInput(vecs& board, vecs& targets) {
  string tmp;
  int n;
  board.clear();
  for (int i=0; i<5; ++i){
    cin >> tmp;
    board.push_back(tmp);
  }
  cin >> n;
  targets.clear();
  for (int i=0; i<n; ++i){
    cin >> tmp;
    targets.push_back(tmp);
  }
}

int isRange(int y, int x) {
  return (y < 5 && x < 5 && 0 <= y && 0 <= x);
}

int search(vecs& board, string target, int cy, int cx, int idx) {
  int y;
  int x;
  int tmp = -1;
  int& cur = cache[cy][cx][idx];

  if (target[idx] != board[cy][cx])
    return 0;
  if (cur != -1)
    return cur;
  cur = 1;
  if (idx == target.size()-1)
    return cur+1;
  for (int i=0; i<8; ++i) {
      y = cy + dy[i];
    for (int j=0; j<8; ++j) {
      x = cx + dx[i];
      if (isRange(y, x)){
        tmp = search(board, target, y, x, idx+1);
        cur = max(cur, tmp);
      }
    }
  }
  return cur ? cur + 1 : 0;
}

void solve(vecs& board, vecs& targets) {
  int rst = 0;
  vector<string> answer = {"NO", "YES"};
  for (int i=0; i<targets.size(); ++i){
    rst = 0;
    memset(cache, -1, sizeof(cache));
    for (int y=0; y<5 && !rst; ++y){
      for (int x=0; x<5 && !rst; ++x){
        search(board, targets[i], y, x, 0);
        if (cache[y][x][0] == targets[i].size())
          rst = 1;
      }
    }
    cout << targets[i] << ' ' << answer[rst] << '\n';
  }
}

int main() {
  int n = 0;
  vecs board = vecs();
  vecs targets = vecs();
  cin >> n;

  for(int i=0; i<n; ++i){
    getInput(board, targets);
    solve(board, targets);
  }
  return 0;
}
