#include <bits/stdc++.h>
#include <climits>
#include <fstream>
#include <variant>
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

int maxArray(int *arr) {
  int max = INT_MIN;
  int i = 0;
  int index = -1;
  for (; i < 10; i++) {
    if (max < arr[i] && arr[i] != -1) {
      index = i;
      max = arr[i];
    }
  }
  return index;
}
int minArray(int *arr) {
  int min = INT_MAX;
  int i = 0;
  int index = -1;
  for (; i < 10; i++) {
    if (min > arr[i] && arr[i] != -1) {
      index = i;
      min = arr[i];
    }
  }
  return index;
}

int todigit(const char ch) {
  int temp = static_cast<int>(ch);
  if (temp >= 48 && temp <= 57)
    return (temp - 48);
  else
    return -1;
}
int digitfromnum = 0;
int digitfromstr = 0;
int digitfromstrend = 0;
int digitfromnumend = 0;

int positionsfromdigitsend(string str) {
  int fromdigit = -1;
  int temp = -1;
  int length = str.length();
  int k = length - 1;
  while (k >= 0) {
    temp = todigit(str[k]);
    if (temp != -1) {
      fromdigit = k;
      digitfromnumend = temp;
      break;
    }
    k--;
  }
  return fromdigit;
}
int positionsfromdigits(string str) {
  int k = 0;
  int fromdigit = -1;
  int temp = -1;
  int length = str.length();
  while (k < length) {
    temp = todigit(str[k]);
    if (temp != -1) {
      fromdigit = k;
      digitfromnum = temp;
      break;
    }
    k++;
  }
  return fromdigit;
}
int position[10];
/// to check why this function is not working as inteded

int strTodigitend(string str) {

  int digitfromstrend = 0;
  int i = 0;
  int index = -1;
  // finding the one , two etc in the string and storing it into a position
  // array
  for (; i < 10; i++) {
    index = str.rfind(digits[i]);
    position[i] = index;
  }

  digitfromstrend = maxArray(position);
  int positionfromdigitend = positionsfromdigitsend(str);
  int positionfromstrend = str.rfind(digits[digitfromstrend]);

  if (positionfromstrend == -1)
    return digitfromnumend;
  else if (positionfromdigitend == -1)
    return digitfromstrend;
  if (positionfromstrend > positionfromdigitend)
    return digitfromstrend;
  else
    return digitfromnumend;
}

int strTodigit(string str) {

  int digitfromstr = 0;
  int i = 0;
  int index = -1;
  // finding the one , two etc in the string and storing it into a position
  // array
  for (; i < 10; i++) {
    index = str.find(digits[i]);
    position[i] = index;
  }

  digitfromstr = minArray(position);
  int positionfromdigit = positionsfromdigits(str);
  int positionfromstr = str.find(digits[digitfromstr]);

  if (positionfromstr == -1)
    return digitfromnum;
  else if (positionfromdigit == -1)
    return digitfromstr;
  if (positionfromstr < positionfromdigit)
    return digitfromstr;
  else
    return digitfromnum;
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

  rep(i, 0, size) {
    num[i][0] = strTodigit(str[i]);
    num[i][1] = strTodigitend(str[i]);
  }

  // printing the result after making it
  rep(i, 0, size) { ans += (10 * num[i][0]) + num[i][1]; }
  cout << ans << endl;

  return 0;
}
