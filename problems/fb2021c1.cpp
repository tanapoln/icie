#include <bits/stdc++.h>

#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define PI 3.1415926535897932384626433832795
#define FOREACH(it, l) for (auto(it) = (l).begin(); (it) != (l).end(); (it)++)
#define FOREACHR(it, l) for (auto(it) = (l).rbegin(); (it) != (l).rend(); (it)++)
#define pb push_back
#define MP make_pair
#define abs(a) ((a) < 0 ? -(a) : (a))
#define max(a, b) ((a) < (b) ? (b) : (a))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define MOD (1e9 + 7)
#define divceil(n, d) (((n) / (d)) + ((n) % (d) > 0 ? 1 : 0))
#define DEBUGARR(arr, s, e)                        \
    {                                              \
        FORL(_i, s, e) { cout << arr[_i] << " "; } \
        cout << endl;                              \
    }
#define DEBUGVEC(vec)                                \
    {                                                \
        FOREACH(_it, vec) { cout << (*_it) << " "; } \
        cout << endl;                                \
    }

#ifdef ONLINE_JUDGE
#define IFNOJ if (false)
#else
#define IFNOJ if (true)
#endif

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

#define MAXN 52

typedef struct node
{
    int id;
    vector<node *> childs;
    int ore;
    int max_ore;
    bool leaf;
} node;

void dfs(node tree[], int id, bool vis[], int sum)
{
    if (vis[id])
        return;

    vis[id] = true;
    node *n = &tree[id];
    sum = sum + n->ore;

    for (auto c : n->childs)
    {
        dfs(tree, c->id, vis, sum);
    }

    int max_ore = sum;
    for (auto c : n->childs)
    {
        max_ore = max(max_ore, c->max_ore);
    }
    n->max_ore = max_ore;
}

void compute(node tree[], int n)
{
    bool vis[MAXN] = {};
    dfs(tree, 1, vis, 0);

    IFNOJ FORL(i, 1, n)
    {
        cout << "N:" << i << " leaf:" << tree[i].leaf << " ore:" << tree[i].ore << " max_ore:" << tree[i].max_ore << endl;
    }
}

bool comp(ii a, ii b)
{
    if (a.first < b.first)
        return true;
    if (a.first > b.first)
        return false;
    if (a.second < b.second)
        return true;
    if (a.second > b.second)
        return false;
    return true;
}

node tree[MAXN];

void clear()
{
    FOR(i, MAXN)
    {
        tree[i].childs.clear();
        tree[i].max_ore = 0;
    }
}

void solve(int caseNo)
{
    clear();
    int n;
    cin >> n;
    FORL(i, 1, n)
    {
        cin >> tree[i].ore;
        tree[i].id = i;
        tree[i].max_ore = 0;
    }

    FORL(i, 1, n - 1)
    {
        int s, t;
        cin >> s >> t;
        tree[t].childs.pb(&tree[s]);
        tree[s].childs.pb(&tree[t]);
    }
    FORL(i, 1, n)
    {
        tree[i].leaf = tree[i].childs.size() == 1;
    }
    // tree[1].leaf = false;

    compute(tree, n);

    int max_ore = 0;
    if (tree[1].childs.size() == 0)
    {
        max_ore = tree[1].max_ore;
    }
    else
    {

        vi ores;
        for (auto c : tree[1].childs)
        {
            ores.pb(c->max_ore);
        }
        sort(ores.begin(), ores.end(), greater());
        IFNOJ DEBUGVEC(ores);
        max_ore = ores[0];
        if (ores.size() > 1)
            max_ore += ores[1] - tree[1].ore;
    }

    cout << "Case #" << caseNo << ": " << max_ore << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;
    FOR(i, tc)
    solve(i + 1);

    return 0;
}
