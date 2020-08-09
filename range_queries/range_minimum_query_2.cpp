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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int BLOCK = 500;
  int n, q;
  cin >> n >> q;
  vi X(n);
  vi B(n / BLOCK + 1, MOD);
  FORI(n) {
    cin >> X[i];
    B[i / BLOCK] = min(B[i / BLOCK], X[i]);
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 2) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      int res = X[a];
      while (a % BLOCK != 0 && a <= b) {
        res = min(res, X[a]);
        a++;
      }
      while (b % BLOCK != (BLOCK - 1) && a <= b) {
        res = min(res, X[b]);
        b--;
      }
      while (a < b) {
        res = min(res, B[a / BLOCK]);
        a += BLOCK;
      }
      cout << res << endl;
    } else {
      int k, u;
      cin >> k >> u;
      k--;
      X[k] = u;
      int blockmin = u;
      for (int i = (k / BLOCK) * BLOCK; i < (k / BLOCK + 1) * BLOCK; i++) {
        blockmin = min(blockmin, X[i]);
      }
      B[k / BLOCK] = blockmin;
    }
  }
}