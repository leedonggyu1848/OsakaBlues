#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int gN;
int gFences[20001];

void getInput() {
  cin >> gN;
  for (int i=0; i<gN; ++i)
    cin >> gFences[i];
}

int cutFence(int left, int right) {
  if (left == right) return gFences[left];
  int mid = (right + left) / 2;
  int ret = max(cutFence(left, mid), cutFence(mid+1, right));
  int l = mid;
  int r = mid+1;
  int height = min(gFences[l], gFences[r]);
  int width = 1;
  while (left <= l || r <= right){
    if (l < left || ((r <= right) && gFences[r] >= gFences[l])){
      height = min(height,gFences[r]);
      r++;
    } else {
      height = min(height, gFences[l]);
      l--;
    }
    ret = max(ret, width * height);
    width++;
  }
  return ret;
}

void solve() {
  cout << cutFence(0, gN-1) << '\n';
}

int main() {
  int t = 0;
  scanf("%d\n", &t);
  while (t--) {
    getInput();
    solve();
  }
}
