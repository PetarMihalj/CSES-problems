#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;

typedef vector<double> vd;
typedef vector<vd> vvd;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> llll;
typedef vector<vll> vvll;
typedef vector<llll> vllll;

inline ll pos_mod(ll i, ll n) {
  return (i % n + n) % n;
}
#define FORI(n) for (int i = 0; i < (n); i++)
#define FORJ(n) for (int j = 0; j < (n); j++)
#define FORK(n) for (int k = 0; k < (n); k++)
#define MOD 1000000007

int sum(int i, int j, vvi& ft) {
  int sum = 0;
  for (int ii = i; ii > 0; ii -= ii & (-ii))
    for (int jj = j; jj > 0; jj -= jj & (-jj))
      sum += ft[ii][jj];
  return sum;
}

void add(int i, int j, int dv, vvi& ft) {
  for (int ii = i; ii < ft.size(); ii += ii & (-ii))
    for (int jj = j; jj < ft[0].size(); jj += jj & (-jj))
      ft[ii][jj] += dv;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  vvi X(n + 1, vi(n + 1));
  vvi F(n + 1, vi(n + 1));
  FORI(n) {
    string s;
    cin >> s;
    FORJ(n) {
      X[i + 1][j + 1] = s[j] == '*' ? 1 : 0;
      add(i + 1, j + 1, s[j] == '*' ? 1 : 0, F);
    }
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int y1, x1;
      cin >> y1 >> x1;
      add(y1, x1, X[y1][x1] == 1 ? -1 : 1, F);
      X[y1][x1] = X[y1][x1] == 1 ? 0 : 1;
    } else {
      int y1, x1, y2, x2;
      cin >> y1 >> x1 >> y2 >> x2;
      cout << sum(y2, x2, F) - sum(y1 - 1, x2, F) - sum(y2, x1 - 1, F) +
                  sum(y1 - 1, x1 - 1, F)
           << '\n';
    }
  }
}