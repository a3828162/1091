/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1390
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <climits>
#include <unordered_set>
#include <algorithm>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

vector<int> node, dist;
vector<vector<pair<int, int>>> G;
unordered_set <int> ans;
int n, m;

void Bellman()
{
    dist[1] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 1; u <= n; ++u)
        {
            for (auto& [v, w] : G[u])
            {
                if (dist[u] != INT_MAX) dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    for (int u = 1; u <= n; ++u)
    {
        for (auto& [v, w] : G[u])
        {
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                ans.insert(v);
            }
        }
    }
}

int main()
{
    int Case = 0;
    while (cin >> n)
    {
        node.assign(n + 1, 0);
        dist.assign(n + 1, INT_MAX);
        G.assign(n + 1, vector<pair<int,int>>());
        ans.clear();

        for (int i = 1; i <= n; ++i) cin >> node[i];
        cin >> m;
        int x, y;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            G[x].push_back({ y, (int)pow(node[y] - node[x], 3) });
        }

        Bellman();

        int d, t;
        cin >> d;
        cout << "Set #" << ++Case << "\n";
        while (d--)
        {
            cin >> t;

            if (ans.count(t) || dist[t] < 3 || dist[t] == INT_MAX) cout << "?\n";
            else cout << dist[t] << "\n";
        }
    }


    return 0;
}






/*void bellman()
{
    dist[1] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 1; u <= n; ++u)
        {
            for (auto& [v, w] : G[u])
            {
                if (dist[u] != INT_MAX) dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }

    for (int u = 1; u <= n; ++u)
    {
        for (auto& [v, w] : G[u])
        {
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                ans.insert(v);
            }
        }
    }
}

int main()
{
    int Case = 0;

    while (cin >> n)
    {
        node.assign(n + 1, 0);
        dist.assign(n + 1, INT_MAX);
        ans.clear();
        G.assign(n + 1, vector<pair<int, int>>());
        for (int i = 1; i <= n; ++i) cin >> node[i];

        cin >> m;
        
        int x, y;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            G[x].push_back({ y,(int)pow(node[y] - node[x],3) });
        }

        int a;
        cin >> a;
        bellman();
        cout << "Set #" << ++Case << "\n";

        while (a--)
        {
            int tmp;
            cin >> tmp;

            if (dist[tmp] == INT_MAX || dist[tmp] < 3 || ans.count(tmp)) cout << "?\n";
            else cout << dist[tmp] << "\n";
        }
    }

    return 0;
}*/


/*void Bellman(int n)
{
    dist[1] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 1; u <= n; ++u)
        {
            for (auto& [v, w] : edge[u])
            {
                if (dist[u] != INT_MAX) dist[v] = min(dist[u] + w, dist[v]);
            }

        }
    }

    for (int u = 1; u <= n; ++u)
    {
        for (auto& [v, w] : edge[u])
        {
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                ans.insert(v);
            }
        }
    }

}

int main()
{
    int n, m, tmp, Case = 0;

    while (cin >> n)
    {
        G.assign(n + 1, 0);
        dist.assign(n + 1, (int)INT_MAX);
        edge.assign(n + 1, vector<pair<int, int>>());
        ans.clear();

        for (int i = 1; i <= n; ++i)
        {
            cin >> tmp;
            G[i] = tmp;
        }

        int x, y;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> x >> y;
            edge[x].push_back({ y, (int)pow(G[y] - G[x], 3) });
        }

        Bellman(n);
        int q;
        cin >> q;
        int d;
        cout << "Set #" << ++Case << "\n";

        while (q--)
        {
            cin >> d;
            if (ans.count(d) || dist[d] < 3 || dist[d] == (int)INT_MAX) cout << "?\n";
            else cout << dist[d] << "\n";
        } 
    }

	return 0;
}*/

/*
5 6 7 8 9 10
6
1 2
2 3
3 4
1 5
5 4
4 5
2
4
5

Set #1
3
4
*/