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
  node *l, *r;
  ll sum;
};

node* create(vector<int>& X, int lo, int hi) {
  if (lo == hi)
    return new node{nullptr, nullptr, X[lo]};
  int mid = (lo + hi) / 2;
  auto n1 = create(X, lo, mid);
  auto n2 = create(X, mid + 1, hi);
  return new node{n1, n2, n1->sum + n2->sum};
}

ll sum(node* tree, int lo, int hi, int a, int b) {
  if (b < lo || a > hi)
    return 0;
  else if (a <= lo && hi <= b)
    return tree->sum;
  int mid = (lo + hi) / 2;
  return sum(tree->l, lo, mid, a, b) + sum(tree->r, mid + 1, hi, a, b);
}

node* update(node* tree, int lo, int hi, int k, int x) {
  if (lo == hi) {
    return new node{nullptr, nullptr, x};
  }
  int mid = (lo + hi) / 2;
  if (k <= mid) {
    node* nova = update(tree->l, lo, mid, k, x);
    return new node{nova, tree->r, nova->sum + tree->r->sum};
  } else {
    node* nova = update(tree->r, mid + 1, hi, k, x);
    return new node{tree->l, nova, nova->sum + tree->l->sum};
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, q;
  cin >> n >> q;
  vi X(n);
  FORI(n) cin >> X[i];

  map<int, node*> last;
  int nextarr = 2;
  last[1] = create(X, 0, n - 1);

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int k, a, x;
      cin >> k >> a >> x;
      last[k] = update(last[k], 0, n - 1, a - 1, x);
    } else if (t == 2) {
      int k, a, b;
      cin >> k >> a >> b;
      cout << sum(last[k], 0, n - 1, a - 1, b - 1) << endl;
    } else {
      int k;
      cin >> k;
      last[nextarr++] = last[k];
    }
  }
}