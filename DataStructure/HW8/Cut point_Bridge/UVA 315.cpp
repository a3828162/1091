/*
題目連結: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=251
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
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
vector<int> dfn, low;
int Time, ret;

inline void init(int n)
{
    G.assign(n + 1, vector<int>());
    dfn.assign(n + 1, 0);
    low.assign(n + 1, 0);
    Time = 0;
    ret = 0;
}

void DFS(int u, int parent)
{
    int child = 0;
    bool flag = false;
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

        if (low[v] >= dfn[u]) flag = true;
    }

    if (flag && (child >= 2 || parent)) ++ret;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        init(n);
        string s;
        while (getline(cin, s) && s != "0")
        {
            stringstream ss(s);
            int x, y;
            ss >> x;
            while (ss >> y)
            {
                G[x].push_back(y);
                G[y].push_back(x);
            }
        }

        for(int i=0;i<n;++i) if(!dfn[i]) DFS(i, 0);

        cout << ret << "\n";
    }

    return 0;
}





/*void DFS(int n, int parent)
{
    int child = 0;
    bool flag = false;
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

        if (low[i] >= dfn[n]) flag = true;
    }

    if (flag && (child >= 2 || parent)) ++ret;
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        init(n);
        string s;
        int x, y;
        while (getline(cin, s) && s != "0")
        {
            stringstream ss(s);
            ss >> x;
            while (ss >> y)
            {
                G[x].push_back(y);
                G[y].push_back(x);
            }
        }

        for(int i=1;i<=n;++i) if(!dfn[i]) DFS(i, 0);

        cout << ret << "\n";
    }

    return 0;
}*/

/*
5
5 1 2 3 4
0
6
2 1 3
5 4 6 2
0
0

1
2
*/