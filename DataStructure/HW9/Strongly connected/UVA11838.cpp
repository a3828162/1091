/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2938
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <algorithm>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

vector<vector<int>> G;
vector<int> low, dfn;
stack<int> s;
unordered_set<int> instack;
int n, m, Time, scnt;

inline void init(int n)
{
    G.assign(n + 1, vector<int>());
    low.assign(n + 1, 0);
    dfn.assign(n + 1, 0);
    instack.clear();
    Time = scnt = 0;
    while (!s.empty()) s.pop();
}

void DFS(int u)
{
    low[u] = dfn[u] = ++Time;
    s.push(u);
    instack.insert(u);

    for (auto& v : G[u])
    {
        if (dfn[v])
        {
            if (instack.count(v)) low[u] = min(low[u], dfn[v]);
            continue;
        }

        DFS(v);
        low[u] = min(low[u], low[v]);
    }

    if (low[u] == dfn[u])
    {
        while (1)
        {
            int tmp = s.top();
            s.pop();
            instack.erase(tmp);

            if (tmp == u) break;
        }
        ++scnt;
    }
}

int main()
{
    while (cin >> n >> m && (n || m))
    {
        init(n);

        int a, b, c;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b >> c;
            G[a].push_back(b);
            if (c == 2) G[b].push_back(a);
        }

        for (int i = 1; i <= n; ++i) if (!dfn[i]) DFS(i);

        if (scnt != 1) cout << "0\n";
        else cout << "1\n";
    }

    return 0;
}









/*void DFS(int n)
{
    dfn[n] = low[n] = ++Time;
    s.push(n);
    instack.insert(n);

    for (auto& i : G[n])
    {
        if (dfn[i])
        {
            if (instack.count(i)) low[n] = min(low[n], dfn[i]);
            continue;
        }

        DFS(i);
        low[n] = min(low[n], low[i]);
    }

    if (dfn[n] == low[n])
    {
        int tmp;

        while (1)
        {
            tmp = s.top();
            s.pop();
            instack.erase(tmp);
            if (tmp == n) break;
        }
        ++scnt;
    }
}

int main()
{
    while (cin >> n >> m && (n || m))
    {
        init(n);

        int x, y, p;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y >> p;

            G[x].push_back(y);
            if (p == 2) G[y].push_back(x);
        }

        for (int i = 1; i <= n; ++i) if (!dfn[i]) DFS(i);

        if (scnt == 1) cout << "1\n";
        else if (scnt > 1) cout << "0\n";
    }

    return 0;
}*/

/*
4 5
1 2 1
1 3 2
2 4 1
3 4 1
4 1 2
3 2
1 2 2
1 3 2
3 2
1 2 2
1 3 1
4 2
1 2 2
3 4 2
0 0

1
1
0
0
*/
/*#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;

// reference: https://ppt.cc/fkxbXx

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int TIME;
int cnt;
vector<int> dfn;
vector<int> low;
unordered_set<int> inStack;
vector<vector<int>> G;
stack<int> s;

void dfs(int u)
{
    dfn[u] = low[u] = ++TIME;
    s.push(u);
    inStack.insert(u);

    for (auto& v : G[u])
    {
        if (dfn[v])
        {
            if (inStack.count(v)) low[u] = min(dfn[v], low[u]);
            continue;
        }

        dfs(v);
        low[u] = min(low[v], low[u]);
    }

    if (dfn[u] == low[u])
    {
        int tmp;
        do
        {
            tmp = s.top();
            s.pop();
            inStack.erase(tmp);
        } while (tmp != u);
        ++cnt;
    }
}

int main()
{
    int N, M;
    while (cin >> N >> M && !(!N && !M))
    {
        // init
        TIME = 0;
        cnt = 0;
        dfn.assign(N + 1, 0);
        low.assign(N + 1, 0);
        inStack.clear();
        G.assign(N + 1, vector<int>());
        while (!s.empty()) s.pop();

        while (M--)
        {
            int u, v, P; // P 為 1 代表單向 u -> v，為 2 代表雙向 u -> v, v -> u
            cin >> u >> v >> P;

            G[u].push_back(v);
            if (P == 2) G[v].push_back(u);
        }

        for (int u = 1; u <= N; ++u) if (!dfn[u] && cnt < 2) dfs(u);

        cout << (cnt == 1) << '\n';
    }
}*/