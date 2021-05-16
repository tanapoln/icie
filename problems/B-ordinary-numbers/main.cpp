#include <bits/stdc++.h>

#define FOR(a, c) for (int a = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int a = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int a = (b); (a) >= (c); (a)--)
#define PI 3.1415926535897932384626433832795
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define pb push_back
#define MP make_pair
#define max(a, b) ((a) < (b) ? (b) : (a))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define MOD (1e9+7)
#define divceil(n, d) (((n)/(d)) + ((n)%(d) > 0 ? 1 : 0))
#define DEBUGARR(arr, s, e) {FORL(i, s, e){ cout << arr[i] << " "; } cout << endl;}

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

vector<ll> vals;

void solve() {
    ll n;
    cin >> n;

    int c = 0;
    FOREACH(it, vals) {
        if (*it <= n) c++;
    }

    cout << c << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    FORL(i, 1, 9) {
        vals.pb(i);
    }
    FORL(d, 1, 9) {
        FORL(i, 1, 9) {
            ll v = i;
            FOR(k, d) {
                v = v * 10 + i;
            }
            vals.pb(v);
        }
    }

    // FOREACH(it, vals) {
    //     cout << *it << " ";
    // }
    // cout << endl;


    int tc; cin >> tc;
    FOR(i, tc)
        solve();

    return 0;
}

