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
#define DEBUGARR(arr, s, e) {FORL(dbg, s, e){ cout << arr[dbg] << " "; } cout << endl;}
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

#define MAXV 200
#define INF_I 1000

typedef struct {
    vvi adj;
} Graph;

void graph_addedge(Graph* g, int f, int t) {
    g->adj[f].pb(t);
}

Graph* make_graph() {
    Graph* g = (Graph*) malloc(sizeof(Graph));
    g->adj.resize(MAXV);
    return g;
}

void clear_graph(Graph *g) {
    vvi i;
    i.swap(g->adj);
    g->adj.resize(MAXV);
}

int G[MAXV][MAXV] = {};

void shortest_path(Graph *g) {
    FOR(i, MAXV) {
        fill(G[i], G[i] + MAXV, INF_I);
    }
    FORL(i, 'A', 'Z') {
        for(auto &k : g->adj[i]) {
            G[i][k] = 1;
        }
    }
    FORL(i, 'A', 'Z') {
        G[i][i] = 0;
    }

    FORL(k, 'A', 'Z') {
        FORL(i, 'A', 'Z') {
            FORL( j, 'A', 'Z') {
                if (G[i][j] > G[i][k] + G[k][j]) {
                    G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
    }
}

void compute_weigth(Graph* g) {
    shortest_path(g);
}

void debug_graph() {
    cout << "   ";
    FORL(k, 'A', 'Z') cout << (char)k << " ";
    cout << endl;
    FORL(i, 'A', 'Z') {
        cout << (char) i << ": ";
        FORL(k, 'A', 'Z') {
            if (G[i][k] == INF_I) cout << "- ";
            else cout << G[i][k] << " ";
        }
        cout << endl;
    }
}

Graph* g = make_graph();

void solve(int caseNo) {
    string s;
    cin >> s;

    int e;
    cin >> e;

    FOR(i, e) {
        string edge;
        cin >> edge;
        graph_addedge(g, edge[0], edge[1]);
    }

    compute_weigth(g);

    // debug_graph();

    int minC = INF_I;
    FORL(v, 'A', 'Z') {
        int cost = 0;
        FOR(k, s.length()) {
            int t = s[k];
            if (t == v) continue;
            if (G[t][v] == INF_I) goto nopath;
            cost += G[t][v];
        }

        minC = min(minC, cost);
        // cout << "TO:" << (char) v << " cost:" << cost << endl;

        nopath: ;
    }

    if (minC == INF_I) minC = -1;
    cout << "Case #" << caseNo << ": " << minC << endl;

    clear_graph(g);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc;
    FOR(i, tc)
        solve(i+1);

    return 0;
}
