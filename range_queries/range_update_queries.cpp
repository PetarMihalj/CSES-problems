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

ll sum(vll& ft, int p) {
  ll s = 0;
  for (int i = p; i > 0; i -= i & (-i))
    s += ft[i];
  return s;
}

void add(vll& ft, int p, int dv) {
  for (int i = p; i < ft.size(); i += i & (-i))
    ft[i] += dv;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  vll FT(n + 1);
  FORI(n) {
    int x;
    cin >> x;
    add(FT, i + 1, x);
    add(FT, i + 2, -x);
  }
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b, u;
      cin >> a >> b >> u;
      add(FT, a, u);
      add(FT, b + 1, -u);
    } else {
      int u;
      cin >> u;
      cout << sum(FT, u) << endl;
    }
  }
}