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

bool compute(int k, int *A, int *B, int al, int bl, int *R) {
    int a = 1, b = 1;
    for (int i = 1; i <= al+bl;) {
        if (A[a] == 0) {
            k++;
            R[i++] = A[a++];
            continue;
        }
        if (B[b] == 0) {
            k++;
            R[i++] = B[b++];
            continue;
        }
        if (A[a] > 0 && A[a] <= k) {
            R[i++] = A[a++];
            continue;
        }
        if (B[b] > 0 && B[b] <= k) {
            R[i++] = B[b++];
            continue;
        }
        if (a <= al && A[a] > k) {
            return false;
        }
        if (b <= bl && B[b] > k) {
            return false;
        }
    }
    return true;
}

void solve() {
    int k, m, n;
    cin >> k >> n >> m;
    int AN[200] = {}, AM[200] = {}, R[500] = {};

    fill(AN, AN+200, -1);
    fill(AM, AM+200, -1);
    
    FORL(i, 1, n) {
        cin >> AN[i];
    }
    FORL(i, 1, m) {
        cin >> AM[i];
    }

    bool found = compute(k, AN, AM, n, m, R);
    if (!found) cout << -1 << endl;
    else DEBUGARR(R, 1, n+m);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    FOR(i, tc)
        solve();

    return 0;
}

