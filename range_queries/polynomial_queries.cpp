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
  ll running_adds;
  ll constant_adds;
};

void lazy(vector<node>& st, int i, int lo, int hi) {
  st[i].sum += (ll)(hi - lo + 1) * (hi - lo + 2) / 2 * st[i].running_adds +
               st[i].constant_adds * (hi - lo + 1);

  int mid = (hi + lo) / 2;

  if (lo != hi) {
    st[2 * i].constant_adds += st[i].constant_adds;
    st[2 * i].running_adds += st[i].running_adds;
    st[2 * i + 1].constant_adds +=
        st[i].constant_adds + st[i].running_adds * (mid + 1 - lo);
    st[2 * i + 1].running_adds += st[i].running_adds;
  }

  st[i].running_adds = 0;
  st[i].constant_adds = 0;
}

void add(vector<node>& st,
         int i,
         int lo,
         int hi,
         int a,
         int b,
         ll running,
         ll constant) {
  lazy(st, i, lo, hi);
  if (b < lo || a > hi)
    return;
  if (lo >= a && hi <= b) {
    st[i].running_adds = running;
    st[i].constant_adds = constant;
    lazy(st, i, lo, hi);
    return;
  }
  int mid = (lo + hi) / 2;
  add(st, 2 * i, lo, mid, a, b, running, constant);
  add(st, 2 * i + 1, mid + 1, hi, a, b, running,
      constant + running * max(mid - max(a, lo) + 1, 0));
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

void build(vector<node>& st, vector<int>& elements, int i, int lo, int hi) {
  if (lo == hi) {
    st[i].sum = elements[lo];
  } else {
    int mid = (lo + hi) / 2;
    build(st, elements, 2 * i, lo, mid);
    build(st, elements, 2 * i + 1, mid + 1, hi);
    st[i].sum = st[2 * i].sum + st[2 * i + 1].sum;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;

  vector<node> ST(4 * n);
  vector<int> elements(n);
  FORI(n) { cin >> elements[i]; }
  build(ST, elements, 1, 0, n - 1);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      add(ST, 1, 0, n - 1, a, b, 1, 0);
    } else {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      cout << sum(ST, 1, 0, n - 1, a, b) << endl;
    }
  }
}