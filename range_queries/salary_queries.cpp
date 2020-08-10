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

int sum(vi& ft, int p) {
  int s = 0;
  for (int i = p; i > 0; i -= i & (-i))
    s += ft[i];
  return s;
}

void add(vi& ft, int p, int dv) {
  for (int i = p; i < ft.size(); i += i & (-i))
    ft[i] += dv;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int BLOCK = 5000;
  int n, q;
  cin >> n >> q;
  vi P(n);
  vvi B(1E9 / BLOCK + 5);

  FORI(n) {
    cin >> P[i];
    B[P[i] / BLOCK].push_back(P[i]);
  }
  FORI(q) {
    char c;
    cin >> c;
    if (c == '!') {
      int k, x;
      cin >> k >> x;
      k--;
      auto s1 = find(B[P[k] / BLOCK].begin(), B[P[k] / BLOCK].end(), P[k]);
      iter_swap(s1, B[P[k] / BLOCK].rbegin());
      B[P[k] / BLOCK].pop_back();
      P[k] = x;
      B[P[k] / BLOCK].push_back(P[k]);
    } else {
      int a, b;
      cin >> a >> b;
      int res = 0;
      int first_block = a / BLOCK;
      int last_block = b / BLOCK;
      for (int v : B[first_block])
        if (v >= a && v <= b)
          res++;
      if (first_block != last_block)
        for (int v : B[last_block])
          if (v >= a && v <= b)
            res++;
      for (int i = first_block + 1; i <= last_block - 1; i++)
        res += B[i].size();
      cout << res << '\n';
    }
  }
}