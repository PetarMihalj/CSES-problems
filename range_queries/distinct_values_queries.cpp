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

struct query {
  int i, a, b, res;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, q;
  cin >> n >> q;

  vector<int> X(n);
  vector<query> Q(q);

  int ind = 1;
  set<int> vals;
  unordered_map<int, int> compr;

  FORI(n) {
    cin >> X[i];
    vals.insert(X[i]);
  }
  FORI(q) {
    cin >> Q[i].a >> Q[i].b;
    Q[i].i = i;
    Q[i].a--;
    Q[i].b--;
    vals.insert(Q[i].a - 1);
    vals.insert(Q[i].b);
  }

  for (int i : vals)
    compr[i] = ind++;

  vi pref(compr.size() + 1);
  FORI(n) { pref[compr[X[i]]] = 1; }
  FORI(pref.size() - 1) pref[i + 1] += pref[i];

  for (query q : Q) {
    cout << pref[compr[q.b]] - pref[compr[q.a - 1]] << endl;
  }
}