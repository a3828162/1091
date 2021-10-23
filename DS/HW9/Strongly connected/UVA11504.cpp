/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2499
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_set>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int n, m, Time, cnt;
vector<vector<int>> G;
vector<int> dfn, low, com;
stack<int> s;
unordered_set<int> instack;

inline void init(int n)
{
    G.assign(n + 1, vector<int>());
    low.assign(n + 1, 0);
    dfn.assign(n + 1, 0);
    com.assign(n + 1, -1);
    instack.clear();
    Time = cnt = 0;
    while (!s.empty()) s.pop();
}

void DFS(int u)
{
    dfn[u] = low[u] = ++Time;
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

    if (dfn[u] == low[u])
    {
        while (1)
        {
            int tmp = s.top();
            s.pop();
            instack.erase(tmp);
            com[tmp] = cnt;
            if (tmp == u) break;
        }
        ++cnt;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        init(n);

        int x, y;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            G[x].push_back(y);
        }

        for (int i = 1; i <= n; ++i) if (!dfn[i]) DFS(i);

        vector<int> degree(cnt);

        for (int u = 1; u <= n; ++u)
        {
            for (auto& v : G[u])
            {
                if (com[u] != com[v]) ++degree[com[v]];
            }
        }

        int ans = 0;

        for (auto& i : degree) if (!i) ++ans;
        cout << ans << "\n";
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
            com[tmp] = cnt;
            instack.erase(tmp);
            
            if (tmp == n) break;
        }
        ++cnt;
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> n >> m;
        init(n);

        int x, y;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            G[x].push_back(y);
        }

        for (int i = 1; i <= n; ++i) if (!dfn[i]) DFS(i);

        vector<int> degree(cnt);

        for (int u = 1; u <= n; ++u)
        {
            for (auto& v : G[u])
            {
                if (com[u] != com[v]) ++degree[com[v]];
            }
        }

        int ans = 0;
        for (auto& i : degree) if (!i) ++ans;
        cout << ans << "\n";
    }

    return 0;
}*/

/*
1
3 2
1 2
2 3

1
*/

/*#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;


reference:
https://ppt.cc/fMdaHx
https://ppt.cc/fnAeqx


static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int TIME;
int cnt;         // 計算目前有幾個 SCC
vector<int> dfn;
vector<int> low;
vector<int> com; // 紀錄點屬於哪個 SCC
vector<vector<int>> G;
unordered_set<int> inStack;
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
            com[tmp] = cnt;
            inStack.erase(tmp);
        } while (tmp != u);
        ++cnt;
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        // init
        TIME = 0;
        cnt = 0;
        dfn.assign(n + 1, 0);
        low.assign(n + 1, 0);
        com.assign(n + 1, 0);
        G.assign(n + 1, vector<int>());
        inStack.clear();
        while (!s.empty()) s.pop();

        while (m--)
        {
            int u, v;
            cin >> u >> v;

            G[u].push_back(v);
        }

        // 找出 SCC ( Strongly Connected Component )
        for (int u = 1; u <= n; ++u) if (!dfn[u]) dfs(u);

        // 計算 SCC 被幾個其他的 SCC 接入
        vector<int> degree(cnt);
        for (int u = 1; u <= n; ++u) for (auto& v : G[u])
        {
            if (com[u] != com[v]) ++degree[com[v]];
        }

        int ret = 0;
        // 如果 SCC 沒有被其他的 SCC 接入則需要一次來推倒
        for (auto& de : degree) if (!de) ++ret;
        cout << ret << '\n';
    }
}*/