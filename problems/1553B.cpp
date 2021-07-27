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

string rev(string t) {
    string tr(t);
    reverse(tr.begin(), tr.end());
    return tr;
}

bool find(string s, string t) {
    return s.find(t) != string::npos;
}

void solve() {
    string s, t;
    cin >> s >> t;

    if (find(s, t) || find(s, rev(t))) {
        cout << "YES" << endl;
        return;
    }

    int tl = t.length();
    while (tl >= 1) {
        string sub = t.substr(0, tl);
        int start = 0;

        while(1) {
            int p = s.find(sub, start);
            if (p == string::npos) break;

            // cout << "======" << endl;
            // cout << "SUB:" << sub << " pos:" << p << endl;

            int r = p+tl-2;
            int k = tl;
            while (1) {
                if (k >= t.length() || r < 0) break;

                // cout << "matching:" << t[k] << " with:" << s[r] << " @s:" << r << " @t:" << k << endl;
                if (s[r] == t[k]) {
                    r--;k++;
                    continue;
                }

                break;
            }
            // cout << "checking k:" << k << " eq to len:" << t.length() << endl;
            if (k == t.length()) {
                cout << "YES" << endl;
                return;
            }

            start = p+1;
        }



        tl--;
    }

    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    FOR(i, tc)
        solve();

    return 0;
}
