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

struct block {
  int lo, hi;
  vi items;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int BLOCK = 500;
  int n;
  cin >> n;
  vector<block> blocks(n / BLOCK + 1);
  FORI(n) {
    int x;
    cin >> x;
    block& my = blocks[i / BLOCK];
    if (my.items.size() == 0)
      my.lo = i;
    my.items.push_back(x);
    my.hi = i;
  }

  FORI(n) {
    int p;
    cin >> p;
    p--;
    int bind = 0;
    while (p < blocks[bind].lo || p > blocks[bind].hi) {
      bind++;
    }
    cout << blocks[bind].items[p - blocks[bind].lo] << ' ';
    blocks[bind].items.erase(blocks[bind].items.begin() + p - blocks[bind].lo);

    blocks[bind].hi--;
    for (int i = bind + 1; i < blocks.size(); i++) {
      blocks[i].lo--;
      blocks[i].hi--;
    }
  }
}