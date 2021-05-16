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

int abs(int i) {
    if (i < 0) return -i;
    return i;
}

void solve() {
    ll r, b, d, dp, hp, l, h;

    cin >> r >> b >> d;

    if (r < b) {
        l = r;
        h = b;
    } else {
        l = b;
        h = r;
    }

    dp = d+1;
    hp = l * dp;

    // cout << "hp:" << hp << " l:" << l << " h:" << h << " diff:" << hp-h << " ";

    ll diff = hp - h;
    if (diff >= 0) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    FOR(i, tc)
        solve();

    return 0;
}

