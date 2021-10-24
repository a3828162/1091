/*
題目連結: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1498
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_set>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

int n, m;
vector<vector<int>> G, re;
vector<int> energy, dis;
unordered_set<int> ans;

void DFS(int u)
{
    ans.insert(u);

    for (auto& v : re[u])
    {
        if (!ans.count(v)) DFS(v);
    }
}

bool bellman()
{
    dis[1] = 100;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 1; u <= n; ++u)
        {
            for (auto& v : G[u])
            {
                if (dis[u]) dis[v] = max(dis[v], dis[u] + energy[v]);
            }
        }
    }

    for (int u = 1; u <= n; ++u)
    {
        for (auto& v : G[u])
        {
            if (dis[u] && dis[v] < dis[u] + energy[v])
            {
                if (ans.count(v)) return true;
                dis[v] = dis[u] + energy[v];
            }
        }
    }

    return dis[n];
}

int main()
{
    while (cin >> n && n != -1)
    {
        G.assign(n + 1, vector<int>());
        re.assign(n + 1, vector<int>());
        energy.assign(n + 1, 0);
        dis.assign(n + 1, 0);
        ans.clear();
        int tmp, x, y;
        for (int i = 1; i <= n; ++i)
        {
            cin >> tmp;
            energy[i] = tmp;
            cin >> x;
            for (int j = 0; j < x; ++j)
            {
                cin >> y;
                G[i].push_back(y), re[y].push_back(i);
            }
        }

        DFS(n);

        if (!bellman()) cout << "hopeless\n";
        else cout << "winnable\n";
    }

    return 0;
}


/*
5
0 1 2
-60 1 3
-60 1 4
20 1 5
0 0
5
0 1 2
20 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
21 1 3
-60 1 4
-60 1 5
0 0
5
0 1 2
20 2 1 3
-60 1 4
-60 1 5
0 0
-1

hopeless
hopeless
winnable
winnable
*/









/*void DFS(int u)
{
    ans.insert(u);
    for (auto& v : re[u]) if (!ans.count(v)) DFS(v);

}

bool bellman()
{
    dis[1] = 100;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 1; u <= n; ++u)
        {
            for (auto& v : G[u])
            {
                if (dis[u]) dis[v] = max(dis[v], dis[u] + energy[v]);
            }
        }
    }

    for (int u = 1; u <= n; ++u)
    {
        for (auto& v : G[u])
        {
            if (dis[u] && dis[v] < dis[u] + energy[v])
            {
                if (ans.count(v)) return true;
                dis[v] = dis[u] + energy[v];
            }
        }
    }

    return dis[n];
}

int main()
{
    while (cin >> n && n != -1)
    {
        G.assign(n + 1, vector<int>());
        re.assign(n + 1, vector<int>());
        energy.assign(n + 1, 0);
        dis.assign(n + 1, 0);
        ans.clear();

        for (int i = 1; i <= n; ++i)
        {
            int tmp, d;
            cin >> tmp;
            energy[i] = tmp;
            cin >> d;
            for (int j = 0; j < d; ++j)
            {
                cin >> tmp;
                G[i].push_back(tmp);
                re[tmp].push_back(i);
            }
        }

        DFS(n);

        if (!bellman()) cout << "hopeless\n";
        else cout << "winnable\n";
    }

    return 0;
}*/





/*void DFS(int u)
{
    ans.insert(u);

    for (auto& v : re[u]) if (!ans.count(v)) DFS(v);
}

bool Bellman()
{
    dis[1] = 100;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 1; u <= n; ++u)
        {
            for (auto& v : G[u])
            {
                if (dis[u])
                {
                    dis[v] = max(dis[v], dis[u] + energy[v]);
                }
            }
        }
    }

    for (int u = 1; u <= n; ++u)
    {
        for (auto& v : G[u])
        {
            if (dis[u] && dis[u] + energy[v] > dis[v])
            {
                if (ans.count(v)) return true;
                dis[v] = dis[u] + energy[v];
            }
        }
    }

    return dis[n];
    //return false;
}

int main()
{
    while (cin >> n && n != -1)
    {
        dis.assign(n + 1, 0);
        energy.assign(n + 1, 0);
        G.assign(n + 1, vector<int>());
        re.assign(n + 1, vector<int>());
        ans.clear();

        int tmp, d;

        for (int i = 1; i <= n; ++i)
        {
            cin >> tmp;
            energy[i] = tmp;
            cin >> d;
            for (int j = 0; j < d; ++j)
            {
                cin >> tmp;
                G[i].push_back(tmp);
                re[tmp].push_back(i);
            }
        }

        DFS(n);

        if (Bellman()) cout << "winnable\n";
        else cout << "hopeless\n";
    }

    return 0;
}*/