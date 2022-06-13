#include <cstdio>
#include <iostream>
#include <cstring>

#define NUM_BLOCK_TYPE 4

const int coverTypes[NUM_BLOCK_TYPE][3][2] = {
  { {0, 0}, {1, 0}, {0, 1} },
  { {0, 0}, {0, 1}, {1, 1} },
  { {0, 0}, {1, 0}, {1, 1} },
  { {0, 0}, {1, 0}, {1, -1} }
};

int r, c;
bool board[20][20];

bool isWall(int y, int x) {
  return board[y][x];
}

void getInput(){
  scanf("%d %d\n", &r, &c);
  char temp[20];
  for (int i=0; i<r; ++i) {
    scanf("%s\n", temp);
    for (int j=0; j<c; ++j)
      board[i][j] = temp[j] == '#';
  }
}

bool canAddBlock(int cy, int cx, int type) {
  int y, x;
  for (int i=0; i<3; ++i){
    y = cy + coverTypes[type][i][0];
    x = cx + coverTypes[type][i][1];
    if ((y >= r || y < 0) ||
        (x >= c || x < 0) ||
        isWall(y, x)) return false;
  }
  return true;
}

void replaceBlock(int cy, int cx, int type, bool replacement) {
  int y, x;
  for (int i=0; i<3; ++i) {
    y = cy + coverTypes[type][i][0];
    x = cx + coverTypes[type][i][1];
    board[y][x] = replacement;
  }
}

int countCases(int cy, int cx) {
  int ret = 0;
  int ny, nx;
  if (cy == r-1 && cx == c-1)
    return isWall(cy, cx);
  if (cx == c-1) {
    ny = cy+1;
    nx = 0;
  } else {
    ny = cy;
    nx = cx+1;
  }
  if (isWall(cy, cx))
    return countCases(ny, nx);
  for (int type=0; type<NUM_BLOCK_TYPE; ++type) {
    if (canAddBlock(cy, cx, type)){
      replaceBlock(cy, cx, type, true);
      ret += countCases(ny, nx);
      replaceBlock(cy, cx, type, false);
    }
  }
  return ret;
}

void solve() {
  printf("%d\n", countCases(0, 0));
}

int main() {
  int t;
  scanf("%d\n", &t);
  while (t--) {
    getInput();
    solve();
  }
  return 0;
}
