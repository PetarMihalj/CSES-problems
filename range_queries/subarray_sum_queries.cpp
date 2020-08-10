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
  ll sum, msl, msr, ms;
};

void update(vector<node>& ST, int i, int lo, int hi, int k, int x) {
  if (k < lo || k > hi)
    return;
  else if (lo == hi) {
    ST[i] = {x, x, x, x};
    return;
  }
  int mid = (lo + hi) / 2;
  update(ST, 2 * i, lo, mid, k, x);
  update(ST, 2 * i + 1, mid + 1, hi, k, x);

  ST[i].ms = max(ST[2 * i].msr + ST[2 * i + 1].msl,
                 max(ST[2 * i].ms, ST[2 * i + 1].ms));
  ST[i].msl = max(ST[2 * i].msl, ST[2 * i].sum + ST[2 * i + 1].msl);
  ST[i].msr = max(ST[2 * i + 1].msr, ST[2 * i + 1].sum + ST[2 * i].msr);
  ST[i].sum = ST[2 * i].sum + ST[2 * i + 1].sum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;

  vector<node> ST(4 * n);
  FORI(n) {
    int x;
    cin >> x;
    update(ST, 1, 0, n - 1, i, x);
  }
  FORI(m) {
    int k, x;
    cin >> k >> x;
    update(ST, 1, 0, n - 1, k - 1, x);
    cout << max(ST[1].ms, 0LL) << '\n';
  }
}