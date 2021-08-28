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
#define MOD (1e9 + 7)
#define divceil(n, d) (((n) / (d)) + ((n) % (d) > 0 ? 1 : 0))
#define DEBUGARR(arr, s, e)                      \
    {                                            \
        FORL(i, s, e) { cout << arr[i] << " "; } \
        cout << endl;                            \
    }
#define DEBUGVEC(vec)                            \
    {                                            \
        FOREACH(it, vec) { cout << *it << " "; } \
        cout << endl;                            \
    }

using namespace std;

typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef map<int, int> mii;
typedef set<int> si;

bool is_vovel(char c)
{
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

void solve(int caseNo)
{
    int V[100] = {}, C[100] = {}, cV = 0, cC = 0, maxV = 0, maxC = 0, sumV = 0, sumC = 0;
    string s;

    cin >> s;
    FOR(i, s.length())
    {
        if (is_vovel(s[i]))
        {
            cV++;
            V[s[i]] += 2;
            maxV = max(maxV, V[s[i]]);
            sumV += 2;
        }
        else
        {
            cC++;
            C[s[i]] += 2;
            maxC = max(maxC, C[s[i]]);
            sumC += 2;
        }
    }

    // cout << "cV:" << cV << " sumV:" << sumV << " maxV:" << maxV << endl;
    // cout << "cC:" << cC << " sumC:" << sumC << " maxC:" << maxC << endl;

    int rV = cV + sumC - maxC;
    int rC = cC + sumV - maxV;

    cout << "Case #" << caseNo << ": " << min(rV, rC) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR(i, tc)
    {
        solve(i + 1);
    }

    return 0;
}
