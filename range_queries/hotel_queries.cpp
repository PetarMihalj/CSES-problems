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
  int n, m;
  cin >> n >> m;
  vi X(n);
  vi B(n / BLOCK + 1, 0);
  FORI(n) {
    cin >> X[i];
    B[i / BLOCK] = max(B[i / BLOCK], X[i]);
  }

  while (m--) {
    int r;
    cin >> r;
    int a = 0;
    while (a < n && B[a / BLOCK] < r)
      a += BLOCK;
    if (a >= n)
      cout << "0 ";
    else {
      while (X[a] < r)
        a++;
      cout << (a + 1) << ' ';
      X[a] -= r;
      int blockres = 0;
      for (int i = (a / BLOCK) * BLOCK; i < min((a / BLOCK + 1) * BLOCK, n);
           i++) {
        blockres = max(blockres, X[i]);
      }
      B[a / BLOCK] = blockres;
    }
  }
}