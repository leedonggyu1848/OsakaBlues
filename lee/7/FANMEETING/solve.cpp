#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;
typedef vector<int> vi;

vi gMembers(200001);
vi gFans(200001);

void getInput() {
  string s;
  cin >> s;
  gMembers.resize(s.length());
  for (int i=0; i<s.length(); ++i)
    gMembers[i] = s[i] == 'M';
  cin >> s;
  gFans.resize(s.length());
  for (int i=0; i<s.length(); ++i)
    gFans[s.length()-i-1] = s[i] == 'M';
}

vector<int> multiply(const vector<int> &a, const vector<int> &b){
    vector<int> c(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); i++)
        for (int j = 0; j < b.size(); j++)
            c[i + j] += (a[i] * b[j]);
    return c;
}

void addTo(vector<int> &a, const vector<int> &b, int k){
    a.resize(max(a.size(), b.size() + k));
    for (int i = 0; i < b.size(); i++)
        a[i + k] += b[i];
}

void subFrom(vector<int> &a, const vector<int> &b){
    a.resize(max(a.size(), b.size()));
    for (int i = 0; i < b.size(); i++)
        a[i] -= b[i];
}

vector<int> karatsuba(const vector<int> &a, const vector<int> &b){
    int an = a.size(), bn = b.size();
    if (an < bn)
        return karatsuba(b, a);
    if (an == 0 || bn == 0)
        return vector<int>();
    if (an <= 50)
        return multiply(a, b);

    int half = an / 2;
    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(bn, half));
    vector<int> b1(b.begin() + min<int>(bn, half), b.end());

    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> res;
    addTo(res, z0, 0);
    addTo(res, z1, half);
    addTo(res, z2, half * 2);
    return res;
}

void solve() {
  vi c = karatsuba(gMembers, gFans);
  int answer = 0;
  for (int i=gMembers.size()-1; i<gFans.size(); ++i )
    if (c[i] == 0) ++answer;
  printf("%d\n", answer);
}

int main() {
  int t = 0;
  scanf("%d\n", &t);
  while (t--) {
    getInput();
    solve();
  }
}
