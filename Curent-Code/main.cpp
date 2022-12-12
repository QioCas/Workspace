#define console(...) void() // 2022/12/11-21:08:08
#define READ // Files
#define CHECK // Check
#include "bits/stdc++.h" // QioCas
using namespace std;
using ll = long long;
const ll inf = ll(2e18), mod = 1e9 + 7, LOG = ' ', maxN = 200005;
template<int MOD = mod> struct mint{
private:
    // Internal, DO NOT USE. Val must be int [0, 2 * MOD)
    constexpr inline __attribute__((always_inline)) mint& _set(ll v) {
        x = (v >= MOD ? v - MOD : v);
        return *this;
    }
public:
    ll x = ll();
    constexpr mint(ll val = ll()) { _set(val % MOD + MOD); }
    constexpr static int mod() { return MOD; }
    // +, -, *, /
    constexpr mint operator + (const mint& other) const { return mint()._set(x + other.x); }
    constexpr mint operator - (const mint& other) const { return mint()._set(x - other.x + MOD); }
    constexpr mint operator * (const mint& other) const { return mint()._set(x * other.x % MOD); }
    constexpr mint operator / (const mint& other) const { return mint()._set(x * other.inv().x % MOD); }
    constexpr mint operator - () const { return mint()._set(MOD - x); }
    friend constexpr mint operator + (ll a, const mint& other) { return mint()._set(a % MOD + other.x); }
    friend constexpr mint operator - (ll a, const mint& other) { return mint()._set(a % MOD - other.x + MOD); }
    friend constexpr mint operator * (ll a, const mint& other) { return mint()._set(a % MOD * other.x % MOD); }
    friend constexpr mint operator / (ll a, const mint& other) { return mint()._set(a % MOD * other.inv().x % MOD); }

    // +=, -=, *=, /=
    constexpr mint operator += (const mint& other) { return *this = *this + other;}
    constexpr mint operator -= (const mint& other) { return *this = *this - other;}
    constexpr mint operator *= (const mint& other) { return *this = *this * other;}
    constexpr mint operator /= (const mint& other) { return *this = *this / other;}
    
    // ==, !=
    constexpr bool operator == (const mint& other) const { return x == other.x; }
    constexpr bool operator != (const mint& other) const { return x != other.x; }

    // cin, cout
    friend istream& operator >> (istream& cin, mint& c) {
        ll val; cin >> val; c = mint(val);
        return cin;
    }
    constexpr friend ostream& operator << (ostream& cout, const mint& c) {
        return cout << c.x;
    }
    
    constexpr mint pow(ll k) const {
        mint ans = 1, tmp = x;
        while(k > 0) {
            if(k & 1) ans *= tmp;
            tmp *= tmp;
            k >>= 1;
        } 
        return ans;
    }

    static vector<mint> fac, invfac, invs;
    constexpr static void precal(int n) {
        if(n > MOD) n = MOD;
        int old_size = fac.size();
        if(n <= old_size) return;
        fac.resize(n); invfac.resize(n); invs.resize(n);
        for(int i = old_size; i < n; ++i) fac[i] = fac[i - 1] * ll(i);
        invfac[n - 1] = fac.back().pow(MOD - 2);
        for(int i = n - 2; i >= old_size; --i) invfac[i] = invfac[i + 1] * ll(i + 1);
        for(int i = n - 1; i >= old_size; --i) invs[i] = invfac[i] * fac[i - 1];
    }

    constexpr mint inv() const {
        if(x < 1000001) {
            precal(1000001);
            return invs[x];
        }
        ll a = x, b = MOD, ax = 1, bx = 0;
        while(b > 0) {
            int q = a / b, t = a % b;
            a = b, b = t;
            t = ax - bx * q;
            ax = bx, bx = t;
        }
        assert(a == 1);
        if(ax < 0) ax += MOD;
        return mint(ax);
    }
    static int get_primitive_root() {
        static int primitive_root = 0;
        if (!primitive_root) {
            primitive_root = [&]() {
                std::set<int> fact;
                int v = MOD - 1;
                for (ll i = 2; i * i <= v; i++)
                    while (v % i == 0) fact.insert(i), v /= i;
                if (v > 1) fact.insert(v);
                for (int g = 1; g < MOD; g++) {
                    bool ok = true;
                    for (auto i : fact)
                        if (mint(g).pow((MOD - 1) / i) == 1) {
                            ok = false;
                            break;
                        }
                    if (ok) return g;
                }
                return -1;
            }();
        }
        return primitive_root;
    }
}; // mint
template <int MOD> std::vector<mint<MOD>> mint<MOD>::fac = {1};
template <int MOD> std::vector<mint<MOD>> mint<MOD>::invfac = {1};
template <int MOD> std::vector<mint<MOD>> mint<MOD>::invs = {0};

int n, m;

