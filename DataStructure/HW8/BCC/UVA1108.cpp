/*
�D�سs��: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3549

�Ѧ�:     https://reurl.cc/3LE9eR

�D��:     �q�u�b�u�@���ɭԬ��F�קK�q�}�Y��ҥH�|�]�m�k�ͳq�D(�]�N�O�w���I), �ЧA��X�ֻ̤ݭn�X�Ӧw���I��]�m�w���I����k��

���D���: ��XBCC(Biconnected Component), BCC�����O�@��component�̭����s�b���I, �Y�@�i�ϸ̦��h��BCC,���|�������N�O���I,
          ��@��BCC�����@���I, ���I�]�����@���I,�i�H��@�i���Y�Block Cutpoint Tree, ������@��, 1 4�O�@��BCC, 1 2 3 5 6
          �]�O�@��BCC, �]�����|��1�N�O���I, �b���D����BCC��@�q��BCC�����C���I���ݦ��@�Ӭ}, ���I�h�������~��, �Y�@��BCC
          �s�����ӥH�W�����I, ���ݭn�]�m�w���I, �]���L�׭����I(�]�A���I)�Y�򳣥i�H�q�䤤�@�ӳ��I�k��t�@��BCC���w���I,
          �Ӧp�G�u���@�ӳ��I, �h�ݭn�bBCC�����N�]�m�@�Ӧw���I, �קK���I�Y��ɭP�u�H�k���X�h, �ӭY�O��i�ϴN�O�@��BCC,
          �h�ݭn�]�m��Ӧw���I, �קK�䤤�@�Ӧw���I�Y��Ӱk���X�h    

Code����: �ε���������ع�, ��tarjan��cutpoint, ���ۦbDFS�̧�X�o��BCC�̦��X���I��s���X��cut point, �p�GBCC�s����
          ��ӥH�W��cut point, �N��䤤�@��cutpoint�Y��]�i�H�z�L��Lcutpoint���LBCC�̪��w���I, �p�GBCC�u���s����
          �@��cut point, �h�ݭn�bBCC�̭��]�m�@�Ӧw���I,�קKcut point�Y��, �ҥH�]�m�w���I���i��ƴN�O�C��BCC���I���ӼƬۭ�, 
          �Ӧp�G�ϨS��cut point�h�ܤֻݭn�]�m��Ӧw���I, ��k�ƬOBCC.size()*(BCC.size()-1)/2,

input:    n�N���X�ӳs�q����,0�N��{������
output:   ��X�ֻ̤ݭn�X�Ӧw���I��]�m�w���I����k��
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
};

map<int, vector<int>> G;
map<int, int> dfn, low;
int Time, comS;
unordered_set<int> visited, iscut, comcut;

inline void init(int n)
{
    G.clear();
    dfn.clear();
    low.clear();
    Time = 0;
    visited.clear();
    iscut.clear();
}

void DFS(int u, int parent)
{
    int child = 0;
    low[u] = dfn[u] = ++Time;

    for (auto& v : G[u])
    {
        if (dfn[v]) 
        {
            if (parent != v) low[u] = min(low[u], dfn[v]);
            continue;
        }

        ++child;
        DFS(v, u);
        low[u] = min(low[u], low[v]);

        if (low[v] >= dfn[u] && (child >= 2 || parent != -1)) iscut.insert(u);
    }
}

void findbcc(int u)
{
    visited.insert(u);
    ++comS;

    for (auto& v : G[u])
    {
        if (visited.count(v) || iscut.count(v))
        {
            if (iscut.count(v)) comcut.insert(v);
            continue;
        }
        findbcc(v);
    }
}

int main()
{
    int n, Case = 0;
    while (cin >> n && n)
    {
        init(n);
        int x, y;

        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for (auto&[i,_]:G)
        {
            if (!dfn[i]) DFS(i, -1);
        }

        vector<int> D;
        for (auto& [i, _] : G)
        {
            comcut.clear();
            comS = 0;
            if (!visited.count(i)&&!iscut.count(i)) findbcc(i);

            if (comcut.size() == 1) D.push_back(comS);
        }

        long long ways = 1, mn = D.size();

        for (auto& i : D)ways *= i;

        if (D.size() == 0) mn = 2, ways = (G.size() * (G.size() - 1)) / 2;

        cout << "Case " << ++Case << ": " << mn << " " << ways << "\n";
    }

    return 0;
}








/*void DFS(int n, int parent)
{
    int child = 0;
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

        if (low[i] >= dfn[n] && (child >= 2 || parent != -1)) iscut.insert(n);
    }
}

void findBCC(int u)
{
    visited.insert(u);
    ++comS;

    for (auto& v : G[u])
    {
        if (visited.count(v) || iscut.count(v))
        {
            if (iscut.count(v)) comcut.insert(v);
            continue;
        }

        findBCC(v);
    }

}

int main()
{
    int n, Case = 0;

    while (cin >> n && n)
    {
        init(n);
        int x, y;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for (auto& [i, _] : G) if (!dfn.count(i)) DFS(i, -1);

        vector<int> D;
        for (auto& [i, _] : G)
        {
            if (visited.count(i) || iscut.count(i)) continue;

            comS = 0;
            comcut.clear();
            findBCC(i);

            if (comcut.size() == 1) D.push_back(comS);
        }

        long long ways = 1, mn = D.size();

        for (auto& i : D) ways *= i;

        if (D.empty()) mn = 2, ways = (long long)G.size() * (long long)(G.size() - 1) / 2;

        cout << "Case " << ++Case << ": " << mn << " " << ways << "\n";
    }

    return 0;
}*/

