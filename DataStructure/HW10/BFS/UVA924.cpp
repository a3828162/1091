/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=865

參考:     

題目:     
*/

#include <iostream>
#include <vector>
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
vector<int> day, spread;
vector<bool> visited;
int N;

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    day[src] = 1;
    visited[src] = true;

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (auto& next : G[now])
        {
            if (!visited[next])
            {
                day[next] = day[now] + 1;
                visited[next] = true;
                ++spread[day[now]];
                q.push(next);
            }
        }
    }

    int maxD = 0, maxS = 0;

    for (int i = 0; i <= N; ++i)
    {
        if (spread[i] > maxS) maxS = spread[i], maxD = i;
    }

    if (maxS == 0) cout << "0\n";
    else cout << maxS << " " << maxD << "\n";
}

int main()
{
    while (cin >> N)
    {
        G.assign(N, vector<int>());
        int a, b;
        for (int i = 0; i < N; ++i)
        {
            cin >> a;
            for (int j = 0; j < a; ++j)
            {
                cin >> b;
                G[i].push_back(b);  
            }
        }
        int m;
        cin >> m;
        int src;
        while (m--)
        {
            visited.assign(N + 1, false);
            spread.assign(N + 1, 0);
            day.assign(N + 1, 0);
            cin >> src;

            BFS(src);
        }
    }

    return 0;
}










/*void BFS(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    day[src] = 1;

    while (!q.empty())
    {
        int tmp = q.front();
        q.pop();

        for (auto& v : G[tmp])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
                day[v] = day[tmp] + 1;
                ++spread[day[tmp]];
            }
        }
    }

    int maxS = 0, maxD = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (spread[i] > maxS) maxD = i, maxS = spread[i];
    }

    if (maxS) cout << maxS << " " << maxD << "\n";
    else cout << "0\n";
}

int main()
{
    while (cin >> N)
    {
        G.assign(N, vector<int>());

        int a, b;
        for (int i = 0; i < N; ++i)
        {
            cin >> a;
            for (int j = 0; j < a; ++j)
            {
                cin >> b;
                G[i].push_back(b);
            }
        }
        int c, src;

        cin >> c;

        while (c--)
        {
            visited.assign(N, false);
            day.assign(N + 1, 0);
            spread.assign(N + 1, 0);
            
            cin >> src;

            BFS(src);
        }
    }

    return 0;
}*/

/*vector < vector<int> > edges;
vector < int > day, spread;
vector < bool > visited;
int T, E, n, r, src, now, maxD, maxS;

void BFS()
{
    queue<int> Q;
    Q.push(src);
    visited[src] = true;
    day[src] = 1;

    while (!Q.empty())
    {
        now = Q.front();
        Q.pop();    

        for (auto& v : edges[now])
        {
            if (!visited[v])
            {
                visited[v] = true;
                Q.push(v);

                day[v] = day[now] + 1;
                spread[day[now]]++;
            }
        }
    }

    for (int i = 1; i <= T; ++i) if (spread[i] > maxS) maxS = spread[i], maxD = i;

    if (maxD) cout << maxS << " " << maxD << "\n";
    else cout << "0" << "\n";
}

int main()
{
    while (cin >> T)
    {
        edges.assign(T, vector<int>());

        for (auto& i : edges)
        {
            cin >> n;
            for (int j = 0; j < n; ++j)
            {
                cin >> r;
                i.push_back(r);
            }
        }

        cin >> E;

        while (E--)
        {
            visited.assign(T, false);
            day.assign(T + 1, 0);
            spread.assign(T + 1, 0);
            maxD = maxS = 0;

            cin >> src;

            BFS();
        }
    }

    return 0;
}*/

/*
6
2 1 2
2 3 4
3 0 4 5
1 4
0
2 0 2
3
0
4
5

3 2
0
2 1
*/