mint<mod> a[maxN];
struct Data{
    struct Node{
        // A * x + B
        mint<mod> x = 0, A = 1, B = 0;
        mint<mod> get() { return A * x + B; }
    } val, lz;

    Data(mint<mod> _x = 0) { val.x = _x; }
    friend Data operator+ (Data u, Data v) {
        return Data(u.val.get() + v.val.get());
    }
} st[maxN * 4];
void down(int id, int left, int right) {
    Data &root = st[id], &L = st[id << 1], &R = st[id << 1 | 1];
    int mid = (left + right) >> 1;
    if(root.lz.x != 0) {
        L.val = {(mid - left + 1) * root.lz.x, 1, 0};
        L.lz = {root.lz.x, 1, 0};
        R.val = {(right - (mid + 1) + 1) * root.lz.x, 1, 0};
        R.lz = {root.lz.x, 1, 0};
        root.lz.x = 0;
    }
    if(root.lz.A != 1) {
        L.val.A *= root.lz.A, L.val.B *= root.lz.A;
        L.lz.A *= root.lz.A, L.lz.B *= root.lz.A;
        R.val.A *= root.lz.A, R.val.B *= root.lz.A;
        R.lz.A *= root.lz.A, R.lz.B *= root.lz.A;
        root.lz.A = 1;
    }
    if(root.lz.B != 0) {
        L.val.B += (mid - left + 1) * root.lz.B;
        L.lz.B += root.lz.B;
        R.val.B += (right - (mid + 1) + 1) * root.lz.B;
        R.lz.B += root.lz.B;
        root.lz.B = 0;
    }
}

void build(int id, int left, int right) {
    if(left == right) return st[id] = Data(a[left]), void();
    int mid = (left + right) >> 1;
    build(id << 1, left, mid);
    build(id << 1 | 1, mid + 1, right);
    st[id] = st[id << 1] + st[id << 1 | 1];
}
void update_assign(int id, int left, int right, int sta, int endo, mint<mod> U) {
    if(left > endo or right < sta) return void();
    if(sta <= left and right <= endo) {
        st[id].val = {(right - left + 1) * U, 1, 0};
        st[id].lz = {U, 1, 0};
        return void();
    }
    int mid = (left + right) >> 1;
    down(id, left, right);
    update_assign(id << 1, left, mid, sta, endo, U);
    update_assign(id << 1 | 1, mid + 1, right, sta, endo, U);
    st[id] = st[id << 1] + st[id << 1 | 1];
}
void update_mul(int id, int left, int right, int sta, int endo, mint<mod> U) {
    if(left > endo or right < sta) return void();
    if(sta <= left and right <= endo) {
        st[id].val.A *= U, st[id].val.B *= U;
        st[id].lz.A *= U, st[id].lz.B *= U;
        return void();
    }
    int mid = (left + right) >> 1;
    down(id, left, right);
    update_mul(id << 1, left, mid, sta, endo, U);
    update_mul(id << 1 | 1, mid + 1, right, sta, endo, U);
    st[id] = st[id << 1] + st[id << 1 | 1];
}

void update_plus(int id, int left, int right, int sta, int endo, mint<mod> U) {
    if(left > endo or right < sta) return void();
    if(sta <= left and right <= endo) {
        st[id].val.B += (right - left + 1) * U;
        st[id].lz.B += U;
        return void();
    }
    int mid = (left + right) >> 1;
    down(id, left, right);
    update_plus(id << 1, left, mid, sta, endo, U);
    update_plus(id << 1 | 1, mid + 1, right, sta, endo, U);
    st[id] = st[id << 1] + st[id << 1 | 1];
}
mint<mod> query(int id, int left, int right, int sta, int endo) {
    if(left > endo or right < sta) return 0;
    if(sta <= left and right <= endo) return st[id].val.get();
    int mid = (left + right) >> 1;
    down(id, left, right);
    return query(id << 1, left, mid, sta, endo) + query(id << 1 | 1, mid + 1, right, sta, endo);
}
void segment_tree() {
    for(int i = 1; i <= n; ++i)
        cerr << query(1, 1, n, i, i) << ' ';
    cerr << '\n';
}
signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    build(1, 1, n);
    for(int i = 1; i <= m; ++i) {
        int tt; cin >> tt;
        int L, R; mint<mod> C;
        if(tt == 1) {
            cin >> L >> R >> C;
            update_plus(1, 1, n, L, R, C);
        } else if(tt == 2){
            cin >> L >> R >> C;
            update_mul(1, 1, n, L, R, C);
        } else if(tt == 3){
            cin >> L >> R >> C;
            update_assign(1, 1, n, L, R, C);
        } else if(tt == 4) {
            cin >> L >> R;
            cout << query(1, 1, n, L, R) << '\n';
        } else assert(false);
        // segment_tree();
    }
}
