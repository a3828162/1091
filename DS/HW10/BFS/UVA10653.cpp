/*
�D�سs��: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1594

�Ѧ�:     �ݸ�

�D��:     �@��h�L�n�q�_�I����I���̵u�B�ơA�p�ߤ��n���a�p�F!

���D���: ��vector�ӫعϡA��queue���x�s�U�@�B�i������T(�]�i�Ψ�L�e���N�� Ex.list,deque)�A�C����U�@�B�N����ਫ����push��queue�A�A�̧Ǩ��X
          �˵��O���O���I�A�p�G���O�h�~��

Code����: ��pair�Ӧsx,y�y��....�ݸ�

input:    ��JR,C���R*C���Ŷ��A�A��Jn��ܦ�n�C�A�C�C����Jr��row r�A�A��Jx���U�Ӧ��X���A���ۿ�Jc��col c
output:   ��X�_�I����I���Z��
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
                G[x][z] = -1; //�O�g���F
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
