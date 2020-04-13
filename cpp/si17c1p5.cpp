#pragma region
#include <bits/stdc++.h>
using namespace std;
// Common Type shorteners and int128
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using umap = unordered_map<K, V>; template <typename K> using uset = unordered_set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
#ifdef __SIZEOF_INT128__
using int128 = __int128_t; using uint128 = __uint128_t;
#endif
template<typename I> string intStr(I x) { string ret; while (x > 0) { ret += (x % 10) + '0'; x /= 10; } reverse(ret.begin(), ret.end()); return ret; } // Int to string
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define mtup make_tuple
#define pb push_back
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
#define finline __attribute__((always_inline))
// Shorthand Function Macros
#define sz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (__typeof(a) i = a; i < b; i++)
#define reprev(i, a, b) for (__typeof(a) i = a; i > b; i--)
#define repi(a, b) rep(i, a, b)
#define repj(a, b) rep(j, a, b)
#define repk(a, b) rep(k, a, b)
#define Cmplt(type) bool operator<(const type &o) const
#define Cmpgt(type) bool operator>(const type &o) const
#define Cmpfn(name, type) bool name(const type &a, const type &b)
#define Inop(type) istream& operator>>(istream& in, type &o)
#define Outop(type) ostream& operator<<(ostream& out, type o)
#define Pow2(x) (1LL << (x))
#define scn(type, ...) type __VA_ARGS__; scan(__VA_ARGS__) // scn -> Short for SCan New
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
inline void setprec(ostream& out, int prec) { out << setprecision(prec) << fixed; }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> string arrayStr(T *arr,int sz){string ret = "[";for(int i=0;i<sz;i++){ret+=to_string(arr[i])+", "; } return ret + "]";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
template <typename F> inline void println(F t){cout<<t<<'\n';}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
#define db(x) cout << (#x) << ": " << (x) << ", "
#define dblb(s) cout << "[" << (s) << "] "
#define dba(alias, x) cout << (alias) << ": " << (x) << ", "
template<typename F> inline string __generic_tostring(F f) { stringstream ss; ss << f; return ss.str(); }
template<typename F> inline string __join_comma(F f) {return __generic_tostring(f);}
template<typename F, typename... R> string __join_comma(F f, R... r) { return __generic_tostring(f) + ", " + __join_comma(r...); }
#define dbp(alias, ...) cout << (alias) << ": (" << __join_comma(__VA_ARGS__) << "), "
#define dbbin(x, n) cout << (#x) << ": " << bitset<n>(x) << ", "
#define dbarr(x, n) cout << (#x) << ": " << arrayStr((x), (n)) << ", "
#define dbln cout << endl;
#pragma endregion

using VecType = ll;
constexpr ll MOD = 1e9;
constexpr bool USE_MOD = true;

using Vec = vector<VecType>; using Mat = vector<Vec>;
void init(Mat &m, int N) {
    m.resize(N);
    for (int i = 0; i < N; i++) m[i].assign(N, 0);
}
void init(Vec &v, int N) { v.assign(N, 0); }
void init_identity(Mat &m, int N) {
    init(m, N);
    for (int i = 0; i < N; i++) m[i][i] = 1;
}
void mul(Mat &res, const Mat &a, const Mat &b) {
    int N = a.size();
    init(res, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                res[i][j] += a[i][k] * b[k][j]; if (USE_MOD) { res[i][j] %= MOD; } } } }
}
void mul(Vec &res, const Mat &m, const Vec &v) {
    int N = m.size();
    init(res, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            res[i] += m[i][j] * v[j]; if (USE_MOD) { res[i] %= MOD; } } }
}
Mat mul(const Mat &a, const Mat &b) { Mat ret; mul(ret, a, b); return ret; }
Vec mul(const Mat &m, const Vec &v) { Vec ret; mul(ret, m, v); return ret; }
void exp(Mat &res, ll exp) {
    int N = res.size();
    Mat cpow = res; init_identity(res, N);
    for (ll cxp = 0; exp >> cxp; cxp++) {
        if ((exp >> cxp) & 1)
            res = mul(res, cpow);
        cpow = mul(cpow, cpow);
    }
}

ll N;
int a, b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scan(a, b, N);

	if (!N)
		println(a);
	else {
		Vec init{b, a}, ans(2);
		Mat m{{1, 1}, {1, 0}};
		exp(m, N - 1);
		mul(ans, m, init);
		println(ans[0]);
	}

	return 0;
}