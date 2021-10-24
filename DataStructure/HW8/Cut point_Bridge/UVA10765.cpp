/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1706
*/

#include <iostream>
#include <vector>
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
vector<int> dfn, low, Count;
vector<pair<int, int>> ans;
int Time;

inline void init(int n)
{
    G.assign(n, vector<int>());
    dfn.assign(n, 0);
    low.assign(n, 0);
    Count.assign(n, 0);
    ans.clear();
    Time = 0;
}

bool cmp(pair<int, int> left, pair<int, int> right)
{
    return left.second != right.second ? left.second > right.second:left.first < right.first;
}

void DFS(int u, int parent)
{
    int child = 0, cnt = 0;
    low[u] = dfn[u] = ++Time;

    for (auto& v : G[u])
    {
        if (dfn[v])
        {
            if (v != parent) low[u] = min(dfn[v], low[u]);
            continue;
        }

        ++child;
        DFS(v, u);
        low[u] = min(low[u], low[v]);

        if (low[v] >= dfn[u]) ++cnt;
    }

    if (cnt && (child >= 2 || parent != -1)) Count[u] = cnt;
}

int main()
{
    int n, m;
    while (cin >> n >> m && (n || m))
    {
        init(n);
        int a, b;
        while (cin >> a >> b && (a != -1 || b != -1))
        {
            G[a].push_back(b);
            G[b].push_back(a);
        }

        for (int i = 0; i < n; ++i) if (!dfn[i]) DFS(i, -1);

        for (int i = 0; i < n; ++i) ans.push_back({ i,Count[i] + 1 });
        sort(begin(ans), end(ans), cmp);

        for (int i = 0; i < m; ++i) cout << ans[i].first << " " << ans[i].second << "\n";
        cout << "\n";
    }

    return 0;
}



/*void DFS(int n, int parent)
{
    int child = 0;
    dfn[n] = low[n] = ++Time;

    for (auto& i : G[n])
    {
        if (dfn[i])
        {
            if (i != parent) low[n] = min(low[n], dfn[i]);
            continue;
        }

        ++child;
        DFS(i, n);
        low[n] = min(low[n], low[i]);

        if (low[i] >= dfn[n] && (child >= 2 || parent != -1)) ++Count[n];
    }
}

int main()
{
    int n, m;

    while (cin >> n >> m && (n || m))
    {
        init(n);

        int x, y;

        while (cin >> x >> y && (x != -1 || y != -1))
        {
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for (int i = 0; i < n; ++i) if (!dfn[i]) DFS(i, -1);

        for (int i = 0; i < n; ++i) ans.push_back({ i,Count[i] + 1 });
        sort(begin(ans), end(ans), cmp);

        for (int i = 0; i < m; ++i)cout << ans[i].first << " " << ans[i].second << "\n";
        cout << "\n";
    }

    return 0;
}*/

/*
8 4
0 4
1 2
2 3
2 4
3 5
3 6
3 7
6 7
-1 -1
0 0

2 3
3 3
4 2
0 1
*/