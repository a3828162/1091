/*
題目連結: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=870

*/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

static auto __ = []()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

struct edge
{
    int u;
    int v;
    int w;

    bool operator<(const edge& r) const { return w > r.w; }
};

vector<vector<int>> G;
vector<vector<int>> dis;
vector<vector<bool>> visited;
int x, y;
const int dic[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

inline bool inrange(int l, int r)
{
    return l >= 0 && l < y && r >= 0 && r < x;
}

void dijkstra()
{
    priority_queue<edge> pq;
    dis[0][0] = G[0][0];
    pq.push(edge{ 0,0,dis[0][0] });
    visited[0][0] = 1;

    while (!pq.empty())
    {
        edge tmp = pq.top();
        pq.pop();
        visited[tmp.v][tmp.u] = 1;
        for (int i = 0; i < 4; ++i)
        {
            int _x = tmp.u + dic[i][0];
            int _y = tmp.v + dic[i][1];

            if (!inrange(_x, _y) || visited[_y][_x]) continue;

            if (/*dis[_y][_x] > dis[tmp.v][tmp.u] + tmp.w*/dis[_y][_x]>dis[tmp.v][tmp.u]+G[_y][_x])
            {
                dis[_y][_x] = dis[tmp.v][tmp.u] + G[_y][_x];
                //dis[_y][_x] = G[_y][_x] + tmp.w;
                pq.push(edge{ _x,_y,dis[_y][_x] });
            }
        }
    }

    cout << dis[x - 1][y - 1] << "\n";
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> x >> y;
        G.assign(x, vector<int>(y));
        dis.assign(x, vector<int>(y, INT_MAX));
        visited.assign(x, vector<bool>(y, false));

        for (int i = 0; i < x; ++i)
        {
            for (int j = 0; j < y; ++j)
            {
                cin >> G[i][j];
            }
        }

        dijkstra();
    }

    return 0;
}


/*int X, Y;
int d[] = { 1, 0, -1, 0, 1 };
priority_queue<edge, vector<edge>, greater<edge>> pq;
vector<vector<int>> G;
vector<vector<int>> value;
vector<vector<bool>> visited;

void init()
{
    G.assign(Y, vector<int>(X));
    value.assign(Y, vector<int>(X, INT_MAX));
    visited.assign(Y, vector<bool>(X, false));
}

void dijk()
{
    pq.push({ 0, 0, value[0][0] = G[0][0] });

    while (!pq.empty())
    {
        auto [x, y, val] = pq.top();
        visited[y][x] = true;
        pq.pop();

        for (int i = 0; i < 4; ++i)
        {
            int dx = x + d[i];
            int dy = y + d[i + 1];

            if (dx < 0 || dx >= X || dy < 0 || dy >= Y || visited[dy][dx]) continue;

            int tmp = val + G[dy][dx];
            if (value[dy][dx] > tmp) pq.push({ dx, dy, value[dy][dx] = tmp });
        }
    }

    cout << value[Y - 1][X - 1] << '\n';
}

int main()
{
    int T, tmp;
    cin >> T;

    while (T--)
    {
        cin >> Y >> X;
        init();

        for (int i = 0; i < Y; ++i) for (int j = 0; j < X; ++j)
        {
            cin >> tmp;
            G[i][j] = tmp;
        }

        dijk();
    }
}*/





/*struct node
{
    int x;
    int y;
    int w;

    bool operator<(const node& right) const { return w > right.w; }
};

const int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

vector < vector<int> > G, D;
vector < vector<bool> > visited;
int T, r, c;

inline bool inRange(int x, int y) { return x > 0 && y > 0 && x <= c && y <= r; }

void Dijkstra()
{
    priority_queue<node> PQ;

    int i, j;

    D[1][1] = G[1][1];

    node tmp = { 1,1,D[1][1] };
    PQ.push(tmp);

    int all = r * c;

    for (int i = 0; i < all; ++i)
    {
        int nextx = -1, nexty = -1;

        while (!PQ.empty())
        {
            node now = PQ.top();
            PQ.pop();

            if (!visited[now.y][now.x])
            {
                nextx = now.x;
                nexty = now.y;
                break;
            }
        }

        if ((nextx == -1 && nexty == -1) || (nextx == c && nexty == r)) break;

        visited[nexty][nextx] = true;

        for (int j = 0; j < 4; ++j)
        {
            int x = nextx + dir[j][0], y = nexty + dir[j][1];
            if (inRange(x, y))
            {
                if (D[nexty][nextx] + G[y][x] < D[y][x] && !visited[y][x])
                {
                    D[y][x] = D[nexty][nextx] + G[y][x];
                    node tmp2 = { x,y,D[y][x] };
                    PQ.push(tmp2);
                }
            }
        }
    }

    cout << D[r][c] << "\n";
}

int main()
{
    cin >> T;

    while (T--)
    {
        cin >> r >> c;
        G.assign(r + 1, vector<int>());
        D.assign(r + 1, vector<int>());
        visited.assign(r + 1, vector<bool>());
        for (int i = 0; i <= r; ++i) G[i].assign(c + 1, 0), D[i].assign(c + 1, 1e9), visited[i].assign(c + 1, false);

        for (int i = 1; i <= r; ++i) for (int j = 1; j <= c; ++j) cin >> G[i][j];

        Dijkstra();
    }

    return 0;
}*/

/*
2
4
5
0 3 1 2 9
7 3 4 9 9
1 7 5 5 3
2 3 4 2 5
1
6
0 1 2 3 4 5

24
15
*/