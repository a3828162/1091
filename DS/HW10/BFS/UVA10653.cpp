/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1594

參考:     待補

題目:     一位士兵要從起點到終點的最短步數，小心不要踩到地雷了!

解題思路: 用vector來建圖，用queue來儲存下一步可走的資訊(也可用其他容器代替 Ex.list,deque)，每走到下一步就先把能走的路push到queue，再依序取出
          檢視是不是終點，如果不是則繼續走

Code解釋: 用pair來存x,y座標....待補

input:    輸入R,C表示R*C的空間，再輸入n表示有n列，每列先輸入r表row r，再輸入x表接下來有幾筆，接著輸入c表col c
output:   輸出起點到終點的距離
*/



#include <iostream>
#include <vector>
#include <queue>
#include <memory>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

const int direct[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
vector<vector<int>> G;
int r, c, n;
pair<int, int> start, End;

inline bool inrange(int x, int y) { return x >= 0 && x < r && y >= 0 && y < c; }

void BFS()
{
    queue<pair<int, int>> q;
    G[start.first][start.second] = 1;
    q.push(start);

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> next(now.first + direct[i][0], now.second + direct[i][1]);
            if (inrange(next.first, next.second) && G[next.first][next.second] == 0)
            {
                G[next.first][next.second] = G[now.first][now.second] + 1;
                q.push(next);
            }
            if (next == End)
            {
                cout << G[next.first][next.second] - 1 << "\n";
                return;
            }
        }
    }

}

int main()
{
    while (cin >> r >> c && (r || c))
    {
        G.assign(r, vector<int>(c));
        cin >> n;
        int x, y, z;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            for (int j = 0; j < y; ++j)
            {
                cin >> z;
                G[x][z] = -1; //別寫錯了
            }
        }
        cin >> start.first >> start.second;
        cin >> End.first >> End.second;

        BFS();
    }

    return 0;
}







/*void BFS()
{
    queue<pair<int, int>> q;
    q.push(start);
    G[start.first][start.second] = 1;

    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            pair<int, int> next(now.first + direct[i][0], now.second + direct[i][1]);
            if (inrange(next.first, next.second)&&!G[next.first][next.second])
            {
                q.push(next);
                G[next.first][next.second] = G[now.first][now.second] + 1;
            }
            if (next == End)
            {
                cout << G[End.first][End.second] - 1 << "\n";
                return;
            }
        }

    }
}

int main()
{
    while (cin >> r >> c && (r || c))
    {
        G.assign(r, vector<int>(c));
        cin >> n;
        int a, b, c;
        for (int i = 0;i<n;++i)
        {
            cin >> a >> c;
            for (int j = 0; j < c; ++j)
            {
                cin >> b;
                G[a][b] = -1;
            }
        }

        cin >> start.first >> start.second;
        cin >> End.first >> End.second;

        BFS();
    }

    return 0;
}

/*const int direct[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
vector<vector<int>> G;
pair<int, int> Start, End, Now, Next;
int R, C, n, r, c, x;

inline bool IntheRange(int row, int col)
{
    return row >= 0 && col >= 0 && row < R && col < C;
}

void BFS()
{
    queue<pair<int, int>> Q;
    Q.push(pair<int, int>(Start.first, Start.second));
    G[Start.first][Start.second] = 1;

    while (!Q.empty())
    {
        Now = Q.front();
        Q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int newR = Now.first + direct[i][0], newC = Now.second + direct[i][1];
            if (IntheRange(newR, newC) && G[newR][newC] == 0)
            {
                G[newR][newC] = G[Now.first][Now.second] + 1;

                Next = pair<int, int>(newR, newC);

                if (Next == End)
                {
                    cout << G[End.first][End.second] - 1 << "\n";
                    return;
                }

                Q.push(Next);
            }
        }
    }
}

int main()
{
    while (cin >> R >> C && (R || C))
    {
        G.assign(R, vector<int>());
        for (int i = 0; i < R; ++i) G[i].assign(C, 0);

        cin >> n;

        for (int i = 0; i < n; ++i)
        {
            cin >> r >> x;
            for (int j = 0; j < x; ++j)
            {
                cin >> c;
                G[r][c] = -1;
            }
        }
    
        cin >> Start.first >> Start.second >> End.first >> End.second;

        BFS();
    }

    return 0;
}*/

/*
10 10
9
0 1 2
1 1 2
2 2 2 9
3 2 1 7
5 3 3 6 9
6 4 0 1 2 7
7 3 0 3 8
8 2 7 9
9 3 2 3 4
0 0
9 9
0 0

18
*/
