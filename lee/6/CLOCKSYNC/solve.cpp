#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define NUM_CLOCKS 16
#define NUM_SWITCHES 10
#define INF 987654321
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int clocks[NUM_CLOCKS];

vvi switches {
  {0,1,2},
  {3,7,9,11},
  {4,10,14,15},
  {0,4,5,6,7},
  {6,7,8,10,12},
  {0,2,14,15},
  {3,14,15},
  {4,5,7,14,15},
  {1,2,3,4,5},
  {3,4,5,9,13}
};

void getInput() {
  for(int i=0; i<NUM_CLOCKS; ++i)
    scanf("%d ", &clocks[i]);
}

void moveClock(int idx) {
  clocks[idx] += 3;
  if (clocks[idx] == 15) clocks[idx] = 3;
}

void pushSwitch(int idx) {
  for (int i : switches[idx])
    moveClock(i);
}

bool areAllClocks12() {
  for (int i=0; i<NUM_CLOCKS; ++i) {
    if (clocks[i] != 12)
      return false;
  }
  return true;
}

int countCases(int idx) {
  int ret = INF;
  if (areAllClocks12())
    return 0;
  if (idx == NUM_SWITCHES)
    return ret;
  for (int i=0; i<4; ++i){
    ret = min(countCases(idx+1)+i, ret);
    pushSwitch(idx);
  }
  return ret;
}

void solve() {
  int answer = countCases(0);
  if (answer == INF)
    answer = -1;
  printf("%d\n", answer);
}

int main() {
  int c;
  scanf("%d\n", &c);

  while (c--) {
    getInput();
    solve();
  }
}
