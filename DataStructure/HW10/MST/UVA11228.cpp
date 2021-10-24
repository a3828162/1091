/*
�D�سs��: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2169

�Ѧ�:     �ݸ�

�D��:     �{�b�ڭ̭n�b���������\�K���Τ����A�j��@�w���Z���~�\�K���A�_�h���\�����A�u�����P���w�ݭn�K���A��X�o�ǫ����b�X�Ӥ��P���w

���D���: ��MST...�ݸ�

Code����: �ݸ�

input:    ��JT��T������A��Jn,r�An���X�ӫ����Ar��ܻ֭ȡA����n�C��J������x,y�y��
output:   �̧ǿ�X���X�Ӭw,�n�\����������,�n�\���K������
*/

#include <memory.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

struct edge
{
    int u;
    int v;
    double weight;

    bool operator<(const edge& r) { return weight < r.weight; }
};

vector<edge> edges;
vector < pair<double, double>> node;
vector<int> parent, Rank;
int n, s;
double r, ans1, ans2;

inline int find(int f)
{
    return parent[f] == f ? f : parent[f] = find(parent[f]);
}

void Kruskal()
{
    int j = 0;

    for (auto& [u, v, w] : edges)
    {
        int a = find(u), b = find(v);

        if (a != b)
        {
            if (Rank[a] < Rank[b]) parent[a] = b;
            else if (Rank[a] > Rank[b]) parent[b] = a;
            else if (Rank[a] == Rank[b]) parent[a] = b, ++Rank[b];

            if (w < r) ans1 += w, --s;
            else ans2 += w;
            if(++j == n - 1) return;
        }
    }
}

int main()
{
    int T, Case = 0;
    cin >> T;

    while (T--)
    {
        cin >> n >> r;
        edges.clear();
        parent.assign(n, 0);
        Rank.assign(n, 0);
        node.assign(n, pair<double, double>());
        for (int i = 0; i < n; ++i)
        {
            cin >> node[i].first >> node[i].second;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                double x = node[j].first - node[i].first, y = node[j].second - node[i].second;
                double z = sqrt(x * x + y * y);
                edges.push_back({ i,j,z });
            }
        }

        sort(begin(edges), end(edges));

        for (int i = 0; i < n; ++i) parent[i] = i;

        s = n;
        ans1 = ans2 = 0;

        Kruskal();

        pair<int, int> ans(ans1 + 0.5, ans2 + 0.5);

        cout << "Case #" << ++Case << ": " << s << " " << ans.first << " " << ans.second << "\n";
    }
    
    return 0;
}









/*int find(int f)
{
    return parent[f] == f ? f : parent[f] = find(parent[f]);
}

void Kruskal()
{
    int j = 0;
    for (auto& [u, v, w] : edges)
    {
        int a = find(u), b = find(v);

        if (a != b)
        {
            if (Rank[a] < Rank[b]) parent[a] = b;
            else if (Rank[a] > Rank[b]) parent[b] = a;
            else if (Rank[a] == Rank[b]) parent[a] = b, Rank[b]++;

            if (w < r) ans1 += w, --s;
            else ans2 += w;

            if (++j == n - 1) return;
        }
    }
}

int main()
{
    int T, Case = 0;
    cin >> T;

    while (T--)
    {
        cin >> n >> r;
        node.assign(n, pair<double, double>());
        edges.clear();
        parent.assign(n, 0);
        Rank.assign(n, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> node[i].first >> node[i].second;
            parent[i] = i;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                double x = node[j].first - node[i].first, y = node[j].second - node[i].second;
                double z = sqrt(x * x + y * y);
                edges.push_back({ i,j,z });
            }
        }

        sort(begin(edges), end(edges));
        ans1 = 0, ans2 = 0;
        s = n;
        Kruskal();

        pair<int, int> ans(ans1 + 0.5, ans2 + 0.5);

        cout << "Case #" << ++Case << ": " << s << " " << ans.first << " " << ans.second << "\n";
    }

    return 0;
}*/

/*vector <edge> edges;
vector <pair<double, double>> node;
vector <int> parent, Rank;
int n, s;
double ans1, ans2, range;

int find(int f)
{
    return parent[f] == f ? f : parent[f] = find(parent[f]);
}

void Kruskal()
{
    int j = 0;
    for (auto& [left, right, w] : edges)
    {
        int a = find(left), b = find(right);

        if (a != b)
        {
            if (Rank[a] < Rank[b]) parent[a] = b;
            else if (Rank[a] > Rank[b]) parent[b] = a;
            else parent[a] = b, Rank[b]++;

            if (w < range) ans1 += w, --s;
            else ans2 += w;

            if (++j == n - 1) return;
        }
    }
}

int main()
{
    int T, Case = 0;
    cin >> T;
    while (T--)
    {
        double x, y, z;
        cin >> n >> range;
        node.assign(n + 1, pair<double, double>());
        edges.clear();
        parent.assign(n + 1, 0);
        Rank.assign(n + 1, 0);

        for (int i = 1; i <= n; ++i)
        {
            //cin.ignore();
            cin >> node[i].first >> node[i].second;
            parent[i] = i;
        }

        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
            {
                x = node[i].first - node[j].first, y = node[i].second - node[j].second;
                z = sqrt(x * x + y * y);
                edges.push_back({ i,j,z });
            }

        sort(edges.begin(), edges.end());

        s = n;
        ans1 = ans2 = 0;

        Kruskal();

        pair<int, int> ans(ans1 + 0.5, ans2 + 0.5);
        //printf("Case #%d: %d %.0lf %.0lf\n", ++Case, s, ans1, ans2);
        cout << "Case #" << ++Case << ": " << s << " " << ans.first << " " << ans.second << "\n";
    }

    return 0;
}*/

/*
3
3 100
0 0
1 0
2 0
3 1
0 0
100 0
200 0
4 20
0 0
40 30
30 30
10 10
*/