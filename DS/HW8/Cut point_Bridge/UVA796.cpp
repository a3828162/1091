/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=737
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

vector<vector<int>> G;
vector<int> dfn, low;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> ans;
int Time;

inline void init(int n)
{
    G.assign(n, vector<int>());
    dfn.assign(n, 0);
    low.assign(n, 0);
    Time = 0;
}

void DFS(int u, int parent)
{
    dfn[u] = low[u] = ++Time;

    for (auto& v : G[u])
    {
        if (dfn[v])
        {
            if (v != parent) low[u] = min(low[u], dfn[v]);
            continue;
        }

        DFS(v, u);
        low[u] = min(low[u], low[v]);

        if (low[v] > dfn[u]) ans.push({ min(u,v),max(u,v) });
    }
}

int main()
{
    int n;

    while (cin >> n)
    {
        
        init(n);
        int a, b, m;
        char ch;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            cin >> ch >> m >> ch;
            for (int i = 0; i < m; ++i)
            {
                cin >> b;
                G[a].push_back(b);
            }
        }

        for(int i=0;i<n;++i) if(!dfn[i]) DFS(i, -1);

        cout << ans.size() << " critical links\n";
        while (!ans.empty()) cout << ans.top().first << " - " << ans.top().second << "\n", ans.pop();
        cout << "\n";
    }

    return 0;
}



/*void DFS(int n, int parent)
{
    dfn[n] = low[n] = ++Time;

    for (auto& i : G[n])
    {
        if (dfn[i])
        {
            if (i != parent) low[n] = min(low[n], dfn[i]);
            continue;
        }

        DFS(i, n);
        low[n] = min(low[n], low[i]);

        if (low[i] > dfn[n]) ans.push({ min(i,n),max(i,n) });
    }

}

int main()
{
    int n;

    while (cin >> n)
    {
        init(n);

        for (int i = 0; i < n; ++i)
        {
            int a, b, c;
            char ch;
            cin >> a >> ch >> c >> ch;
            for (int j = 0; j < c; ++j)
            {
                cin >> b;
                G[a].push_back(b);
                G[b].push_back(a);
            }
        }

        for (int i = 0; i < n; ++i) if (!dfn[i]) DFS(i, -1);

        cout << ans.size() << " critical links\n";
        while (!ans.empty())
        {
            cout << ans.top().first << " - "<< ans.top().second << "\n";
            ans.pop();
        }
        cout << "\n";
    }

	return 0;
}*/

/*
8
0 (1) 1
1 (3) 2 0 3
2 (2) 1 3
3 (3) 1 2 4
4 (1) 3
7 (1) 6
6 (1) 7
5 (0)

0

3 critical links
0 - 1
3 - 4
6 - 7

0 critical links
*/