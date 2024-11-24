// standard templates library
#include <bits/stdc++.h>
// faster stl implementation
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
// =========================================================================

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

ll FIRSTTRUE(function<bool(ll)> f, ll lb, ll rb) {
   while (lb < rb) {
      ll mb = (lb + rb) / 2;
      f(mb) ? rb = mb : lb = mb + 1;
   }
   return lb;
}
ll LASTTRUE(function<bool(ll)> f, ll lb, ll rb) {
   while (lb < rb) {
      ll mb = (lb + rb + 1) / 2;
      f(mb) ? lb = mb : rb = mb - 1;
   }
   return lb;
}
// ===========================================================================

template <class A> void read(vt<A> &v);
template <class A, size_t S> void read(ar<A, S> &a);
template <class T> void read(T &x) {
   cin >> x;
}
void read(double &d) {
   string t;
   read(t);
   d = stod(t);
}
void read(ld &d) {
   string t;
   read(t);
   d = stold(t);
}
template <class H, class... T> void read(H &h, T &...t) {
   read(h);
   read(t...);
}
template <class A> void read(vt<A> &x) {
   EACH(a, x) read(a);
}
template <class A, size_t S> void read(array<A, S> &x) {
   EACH(a, x) read(a);
}
// =========================================================================

string to_string(char c) {
   return string(1, c);
}
string to_string(bool b) {
   return b ? "true" : "false";
}
string to_string(const char *s) {
   return string(s);
}
string to_string(string s) {
   return s;
}
string to_string(vt<bool> v) {
   string res;
   FOR(len(v)) res += char('0' + v[i]);

   return res;
}
template <size_t S> string to_string(bitset<S> b) {
   string res;
   FOR(S) res += char('0' + b[i]);

   return res;
}
template <class T> string to_string(T v) {
   bool f = 1;
   string res;
   EACH(x, v) {
      if (!f) res += ' ';
      f = 0;
      res += to_string(x);
   }
   return res;
}
// =========================================================================

template <class A> void write(A x) {
   cout << to_string(x);
}
template <class H, class... T> void write(const H &h, const T &...t) {
   write(h);
   write(t...);
}
void print() {
   write("\n");
}
template <class H, class... T> void print(const H &h, const T &...t) {
   write(h);
   if (sizeof...(t)) write(' ');

   print(t...);
}

// ========================================================================================================================
// ========================================================================================================================

void solve(int &n) {
   print(n);
   return;
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   int n;
   read(n);

   solve(n);
}
