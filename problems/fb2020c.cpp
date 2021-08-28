#include <bits/stdc++.h>

#define FOR(a, c) for (int a = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int a = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int a = (b); (a) >= (c); (a)--)
#define PI 3.1415926535897932384626433832795
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define FOREACHR(it, l) for (auto it = l.rbegin(); it != l.rend(); it++)
#define pb push_back
#define MP make_pair
#define abs(a) ((a) < 0 ? -(a) : (a))
#define max(a, b) ((a) < (b) ? (b) : (a))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define MOD (1e9+7)
#define divceil(n, d) (((n)/(d)) + ((n)%(d) > 0 ? 1 : 0))
#define DEBUGARR(arr, s, e) {FORL(i, s, e){ cout << arr[i] << " "; } cout << endl;}
#define DEBUGVEC(vec) {FOREACH(it, vec){ cout << *it << " "; } cout << endl;}

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;

#define MAX 1200000000
#define BASE 500000000
#define N 900000

typedef struct {
    int p, h;
} tree;

tree make_tree(int p, int h) {
    tree i;
    i.p = p;
    i.h = h;
    return i;
}

bool cmp(tree i1, tree i2) {
    return i1.p < i2.p;
}

tree *T = (tree*) malloc(sizeof(tree) * N);

unordered_map<int, int> compute_right(tree *tr, int n) {
    int last_n = 0;
    unordered_map<int, int> len;

    FOR(i, n) {
        auto t = tr[i];
        int tpos = t.p+t.h;
        int new_len = len[t.p]+t.h;
        int exist_len = len[tpos];

        if (new_len > exist_len) {
            len[tpos] = new_len;
            last_n = i;
        }
    }
    return len;
}

unordered_map<int, int> compute_left(tree *tr, int n) {
    unordered_map<int, int> len;

    FORR(i, n-1, 0) {
        auto t = tr[i];
        int tpos = t.p-t.h;
        int new_len = len[t.p]+t.h;
        int exist_len = len[tpos];

        if (new_len > exist_len) {
            len[tpos] = new_len;
        }
    }
    return len;
}

void solve(int no) {
    int n;
    cin >> n;

    FOR(i, n) {
        int p, h;
        cin >> p >> h;
        T[i] = make_tree(p, h);
    }

    sort(T, T+n, cmp);


    auto right = compute_right(T, n);
    auto left = compute_left(T, n);

    int res = 0;

    for (auto &kv : right) {
        res = max(res, kv.second + left[kv.first]);
    }
    for (auto &kv : left) {
        res = max(res, kv.second);
    }

    cout << "Case #" << no+1 << ": " << res << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    FOR(i, tc) {
        solve(i);
    }

    return 0;
}