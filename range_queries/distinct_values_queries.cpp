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

  vi compr;

  FORI(n) {
    cin >> X[i];
    compr.push_back(X[i]);
  }
  FORI(q) {
    cin >> Q[i].a >> Q[i].b;
    Q[i].i = i;
    Q[i].a--;
    Q[i].b--;
  }
  int BLOCK = 500;
  sort(Q.begin(), Q.end(), [BLOCK](query q1, query q2) -> bool {
    if (q1.a / BLOCK < q2.a / BLOCK)
      return true;
    if (q1.a / BLOCK > q2.a / BLOCK)
      return false;
    return q1.b < q2.b;
  });

  sort(compr.begin(), compr.end());
  compr.erase(unique(compr.begin(), compr.end()), compr.end());

  auto compf = [&compr](int i) -> int {
    return lower_bound(compr.begin(), compr.end(), i) - compr.begin();
  };

  FORI(n) { X[i] = compf(X[i]); }

  vi sett(compr.size());

  vi toclear;

  int lastblock = -1;
  int nextright = -1;
  int currentuniqcnt;
  for (query& q : Q) {
    if (q.a / BLOCK != lastblock) {
      lastblock = q.a / BLOCK;
      nextright = (lastblock + 1) * BLOCK;
      currentuniqcnt = 0;
      for (int i : toclear)
        sett[i] = 0;
      toclear.clear();
    }

    for (int i = q.a; i <= min(q.b, (lastblock + 1) * BLOCK - 1); i++) {
      int cval = X[i];
      if (sett[cval] == 0)
        currentuniqcnt++;
      sett[cval]++;
    }

    for (; nextright <= q.b; nextright++) {
      int cval = X[nextright];
      toclear.push_back(cval);
      if (sett[cval] == 0)
        currentuniqcnt++;
      sett[cval]++;
    }
    q.res = currentuniqcnt;

    for (int i = q.a; i <= min(q.b, (lastblock + 1) * BLOCK - 1); i++) {
      int cval = X[i];
      if (sett[cval] == 1)
        currentuniqcnt--;
      sett[cval]--;
    }
  }

  sort(Q.begin(), Q.end(),
       [](query q1, query q2) -> bool { return q1.i < q2.i; });
  for (query& q : Q)
    cout << q.res << '\n';
}