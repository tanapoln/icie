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
#define DEBUGARR(arr, s, e) {FORL(_i, s, e){ cout << arr[_i] << " "; } cout << endl;}
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

void solve(int caseNo) {
    int n;
    int o_row[51] = {0};
    int o_col[51] = {0};
    int e_row[51] = {0};
    int e_col[51] = {0};
    int G[51][51] = {0};
    FOR(i, 51) fill(G[i], G[i]+51, 0);

    cin >> n;
    FOR(i, n) {
        string s;
        cin >> s;
        FOR(k, s.length()) {
            if (s[k] == '.') {
                e_row[i]++;
                e_col[k]++;
                G[i][k] = '.';
            }
            if (s[k] == 'O') {
                o_row[i]++;
                o_col[k]++;
            }
        }
    }

    int min_e = 100000;
    FOR(i, n) {
        if (o_row[i] == 0) min_e = min(min_e, e_row[i]);
        if (o_col[i] == 0) min_e = min(min_e, e_col[i]);
    }

    if (min_e == 100000) {
        cout << "Case #" << caseNo << ": Impossible" << endl;
        return;
    }

    int C[51][51] = {};
    FOR(i, 51) fill(C[i], C[i]+51, 0);
    int types = 0;
    FOR(i, n) {
        if (e_row[i] == min_e && o_row[i] == 0) {
            FOR(k, n) {
                if (G[i][k] == '.' && C[i][k] == 0) {
                    C[i][k] = 1;
                    types++;
                    break;
                }
            }
        }
        if (e_col[i] == min_e && o_col[i] == 0) {
            FOR(k, n) {
                if (G[k][i] == '.' && C[k][i] == 0) {
                    C[k][i] = 1;
                    types++;
                    break;
                }
            }
        };
    }

    cout << "Case #" << caseNo << ": " << min_e << " " << types << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    FOR(i, tc)
        solve(i+1);

    return 0;
}