/*
9
1 3
4 1
3 5
1 2
2 6
1 5
6 3
1 6
3 2
6
1 2
1 3
2 4
2 5
3 6
3 7
0

Case 1: 2 4
Case 2: 4 1
*/

/*#include<iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
#define MAXN 65536

vector<int> g[MAXN];
int visited[MAXN], time, back[MAXN], depth[MAXN];
int cutPoint[MAXN];

void tarjan(int u, int p, int root) {
    back[u] = depth[u] = ++time;
    visited[u] = 1;
    int child = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        if (!visited[v]) {
            tarjan(v, u, root);
            back[u] = min(back[u], back[v]);
            child++;
            if ((u == root && child > 1) || (u != root && back[v] >= depth[u]))
                cutPoint[u]++;
        }
        else if (v != p) {
            back[u] = min(back[u], depth[v]);
        }
    }
}

set<int> adjCutPt;
int comSize = 0;
void dfs(int u) {
    visited[u] = 1, comSize++; //��Xcomponent�����X���I
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i]; 
        if (cutPoint[v]) 	adjCutPt.insert(v);
        if (cutPoint[v] || visited[v])
            continue;
        dfs(v);
    }
}
int main(){
    int n, m, x, y;
    int cases = 0;
    while (cin >> m&& m) {
        int used[MAXN] = {}, usedn = 0; //usedn�O�I���Ӽ�
        fill(g, g + MAXN, vector<int>());
        n = 0;

        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            n = max(n, max(x, y));
            used[--x] = used[--y] = 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        for (auto& i : used) usedn += i; //���X��node
        time = 0;
        fill(visited, visited + MAXN, 0);
        fill(cutPoint, cutPoint + MAXN, 0);

        for (int i = 0; i < n; i++) {
            if (!visited[i] && used[i])
                tarjan(i, -1, i);
        }

        vector<int> D;
        fill(visited, visited + MAXN, 0);

        for (int i = 0; i < n; i++)
            if (!visited[i] && !cutPoint[i]) {
                comSize = 0, adjCutPt.clear();
                dfs(i);
                if (adjCutPt.size() == 1) //�p�Gcomponent�u���s���@��cut point�~�ݭn�p��
                    D.push_back(comSize);
            }

        long long ways = 1, mn = D.size();
        for (int i = 0; i < D.size(); i++)
            ways *= D[i];
        if (D.size() == 0)	ways = (long long) usedn * (usedn - 1) / 2, mn = 2;
        cout << "Case " << ++cases << ": " << mn << " " << ways << endl;
    }
    return 0;
}*/
