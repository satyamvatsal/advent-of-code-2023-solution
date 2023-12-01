#include <bits/stdc++.h>
#include <climits>
#include <fstream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define rep(i, a, b) for (int i = a; i < b; i++)
#define iter(i, arr) for (auto i : arr)
#define SQ(a) (a) * (a)

string digits[10] = {"zero", "one", "two",   "three", "four",
                     "five", "six", "seven", "eight", "nine"};

int todigit(const char ch) {
  int temp = static_cast<int>(ch);
  if (temp >= 48 && temp <= 57)
    return (temp - 48);
  else
    return -1;
}

int strTodigit(string s) {

  rep(i, 0, 10) {
    if (s == digits[i])
      return i;
  }
  return -1;
}

int main() {

  freopen("input.txt", "r", stdin);

  const int size = 1000;

  int ans = 0;
  vector<string> str;

  // taken input
  rep(i, 0, size) {

    string temp;
    cin >> temp;
    str.push_back(temp);
  }

  int num[size][2];

  // extracting digit from the first
  rep(i, 0, size) {
    int j = 0;
    int index = 0;
    int limit = str[i].length();
    for (int j = 0; j < limit; j++) {
      int digit = todigit(str[i][j]);
      if (digit != -1) {
        num[i][0] = digit;
        break;
      }
    }
  }

  // extrating digit from the end
  rep(i, 0, size) {
    int j = str[i].length() - 1;
    for (; j >= 0; j--) {
      int digit = todigit(str[i][j]);
      if (digit != -1) {
        num[i][1] = digit;
        break;
      }
    }
  }

  // printing the result after making it
  rep(i, 0, size) { ans += (10 * num[i][0]) + num[i][1]; }
  cout << ans << endl;

  return 0;
}
