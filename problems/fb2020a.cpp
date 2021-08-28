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

void solve() {
    int N;
    cin >> N;

    int F[51][51] = {};

    string I, O;
    cin >> I >> O;

    FOR(p, N) {
        if (I[p] == 'N') {
            FORL(i, 0, p-1) {
                FORL(j, p, N) F[i][j]=1;
            }
            FORL(i, p+1, N) {
                FORL(j, 0, p) F[i][j]=1;
            }
        }
    }
    FOR(p, N) {
        if (O[p] == 'N') {
            FORL(i, 0, p-1) {
                FORL(j, p+1, N) F[i][j]=1;
            }
            FORL(j, 0, p-1) F[p][j]=1;
            FORL(j, p+1, N) F[p][j]=1;
            FORL(i, p+1, N) {
                FORL(j, 0, p-1) F[i][j]=1;
            }
        }
    }


    FORL(i, 0, N-1) {
        FORL(j, 0, N-1) {
            if (F[i][j] == 1) cout << "N";
            else cout << "Y";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    FOR(i, tc) {
        cout << "Case #" << i+1 << ":" << endl;
        solve();
    }

    return 0;
}
