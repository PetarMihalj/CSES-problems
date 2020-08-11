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

struct node {
  ll sum;
  ll set;
  ll add;
};

void lazy(vector<node>& st, int i, int lo, int hi) {
  if (lo == hi) {
    if (st[i].set) {
      st[i].sum = st[i].set;
      st[i].set = 0;
    }
    st[i].sum += st[i].add;
    st[i].add = 0;
    return;
  }
  if (st[i].set) {
    st[i].sum = (hi - lo + 1) * st[i].set;
  }
  st[i].sum += (hi - lo + 1) * st[i].add;

  if (st[i].set) {
    st[2 * i].set = st[i].set;
    st[2 * i + 1].set = st[i].set;
    st[2 * i].add = 0;
    st[2 * i + 1].add = 0;
  }
  st[2 * i].add += st[i].add;
  st[2 * i + 1].add += st[i].add;

  st[i].add = 0;
  st[i].set = 0;
}

void sett(vector<node>& st, int i, int lo, int hi, int a, int b, int x) {
  lazy(st, i, lo, hi);
  if (b < lo || a > hi)
    return;
  if (lo >= a && hi <= b) {
    st[i].set = x;
    lazy(st, i, lo, hi);
    return;
  }
  int mid = (lo + hi) / 2;
  sett(st, 2 * i, lo, mid, a, b, x);
  sett(st, 2 * i + 1, mid + 1, hi, a, b, x);
  st[i].sum = st[2 * i].sum + st[2 * i + 1].sum;
}

void add(vector<node>& st, int i, int lo, int hi, int a, int b, int x) {
  lazy(st, i, lo, hi);
  if (b < lo || a > hi)
    return;
  if (lo >= a && hi <= b) {
    st[i].add = x;
    lazy(st, i, lo, hi);
    return;
  }
  int mid = (lo + hi) / 2;
  add(st, 2 * i, lo, mid, a, b, x);
  add(st, 2 * i + 1, mid + 1, hi, a, b, x);
  st[i].sum = st[2 * i].sum + st[2 * i + 1].sum;
}

ll sum(vector<node>& st, int i, int lo, int hi, int a, int b) {
  lazy(st, i, lo, hi);
  if (b < lo || a > hi)
    return 0;
  if (lo >= a && hi <= b) {
    return st[i].sum;
  }
  int mid = (lo + hi) / 2;
  ll r1 = sum(st, 2 * i, lo, mid, a, b);
  ll r2 = sum(st, 2 * i + 1, mid + 1, hi, a, b);
  return r1 + r2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  vector<node> ST(4 * n);
  FORI(n) {
    int a;
    cin >> a;
    sett(ST, 1, 0, n - 1, i, i, a);
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b, x;
      cin >> a >> b >> x;
      a--;
      b--;
      add(ST, 1, 0, n - 1, a, b, x);
    } else if (t == 2) {
      int a, b, x;
      cin >> a >> b >> x;
      a--;
      b--;
      sett(ST, 1, 0, n - 1, a, b, x);
    } else {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      cout << sum(ST, 1, 0, n - 1, a, b) << endl;
    }
  }
}