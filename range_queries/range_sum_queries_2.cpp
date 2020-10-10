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

inline ll pos_mod(ll i, ll n) { return (i % n + n) % n; }
#define FORI(n) for (int i = 0; i < (n); i++)
#define FORJ(n) for (int j = 0; j < (n); j++)
#define FORK(n) for (int k = 0; k < (n); k++)
#define MOD 1000000007

vll ST;

ll sum(int i, int ia, int ib, int a, int b) {
    if (ia == a && ib == b)
        return ST[i];
    int im = (ia + ib) / 2;
    if (b <= im)
        return sum(2 * i, ia, im, a, b);
    if (a > im)
        return sum(2 * i + 1, im + 1, ib, a, b);
    return sum(2 * i, ia, im, a, im) + sum(2 * i + 1, im + 1, ib, im + 1, b);
}

void add(int i, int ia, int ib, int t, int x) {
    if (ia == ib) {
        ST[i] = x;
        return;
    }
    int im = (ia + ib) / 2;
    if (t <= im)
        add(2 * i, ia, im, t, x);
    else
        add(2 * i + 1, im + 1, ib, t, x);
    ST[i] = ST[2 * i] + ST[2 * i + 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;
    ST = vll(4 * n);
    FORI(n) {
        int x;
        cin >> x;
        add(1, 0, n - 1, i, x);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 2) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            cout << sum(1, 0, n - 1, a, b) << endl;
        } else {
            int k, u;
            cin >> k >> u;
            k--;
            add(1, 0, n - 1, k, u);
        }
    }
}