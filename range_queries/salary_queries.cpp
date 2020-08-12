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

struct query {
  int k, x, a, b;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;
  vi P(n);
  vi compr;
  vector<query> Q;

  FORI(n) {
    cin >> P[i];
    compr.push_back(P[i]);
  }
  FORI(q) {
    char c;
    cin >> c;
    if (c == '!') {
      int k, x;
      cin >> k >> x;
      k--;
      Q.push_back({k, x, -1, -1});
      compr.push_back(x);
    } else {
      int a, b;
      cin >> a >> b;
      compr.push_back(a - 1);
      compr.push_back(b);
      Q.push_back({-1, -1, a, b});
    }
  }
  sort(compr.begin(), compr.end());
  compr.erase(unique(compr.begin(), compr.end()), compr.end());

  auto compf = [&compr](int i) -> int {
    return lower_bound(compr.begin(), compr.end(), i) - compr.begin() + 1;
  };

  vi ft(compr.size() + 1);
  FORI(n) add(ft, compf(P[i]), 1);

  for (query q : Q) {
    if (q.a == -1) {
      add(ft, compf(P[q.k]), -1);
      P[q.k] = q.x;
      add(ft, compf(P[q.k]), 1);
    } else {
      cout << sum(ft, compf(q.b)) - sum(ft, compf(q.a - 1)) << '\n';
    }
  }
}