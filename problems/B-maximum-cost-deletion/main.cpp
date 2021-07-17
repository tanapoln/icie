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

int input[101] = {0};
int n, a, b;

void readStringInput() {
    string s;
    cin >> s;

    int pos = 0;

    FORL(i, 0, 100) {
        input[i] = 0;
    }

    FOREACH(c, s) {
        if (pos % 2 == 0) { //expect 0
            if (*c != '0') {
                pos++;
            }
        } else { //expect 1
            if (*c != '1') {
                pos++;
            }
        }
        input[pos]++;
    }
}

void solve() {
    cin >> n >> a >> b;
    readStringInput();

    if (b >= 0) {
        cout << (a*n)+(b*n) << endl;
        return;
    }

    int c0 = 0, c1 = 0;

    FORL(i, 0, n) {
        if (input[i] > 0) {
            if (i%2 == 0) c0++;
            else c1++;
        }
    }

    // cout << "c0:" << c0 << " c1:" << c1 << endl << "====" << endl;

    if (c0 < c1) {
        cout << (a*n)+(b*c0)+b << endl;
    } else {
        cout << (a*n)+(b*c1)+b << endl;
    }

}

int main() {    
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    FOR(i, tc)
        solve();

    return 0;
}

