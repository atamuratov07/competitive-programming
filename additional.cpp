// standard templates library
#include <bits/stdc++.h>
// faster stl implementation
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// ==========================================================================================================================

template <typename t>
using oset = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

#define ar array
#define vt vector

typedef long long ll;
typedef long double ld;
typedef vt<int> vi;
typedef vt<vi> vvi;
typedef vt<ll> vl;
typedef vt<vl> vvl;

#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define SQR(x) ((ll)(x) * (x))
#define RESET(a, b) memset(a, b, sizeof(a))

#define all(c) (c).begin(), (c).end()
#define len(x) (int)(x).size()
#define SORT(v) sort(all(v))
#define REVERSE(v) reverse(all(v))

#define TC(t) while (t--)
#define EACH(i, a) for (auto &(i) : (a))

#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (b) : i > (b); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

void DBG() {
   cerr << "]" << endl;
}
template <class H, class... T> void DBG(H h, T... t) {
   cerr << to_string(h);
   if (sizeof...(t)) cerr << ", ";
   DBG(t...);
}
#ifdef _DEBUG
#define dbg(...) cerr << "LINE(" << __LINE__ << ") -> [" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#else
#define dbg(...) 0
#endif
// ===================================================================================================

template <class T> void offset(ll o, T &x) {
   x += o;
}
template <class T> void offset(ll o, vt<T> &x) {
   EACH(a, x) offset(o, a);
}
template <class T, size_t S> void offset(ll o, ar<T, S> &x) {
   EACH(a, x) offset(o, a);
}

mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
ll randint(ll a, ll b) {
   return uniform_int_distribution<ll>(a, b)(mt_rng);
}

template <class T, class U> void vti(vt<T> &v, U x, size_t n) {
   v = vt<T>(n, x);
}
template <class T, class U> void vti(vt<T> &v, U x, size_t n, size_t m...) {
   v = vt<T>(n);
   EACH(a, v) vvti(a, x, m);
}

const int d4i[4] = {-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};
const int d8i[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, d8j[8] = {0, 1, 1, 1, 0, -1, -1, -1};

const string DIRS = "NESW";
int DIRS2[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, m;
vt<string> g;
string ans;

bool canGo(int i, int j) {
   return i >= 0 && i < n && j >= 0 && j < m && g[i][j] == '*';
}

void dfs(int i = 0, int j = 0) {
   // DBG(i, j);
   g[i / 2][j / 2] = '#';
   int i2 = i & 1, j2 = j & 1, k = i2 ? 3 - j2 : j2;
   int ck = k;
   do {
      int ni = i + DIRS2[ck][0], nj = j + DIRS2[ck][1];
      if (canGo(ni / 2, nj / 2)) {
         ans += DIRS[ck];
         dfs(ni, nj);
         ans += DIRS[ck ^ 2];
      } else {
         ans += DIRS[(ck + 1) % 4];
      }
      i += DIRS2[(ck + 1) % 4][0];
      j += DIRS2[(ck + 1) % 4][1];
      ck = (ck + 1) % 4;
   } while (ck ^ k);
   ans.pop_back();
}